#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n;
vvi g;
vvi dp;

int q(int v, int k) {
	return dp[v][min(k, (int)dp[v].size() - 1)];
}

void dfs(int v, int p) {
	int cnt = 0;
	vi all1;
	for(int u : g[v]) {
		if(u == p) {
			continue;
		}
		all1.push_back(u);
		++cnt;
		dfs(u, v);
	}
	for(int i = 0; i <= n; i++) {
		int here = cnt - all1.size();
		vi all2;
		for(int u : all1) {
			int val = q(u, i);
			if(val - i > 1) {
				here += val - i;
				all2.push_back(u);
			} else {
				here += 1;
			}
		}
		all1 = all2;
		dp[v].push_back(here);
		if(here == cnt) {
			break;
		}
	}
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
    cin >> n;
    g.resize(n);
    dp.resize(n);
    for(int i = 0; i < n - 1; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    dfs(0, -1);
    int q1;
    cin >> q1;
    for(int i = 0; i < q1; i++) {
    	int v, k;
    	cin >> v >> k;
    	cout << q(v - 1, k) << '\n';
    }
}