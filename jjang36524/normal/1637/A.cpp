#include <bits/stdc++.h>
using namespace std;
int cnt[10010];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		int ma = 0;
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (a < ma)
			{
				ans = 1;
			}
			ma = a;
		}
		if (ans)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}