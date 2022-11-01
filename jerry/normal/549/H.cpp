#include <bits/stdc++.h>
using namespace std;

#define EPS 1.e-10

long double A[2][2];

bool foo(long double val, int r, int c, long double test)
{
	long double lo = 1.e+20, hi = -1.e+20;
	for (int i = -1;i <= 1;i+=2) for (int j = -1;j <= 1;j+=2)
	{
		long double tmp = (A[r^1][c]+i*test)*(A[r][c^1]+j*test);
		if (tmp < lo) lo = tmp;
		if (tmp > hi) hi = tmp;
	}
	if (fabs(val) < EPS)
		return (lo < EPS && hi > -EPS);
	lo /= val, hi /= val;
	if (lo > hi)
	{
		long double tmp = lo;
		lo = hi;
		hi = tmp;
	}
	long double rlo = A[r^1][c^1]-test, rhi = A[r^1][c^1]+test;
	if (rlo-EPS > hi) return false;
	if (rhi+EPS < lo) return false;
	return true;
}

int main()
{
	cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];
	long double lo = 0.0, hi = 1.e+12;
	while (hi-lo > EPS || hi-lo > lo*EPS)
	{
		long double mid = (lo + hi) / 2.;
		bool ok = false;
		for (int i = 0;i < 2;i++) for (int j = 0;j < 2;j++)
		{
			if (foo(A[i][j]+mid, i, j, mid) || foo(A[i][j]-mid, i, j, mid))
			{
				ok = true;
				break;
			}
		}
		if (ok)
			hi = mid;
		else
			lo = mid;
	}
	printf("%.10lf\n", (double)lo);
	return 0;
}