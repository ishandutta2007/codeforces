#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
    	int n, k;
    	cin >> n >> k;
    	vector<set<int>> g(n);
    	for(int i = 0; i < n - 1; i++) {
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		g[v].insert(u);
    		g[u].insert(v);
    	}
    	int now = 0;
    	vector<bool> used(n, false);
    	vi cand;
    	for(int i = 0; i < n; i++) {
    		if(g[i].size() <= 1) {
    			cand.push_back(i);
    		}
    	}
    	for(int o = 0; o < k && cand.size() != 0; o++) {
    		vi cand1;
    		for(auto v : cand) {
    			if(used[v]) {
    				continue;
    			}
    			++now;
    			used[v] = true;
    			if(g[v].size() != 0) {
    				int u = *(g[v].begin());
    				g[v].erase(g[v].begin());
    				g[u].erase(g[u].find(v));
    				if(g[u].size() <= 1) {
    					cand1.push_back(u);
    				}
    			}
    		}
    		cand = cand1;
    	}
    	cout << n - now << '\n';
    }
}