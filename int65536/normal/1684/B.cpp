#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void solve(int a, int b, int c, int& x, int& y, int& z)
{
	if (c != max(max(a, b), c))
	{
		solve(b, c, a, y, z, x);
	}
	else
	{
		z = c;
		y = c + b;
		x = c + b + a;
	}
	assert(x % y == a);
	assert(y % z == b);
	assert(z % x == c);
}
int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; case_id++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int x, y, z;
		solve(a, b, c, x, y, z);
		printf("%d %d %d\n", x, y, z);
	}
	return 0;
}