#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const int mxn = 2e5 + 5;

int n, k;
int fa[mxn];
vector <int> adj[mxn];
int s[mxn];
map <int, i64> dp[mxn];

void dfs(int u)
{
	if (adj[u].empty())
	{
		for (auto &pr : dp[u]) pr.second = 1LL * pr.first * s[u];
		return ;
	}
	set <int> avai;
	for (auto pr : dp[u])
	{
		int x = pr.first;
		int x0 = x / (int)(adj[u].size());
		avai.insert(x0);
		if (x % (int)(adj[u].size()) != 0)
			avai.insert(x0 + 1);
	}
	for (int v : adj[u]) for (int x : avai) dp[v][x];
	for (int v : adj[u]) dfs(v);
	for (auto &pr : dp[u])
	{
		int x = pr.first;
		i64 &res = pr.second;
		vector <i64> vdp_0, vdp_1;
		int x0 = x / (int)(adj[u].size());
		for (int v : adj[u])
		{
			vdp_0.push_back(dp[v][x0]);
			if (x % (int)(adj[u].size()) != 0)
			{
				vdp_1.push_back(dp[v][x0 + 1] - dp[v][x0]);
			}
		}
		int rest = x % (int)(adj[u].size());
		sort(vdp_1.rbegin(), vdp_1.rend());
		res = 1LL * x * s[u];
		for (i64 r : vdp_0) res += r;
		for (int i = 0; i < rest; ++ i) res += vdp_1[i];
	}
}

void Main()
{
	cin >> n >> k;
	for (int i = 2; i <= n; ++ i) cin >> fa[i];
	for (int i = 2; i <= n; ++ i) adj[fa[i]].push_back(i);
	for (int i = 1; i <= n; ++ i) cin >> s[i];
	dp[1][k];
	dfs(1);
	cout << dp[1][k] << endl;
	for (int i = 1; i <= n; ++ i)
	{
		adj[i].clear();
		dp[i].clear();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T --) Main();
	return 0;
}