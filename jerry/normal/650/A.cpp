#include <bits/stdc++.h>

using namespace std;

map<int, long long> x, y;
map<pair<int, int>, long long> z;

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		x[a]++;
		y[b]++;
		z[make_pair(a, b)]++;
	}
	long long ans = 0;
	for (auto u: x) ans += (u.second)*(u.second-1)>>1;
	for (auto u: y) ans += (u.second)*(u.second-1)>>1;
	for (auto u: z) ans -= (u.second)*(u.second-1)>>1;
	cout << ans << endl;
	return 0;
}