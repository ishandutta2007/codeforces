#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n;
vector<vector<pair<int, int>>> g;
vi c;

pair<int, int> dfs(int v) {
	pair<int, int> ans = {0, 0};
	if(c[v] == 1) {
		++ans.second;
	} else {
		++ans.first;
	}
	for(auto el : g[v]) {
		int u = el.first;
		int val = el.second;
		if(c[u] == -1) {
			if(val == 1) {
				c[u] = 1 - c[v];
			} else {
				c[u] = c[v];
			}
			auto p = dfs(u);
			if(p.first == -1) {
				return p;
			}
			ans.first += p.first;
			ans.second += p.second;
		} else if((val == 1 && c[u] == c[v]) || (val == 0 && c[u] != c[v])) {
			return {-1, -1};
		}
	}
	return ans;
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
    	cin >> n;
    	int m;
    	cin >> m;
    	g.assign(n, vector<pair<int, int>>(0));
		c.assign(n, -1);
    	for(int i = 0; i < m; i++) {
    		int v, u;
    		string s;
    		cin >> v >> u;
    		cin >> s;
    		--v;
    		--u;
    		int val = 0;
    		if(s[0] == 'i') {
    			val = 1;
    		}
    		g[v].push_back({u, val});
    		g[u].push_back({v, val});
    	}
    	int res = 0;
    	for(int i = 0; i < n; i++) {
    		if(c[i] == -1) {
    			c[i] = 0;
    			auto p = dfs(i);
    			if(p.first == -1) {
    				res = -1;
    				break;
    			}
    			res += max(p.first, p.second);
    		}
    	}
    	cout << res << '\n';
    }
}