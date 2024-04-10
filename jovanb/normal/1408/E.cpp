#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

int a[N+5], b[N+5], par[2*N+5], sz[2*N+5];

int root(int x){ return (par[x] == x ? x : par[x] = root(par[x])); }

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int m, n;
    cin >> m >> n;
    for(int i=1; i<=m; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    ll tot = 0;
    vector <tuple <int, int, int>> edges;
    for(int i=1; i<=n+m; i++) par[i] = i, sz[i] = 1;
    for(int i=1; i<=m; i++){
        int x;
        cin >> x;
        while(x--){
            int y;
            cin >> y;
            tot += a[i] + b[y];
            edges.push_back({a[i] + b[y], y + m, i});
        }
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for(auto edge : edges){
        int c, u, v;
        tie(c, u, v) = edge;
        u = root(u);
        v = root(v);
        if(u == v) continue;
        tot -= c;
        if(sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
    cout << tot << "\n";
    return 0;
}