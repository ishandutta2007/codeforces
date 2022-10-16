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
		vector<pair<int, int>>sp;
		for (i = 0; i < N; i++)
		{
			int ans = 0;
			int j;
			for (j = 0; j < M; j++)
			{
				int a;
				cin >> a;
				ans += a * j;
			}
			sp.push_back({ ans,i + 1 });
		}
		sort(sp.begin(), sp.end());
		cout << sp.back().second << ' ' << sp.back().first - sp[0].first << '\n';
	}
}