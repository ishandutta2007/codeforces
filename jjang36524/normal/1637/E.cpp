#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int, int>cnt;
vector<int>v[300100];
vector<int>cnta;
unordered_map<int, int>dp;
struct p
{
	int a, b;
	bool operator<(const p& x) const
	{
		if((a + b) != (x.a + x.b))
			return (a+b) < (x.a + x.b);
		return a < x.a;
	}
};
map<p,int>x;
map<p, int>bp;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cnt.clear();
		cnta.clear();
		x.clear();
		bp.clear();
		int N, M;
		cin >> N >> M;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			cnt[a]++;
			v[i + 1].clear();
		}
		for (auto j = cnt.begin(); j != cnt.end(); j++)
		{
			cnta.push_back(j->second);
			v[j->second].push_back(-(j->first));
		}
		for (i = 1; i <= N; i++)
		{
			sort(v[i].begin(), v[i].end());
			int j;
			for (j = 0; j < v[i].size(); j++)
				v[i][j] *= -1;
		}
		sort(cnta.begin(), cnta.end());
		cnta.erase(unique(cnta.begin(), cnta.end()), cnta.end());
		for (i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			bp[{a, b}] = 1;
		}
		int ans = 0;
		for (i = 0; i < cnta.size(); i++)
		{
			int j;
			for (j = i; j < cnta.size(); j++)
			{
				x.clear();
				dp.clear();
				priority_queue<p>cp;
				if (i != j)
				{
					cp.push({ v[cnta[i]][0],v[cnta[j]][0] });
				}
				else
				{
					if (v[cnta[i]].size() == 1)
						continue;
					cp.push({ v[cnta[i]][1],v[cnta[j]][0] });
				}
				int k;
				for (k = 0; k < v[cnta[i]].size(); k++)
				{
					dp[v[cnta[i]][k]] = k;
				}
				for (k = 0; k < v[cnta[j]].size(); k++)
				{
					dp[v[cnta[j]][k]] = k;
				}
				while (cp.size())
				{
					auto t = cp.top();
					cp.pop();
					if (x[t])
						continue;
					x[t] = 1;
					if (t.a == t.b)
						continue;
					p nt = { t.b,t.a };
					if (!bp[t] && !bp[nt])
					{
						ans = max(ans, (cnta[i] + cnta[j]) * (t.a + t.b));
						break;
					}
					if (dp[t.a] + 1 != v[cnta[i]].size())
					{
						cp.push({ v[cnta[i]][dp[t.a] + 1],t.b });
					}
					if (dp[t.b] + 1 != v[cnta[j]].size())
					{
						cp.push({ t.a ,v[cnta[j]][dp[t.b] + 1] });
					}
				}
			}
		}
		cout << ans << '\n';
	}
}