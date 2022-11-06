#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int i, a, p[n];
		for (i = 0; i != n; ++i)
			p[i] = 0;
		for (i = 0; i != m; ++i)
		{
			cin >> a;
			++p[a - 1];
		}
		int l = 0, r = 2 * m, mid, ans = r + 1;
		while (l <= r)
		{
			mid = ((l + r) / 2);
			// judge mid
			int tsk = m;
			long long res = 0;
			for (i = 0; i != n; ++i)
			{
				int d=min(p[i],min(mid,tsk));
					tsk -=d;
				res += (mid - d) / 2;
			}
			if (res >= tsk)
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}