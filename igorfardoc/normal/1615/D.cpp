#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<vector<pair<int, int>>> g;
vector<vector<pair<int, int>>> g1;
vi xor1;
vector<bool> used;
bool ok;
vi val;
vi par;

void dfs(int v) {
	used[v] = true;
	for(auto& u1 : g1[v]) {
		int u = u1.first;
		int w = u1.second;
		if(used[u]) {
			if((w == 1 && val[v] == val[u]) || (w == 0 && val[v] != val[u])) {
				ok = false;
				return;
			}
			continue;
		}
		if(w == 1) {
			val[u] = 1 - val[v];
		} else {
			val[u] = val[v];
		}
		dfs(u);
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
    int t;
    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;
    	g.assign(n, vector<pair<int, int>>(0));
    	vector<array<int, 3>> e(n - 1);
    	vector<array<int, 3>> rules;
    	for(int i = 0; i < n - 1; i++) {
    		int v, u, w;
    		cin >> v >> u >> w;
    		--v;
    		--u;
    		g[v].push_back({u, w});
    		g[u].push_back({v, w});
    		e[i] = {v, u, w};
    		if(w != -1) {
    			rules.push_back({v, u, __builtin_popcount(w) % 2});
    		}
    	}

    	for(int i = 0; i < m; i++) {
    		int v, u, w;
    		cin >> v >> u >> w;
    		--v;
    		--u;
    		rules.push_back({v, u, w});
    	}
    	g1.assign(n, vector<pair<int, int>>(0));
    	for(const auto& el : rules) {
    		//cout << el[0] << ' ' << el[1] << ' ' << el[2] << endl;
    		g1[el[0]].push_back({el[1], el[2]});
    		g1[el[1]].push_back({el[0], el[2]});
    	}
    	used.assign(n, false);
    	ok = true;
    	val.assign(n, 0);
    	for(int i = 0; i < n; i++) {
    		if(!used[i]) {
    			dfs(i);
    		}
    	}
    	if(!ok) {
    		cout << "NO\n";
    		continue;
    	}
    	cout << "YES\n";
    	for(int i = 0; i < n - 1; i++) {
    		if(e[i][2] != -1) {
    			cout << e[i][0] + 1 << ' ' << e[i][1] + 1 << ' ' << e[i][2] << '\n';
    			continue;
    		}
    		int here = val[e[i][0]] ^ val[e[i][1]];
    		cout << e[i][0] + 1 << ' ' << e[i][1] + 1 << ' ' << here << '\n';
    	}
    }
}