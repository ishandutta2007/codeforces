#include <cstdio>

double a[111];
double p[111];

int main()
{
	double t, s, r, rr;
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &j);
		p[i] = a[i] = (100 - j) / 100.;
	}
	r = rr = 0;
	for (i = 0; i < 200000; i++)
	{
		k = 0;
		s = 1 - p[0];
		for (j = 1; j < n; j++)
		{
			if ((1 - p[j] * a[j]) * (1 - p[k]) > (1 - p[k] * a[k]) * (1 - p[j])) k = j;
			s -= s * p[j];
		}
		p[k] *= a[k];
		rr += 1 - s;
		if (rr > r)
		{
			r += rr;
			rr = 0;
		}
	}
	printf("%.20f", n + r + rr);
}