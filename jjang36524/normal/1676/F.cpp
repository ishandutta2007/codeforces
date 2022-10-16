#include <bits/stdc++.h>
using namespace std;
#define int long long 
int arr[201][201];
map<int, int>x;
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
		x.clear();
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x[a]++;
		}
		int befx = -1;
		int befy = -1;
		int a, b;
		pair<int, pair<int, int>>ans = { -1LL,{0LL,0LL} };
		int st = 0;
		for (auto j = x.begin(); j != x.end(); j++)
		{
			if (j->second < M)
			{
				befx = -1;
				befy = -1;
			}
			else
			{
				if (befx + 1 == j->first)
				{
					befx = j->first;
					befy++;
				}
				else
				{
					befx = j->first;
					st = befx;
					befy = 0;
				}
				ans = max(ans, { befy,{st,j->first} });
			}
		}
		if (ans.first == -1)
			cout << -1 << '\n';
		else
			cout <<ans.second.first<<' '<<ans.second.second<<'\n';
	}
}