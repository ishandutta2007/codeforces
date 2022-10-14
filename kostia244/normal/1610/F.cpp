#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std; 
const int N = 1e6 + 55;
int n, m, vis[N], dir[N];
vector<array<int, 4>> edges;
vector<int> g[N];
void add_edge(int u, int v) {
    g[u].push_back(edges.size());
    g[v].push_back(edges.size());
    edges.push_back({u, v, 0});
}

void tour(int v) {
    int ID = 0;
    vis[v] = 1;
    while(!g[v].empty()) {
        int u = g[v].back();
        if(edges[u][2]++) {
            u = -1;
        } 
        g[v].pop_back();
        if(u == -1) continue;
        
    	dir[u] = edges[u][1] == v;
        //cout << v << " -> " << (edges[u][0]^edges[u][1]^v) << " " << RID[u] << " " << dir[RID[u]] << endl;
        u = edges[u][0]^edges[u][1]^v;
        tour(u);
    }
    //cout << ID << " _ " << edges[ID][0] << " to " << edges[ID][1] << " " << (dir?"A":"B") << endl;
}
void clear() {
	for(auto &i : g) i.clear();
	edges.clear();
	memset(vis, 0, sizeof vis);
}
int deg[N][2];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    int sz = n;
    vector<array<int, 3>> E(m);
    for(auto &[a, b, c] : E) {
    	cin >> a >> b >> c;a--,b--,c--;
    	deg[a][c]++;
    	deg[b][c]++;
    	add_edge(a+c*n, b+c*n);
    }
    for(int i = 0; i < n; i++) {
    	if(deg[i][0]%2==1 && deg[i][1]%2==1)
    		add_edge(i, i+n);
    	else if(deg[i][0]%2)
    		add_edge(2*n, i);
    	else if(deg[i][1]%2)
    		add_edge(2*n, n+i);
    }
    for(int i = 2*n+1; i--;)
    	tour(i);
    int rid = -1;
    vector<int> val(n);
    for(auto [a, b, c] : E) {
    	rid++;
    	if(rid >= m) continue;
    	if(dir[rid])
    		swap(a, b);
    	val[a] += 1+c;
    	val[b] -= 1+c;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
    	cnt += abs(val[i])==1;
    }
    cout << cnt << '\n';
    for(int i = 0; i < m; i++)
    	cout << (1+dir[i]);cout << '\n';
}