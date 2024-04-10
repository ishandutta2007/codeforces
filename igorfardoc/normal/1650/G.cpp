#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int mod = 1000000007;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int s, t;
		cin >> s >> t;
		--s;
		--t;
		vvi g(n);
		for(int i = 0; i < m; i++) {
			int v, u;
			cin >> v >> u;
			--v;
			--u;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		vi dst(n, inf);
		dst[t] = 0;
		{
			queue<int> q;
			q.push(t);
			while(!q.empty()) {
				int v = q.front();
				q.pop();
				for(int u : g[v]) {
					if(dst[u] == inf) {
						dst[u] = dst[v] + 1;
						q.push(u);
					}
				}
			}
		}
		vvi dp(n, vi(2, 0));
		vector<vector<bool>> was(n, vector<bool>(2, false));
		dp[s][0] = 1;
		was[s][0] = true;
		queue<pair<int, int>> q;
		q.push({s, 0});
		while(!q.empty()) {
			auto p = q.front();
			q.pop();
			int v = p.first;
			int m1 = p.second;
			for(int u : g[v]) {
				if(dst[u] == dst[v] - 1) {
					if(!was[u][m1]) {
						was[u][m1] = true;
						q.push({u, m1});
					}
					dp[u][m1] = (dp[u][m1] + dp[v][m1]) % mod;
				}
			}
			if(m1 == 0) {
				for(int u : g[v]) {
					if(dst[u] == dst[v]) {
						if(!was[u][1]) {
							was[u][1] = true;
							q.push({u, 1});
						}
						dp[u][1] = (dp[u][1] + dp[v][m1]) % mod;
					}
				}
			}
		}
		cout << (dp[t][0] + dp[t][1]) % mod << '\n';
	}
}