#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m;
vector<vector<pair<int, int>>> g;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++) {
    	int v, u, t;
    	cin >> v >> u >> t;
    	--v;
    	--u;
    	if(v == u) continue;
    	g[u].push_back({v, t});
    }
    vi dst(n, INF);
    vi c(n, 2);
    dst[n - 1] = 0;
    queue<int> q;
    q.push(n - 1);
    while(!q.empty()) {
    	int v = q.front();
    	q.pop();
    	for(auto& u1 : g[v]) {
    		int u = u1.first;
    		int t = u1.second;
    		if(dst[u] != INF) {
    			continue;
    		}
    		if(c[u] == 2) {
    			c[u] = 1 - t;
    			continue;
    		}
    		if(c[u] == t) {
    			q.push(u);
    			dst[u] = dst[v] + 1;
    		}
    	}
    }
    if(dst[0] == INF) {
    	cout << -1 << '\n';
    } else {
    	cout << dst[0] << '\n';
    }
    for(int i = 0; i < n; i++) {
    	if(c[i] == 1) {
    		cout << 1;
    	} else {
    		cout << 0;
    	}
    }
}