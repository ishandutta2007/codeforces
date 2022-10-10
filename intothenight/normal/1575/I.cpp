#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mid ((l+r)/2)

int n, q, a[100100], in[100100], head[100100], sz[100100], lev[100100], par[100100], cnt;
ll t[400400];
vector<int> v[100100];

void update(int id, int val, int node = 1, int l = 1, int r = n){
    if(id < l || r < id) return;
    if(l == r){
        t[node] = val;
        return;
    }
    update(id, val, node*2, l, mid), update(id, val, node*2+1, mid+1, r);
    t[node] = t[node*2] + t[node*2+1];
}

ll find(int nl, int nr, int node = 1, int l = 1, int r = n){
    if(r < nl || nr < l) return 0;
    if(nl <= l && r <= nr) return t[node];
    return find(nl, nr, node*2, l, mid) + find(nl, nr, node*2+1, mid+1, r);
}

ll hld(int a, int b){
    ll re = 0;
    while(head[a] != head[b]){
        if(lev[head[a]] < lev[head[b]]) swap(a, b);
        re += find(in[head[a]], in[a]);
        a = par[head[a]];
    }
    if(in[a] > in[b]) swap(a, b);
    return re + find(in[a], in[b]);
}

int dfs_sz(int u, int p){
    par[u] = p, sz[u] = 1, lev[u] = lev[p] + 1;
    for(auto &x : v[u]) if(x != p){
        sz[u] += dfs_sz(x, u);
        if(sz[x] > sz[v[u][0]]) swap(x, v[u][0]);
    }
    return sz[u];
}

void dfs_hld(int u, int p){
    in[u] = ++cnt;
    update(in[u], a[u]);
    for(auto x : v[u]) if(x != p){
        head[x] = (x == v[u][0] ? head[u] : x);
        dfs_hld(x, u);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i], a[i] = abs(a[i]);
    for(int i=1;i<n;i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }

    dfs_sz(1, 0);
    dfs_hld(1, 0);

    while(q--){
        int t, u, v; cin >> t >> u >> v;

        if(t == 1) update(in[u], abs(v));
        else cout << hld(u, v) * 2 - hld(u, u) - hld(v, v) << "\n";
    }
}