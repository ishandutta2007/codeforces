#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, k;
vector<vector<pair<int, int>>> g;
vector<bool> used;
vector<pair<ll, ll>> dp;

void dfs(int v, int p) {
	vector<ll> deltas;
	used[v] = true;
	ll anshere = 0;
	for(auto& u1 : g[v]) {
		int u = u1.first;
		if(u == p) continue;
		int w = u1.second;
		pair<ll, ll> here;
		if(!used[u]) {
			dfs(u, v);
		}
		here.first = dp[u].first + w;
		here.second = dp[u].second;
		anshere += here.second;
		if(here.second < here.first) {
			deltas.push_back(here.first - here.second);
		}
	}
	sort(deltas.begin(), deltas.end());
	reverse(deltas.begin(), deltas.end());
	for(int i = 0; i < deltas.size() && i < k - 1; i++) {
		anshere += deltas[i];
	}
	dp[v].first = anshere;
	if(k - 1 < deltas.size()) {
		anshere += deltas[k - 1];
	}
	dp[v].second = anshere;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
    	cin >> n >> k;
    	g.assign(n, vector<pair<int, int>>(0));
    	for(int i = 0; i < n - 1; i++) {
    		int v, u, w;
    		cin >> v >> u >> w;
    		--v;
    		--u;
    		g[v].push_back({u, w});
    		g[u].push_back({v, w});
    	}
    	used.assign(n, false);
    	ll ans = 0;
    	for(int i = 0; i < n; i++) {
    		if(g[i].size() <= k) {
    			used[i] = true;
    		}
    	}
    	for(int i = 0; i < n; i++) {
    		for(auto& u1 : g[i]) {
    			int u = u1.first;
    			int w = u1.second;
    			if(used[i] && used[u]) {
    				ans += w;
    			}
    		}
    	}
    	ans /= 2;
    	dp.assign(n, {0, 0});
    	for(int i = 0; i < n; i++) {
    		if(!used[i]) {
    			dfs(i, -1);
    			ans += max(dp[i].first, dp[i].second);
    		}
    	}
    	cout << ans << '\n';
    }
}