#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<int> a, b;
int n, m, r;

int main()
{
	scanf("%d%d", &n, &m);
	for (ll i = 0;i < n;i++)
	{
		int x; scanf("%d", &x);
		a.insert(x);
	}
	for (ll i = 0;i < m;i++)
	{
		int x; scanf("%d", &x);
		b.insert(x);
	}
	for (int u: a)
	{
		auto it = b.lower_bound(u);
		int x = 2147483647;
		if (it != b.end()) x = min(x, *it-u);
		if (it != b.begin()) x = min(x, u-*--it);
		r = max(r, x);
	}
	printf("%d\n", r);
	return 0;
}