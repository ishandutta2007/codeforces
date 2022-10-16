#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int nex[1010];
int cur[1010];
vector<int>link[1010];
int cnt[1010];
int dp[1010];
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
		for (i = 0; i < N; i++)
		{
			cin >> cur[i + 1];
			link[i + 1].clear();
		}
		memset(nex, 0, sizeof(nex));
		memset(cnt, 0, sizeof(cnt));
		for (i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			link[a].push_back(b);
			cnt[b]++;
		}
		for (i = 0; i <=N; i++)
		{
			memset(nex, 0, sizeof(nex));
			int j;
			int p = 0;
			for (j = 1; j <= N; j++)
			{
				nex[j] += cur[j];
				if (cur[j])
				{
					nex[j]--;
					int k;
					for (k = 0; k < link[j].size(); k++)
						nex[link[j][k]]++;
					p = 1;
				}
			}
			for (j = 1; j <= N; j++)
			{
				cur[j] = nex[j];
			}
			if (p == 0)
			{
				cout << i<<'\n';
				break;
			}
		}
		if (i > N)
		{
			memset(dp, 0, sizeof(dp));
			int ans = N;
			queue<int>x;
			for (i = 1; i <= N; i++)
			{
				if (cnt[i] == 0)
				{
					x.push(i);
				}
			}
			int la = 0;
			while (x.size())
			{
				auto t = x.front();
				x.pop();
				dp[t] += cur[t];
				la = dp[t];
				int j;
				for (j = 0; j < link[t].size(); j++)
				{
					dp[link[t][j]] += dp[t];
					dp[link[t][j]] %= MOD;
					cnt[link[t][j]]--;
					if (cnt[link[t][j]] == 0)
					{
						x.push(link[t][j]);
					}
				}
			}
			cout << (la+ans+1)%MOD << '\n';
		}
	}
}