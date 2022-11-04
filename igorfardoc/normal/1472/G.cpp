#include<bits/stdc++.h>
#define inf 1000000000
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
    	int n, m;
    	cin >> n >> m;
    	vvi g(n);
    	for(int i = 0; i < m; i++) {
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		g[v].push_back(u);
    	}
    	vi dst(n, inf);
    	vvi ds(n);
    	queue<int> q;
    	dst[0] = 0;
    	q.push(0);
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
    	for(int i = 0; i < n; i++) {
    		ds[dst[i]].push_back(i);
    	}
    	vi ans(n);
    	for(int dst1 = n - 1; dst1 >= 0; dst1--) {
    		for(const auto& v : ds[dst1]) {
    			ans[v] = dst1;
    			for(int u : g[v]) {
    				if(dst[u] > dst[v]) {
    					ans[v] = min(ans[v], ans[u]);
    				} else {
    					ans[v] = min(ans[v], dst[u]);
    				}
    			}
    		}
    	}
    	for(const auto& el : ans) {
    		cout << el << ' ';
    	}
    	cout << '\n';
    }
}