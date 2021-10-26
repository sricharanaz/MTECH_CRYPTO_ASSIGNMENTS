#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/* Euclid's algorithm for GCD */
int gcd(int m, int n)
{
	while (n > 0) {
		int r = m % n;
		m = n;
		n = r;
	}

	return m;
}

double msqrt (float number)
{
	double n = 0.0000001, m;

	for (m = 0; m < number; m += n)
	{
		if ((m * m) > number)
		{
			m -= n;
			break;
		}
	}

	return m;
}

void main(int argc, char* argv)
{
	int niter = 0, seed, x, y, m, n, i, count = 0, z;
	double pi;

	/* 
	 * To deduce the value of pi using the assumption that
	 * probability(gcd(random_x, random_y)) == 1 is (6/pi ^ 2)
	 */

	printf("Enter the number of iterations ");
	scanf("%d",&niter);
	printf("Enter the seed value : ");
	scanf("%d",&seed);

	/* initialize seed */
	srand(seed);

	for (i = 0; i < niter; i++) {
		srand(seed);
		x = rand();
		y = rand();
		z = gcd(x,y);

		if (z == 1)
			count++;
		seed = x;
	}

	pi=(double) msqrt((float) ((6.0 * (double)niter) / (double)count));
	printf("gcd %d x %d y %d count %d\n", z, x, y, count);
	printf("value of pi = %g \n", pi);
}
