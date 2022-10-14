#include<bits/stdc++.h>
using namespace std;
struct sat {
	int n, sz, c;
	vector<vector<int>> g, gt;
	vector<int> ord, vis, ans;
	sat(int N) : n(2*N), c(1), sz(0), g(n), gt(n), ord(2*n), vis(n), ans(N) {}
	void dfs(int v) {
		vis[v] = c;
		for(int i : g[v]) if(!vis[i]) dfs(i);
		ord[sz++] = v;
	}
	bool check() {
		for(int i = n; i--;) if(!vis[i]) dfs(i);
		swap(g, gt);
		vis.assign(n, 0);
		for(int i = sz; i--;) if(!vis[ord[i]])
			++c, dfs(ord[i]);
		for(int i = 0; i < n; i+=2)
			if(vis[i]^vis[i+1]) ans[i/2] = vis[i] < vis[i+1];
			else c = -1;
		return c+1;
	}
	void add(int u, int v) {
		g[u].push_back(v);
		gt[v].push_back(u);
	}
};
int n, m, a[500], b[500];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
    sat d(m+1);
    for(int i = 1 ; i <= m ; i ++)
        cin >> a[i] >> b[i];
    for(int i = 1 ; i <= m ; i ++)
        if(a[i] > b[i])swap(a[i], b[i]);
    for(int i = 1 ; i <= m ; i ++)
        for(int j = 1 ; j <= m ; j ++){
            if(a[i] >= a[j] and b[i]<= b[j])continue;
            if(a[j] >= a[i] and b[j]<= b[i])continue;
            if(a[j] >= b[i]) continue;
            if(a[i] >= b[j]) continue;
            d.add(i*2 + 1 , j*2);
            d.add(i*2 , j*2 + 1);
        }
    if(!d.check())
        return cout << "Impossible", 0;
    string s = "";
    for(int i = 1 ; i <= m ; i ++)
        s += ((d.ans[i]) ? "o" : "i");
    cout << s;
}