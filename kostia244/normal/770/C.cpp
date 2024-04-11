#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
using namespace std;
int n, m, t, l, vol = 1;
__V<vi> g;
vi vis, col, ttm;
vi k;

void dfs(int v, int p) {
    vis[v] = 1;
    for(auto& i : g[v])
        if(vis[i] == 0) {
            dfs(i, v);
        } else if(vis[i] == 1) {
            cout << -1;
            exit(0);
        }
    vis[v] = 2;
    ttm.pb(v);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    k.resize(m);
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    for(auto& i : k) cin >> i;
    for(int i = 1; i <= n; i++) {
        cin >> t;
        while(t--) cin >> l, g[i].pb(l);
    }
    for(auto& i : k) if(vis[i] == 0)
        ttm.clear(), dfs(i, -1), vol++, col.insert(col.end(), ttm.begin(), ttm.end());
    cout <<col.size() << "\n";
    for(auto& i : col) cout << i << " ";
}