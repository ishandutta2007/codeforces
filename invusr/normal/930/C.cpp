#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100000;
const int INF = 0x3f3f3f3f;

int n, m;
int cover[MaxN + 1];

int f[MaxN + 1], g[MaxN + 1];

int last[MaxN + 1];

inline void solve(int *f, int *a)
{
	last[0] = 0;
	for (int i = 1; i <= m; ++i)
		last[i] = INF;

	for (int i = 1; i <= m; ++i)
	{
		int k = upper_bound(last, last + m, a[i]) - last - 1;
		f[i] = ++k;
		last[k] = min(last[k], a[i]);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		cin >> l >> r;

		++cover[l];
		if (r < m)
			--cover[r + 1];
	}

	for (int i = 2; i <= m; ++i)
		cover[i] += cover[i - 1];

	solve(f, cover);
	reverse(cover + 1, cover + m + 1);
	solve(g, cover);

	int res = 0;
	for (int i = 1; i <= m; ++i)
		res = max(res, f[i] + g[m - i + 1] - 1);

	cout << res << endl;

	return 0;
}