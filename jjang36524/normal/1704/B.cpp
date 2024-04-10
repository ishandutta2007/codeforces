#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		int i;
		int mi = 1LL << 50;
		int ma = -1LL << 50;
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			ma = min(ma, a + M);
			mi = max(mi, a - M);
			if (mi > ma)
			{
				mi = a - M;
				ma = a + M;
				ans++;
			}
		}
		cout << ans-1 << '\n';
	}
}