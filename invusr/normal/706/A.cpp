#include <bits/stdc++.h>
using namespace std;

typedef double r32;

double x, y, u, v, w, res = 1e100;
int n;

int main()
{
	cin >> x >> y >> n;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lf%lf%lf", &u, &v, &w);
		r32 d = (x - u) * (x - u) + (y - v) * (y - v);
		res = min(res, sqrt(d) / w);
	}

	printf("%.16f", res);

	return 0;
}