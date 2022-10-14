#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
struct DSU{
    vector<int> sz,parent;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        parent[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int find(int a) {
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};

int par[mxN],d[mxN],jmp[mxN];
void add(int i) {
    int p = par[i];
    d[i]=1+d[p];
    if(d[p] - d[jmp[p]] == d[jmp[p]] - d[jmp[jmp[p]]]) jmp[i] = jmp[jmp[p]];
    else jmp[i] = p;
}
int jump(int a, int k) {
    int D = max(0,d[a]-k);
    while(d[a]>D) {
        if(d[jmp[a]]>=D) a = jmp[a];
        else a = par[a];
    }
    return a;
}
int lca(int a, int b) {
    if(d[a]<d[b]) swap(a,b);
    a = jump(a,d[a]-d[b]);
    while(a!=b) {
        if(jmp[a]!=jmp[b]) a=jmp[a],b=jmp[b];
        else a=par[a],b=par[b];
    }
    return a;
}
vi adj[mxN];
int p1[mxN],p2[mxN];
void dfs(int at) {
    for(int to: adj[at]) if(par[at]!=to) {
        par[to]=at;
        add(to);
        dfs(to);
    }
}
bool ans[mxN];
int cur=0;
void dfs2(int at) {
    if(!p1[at]) ans[at]=1;
    p1[at]+=p2[at];
    for(int to: adj[at]) if(par[at]!=to) {
        p1[to] += p1[at];
        dfs2(to);
    }
}
void solve() {
    int n,m; cin >> n >> m;
    DSU dsu(n);
    vector<pi> bads;
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        if(dsu.unite(u,v)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            bads.push_back({u,v});
        }
    }
    dfs(0);
    for(auto [u,v] : bads) {
        int l = lca(u,v);
        if(v==l) {
            swap(u,v);
        }
        if(u==l) {
            int dif = d[v]-d[u];
            int udown = jump(v,dif-1);
            p1[udown]++;
            p1[v]--;
        } else {
            p1[0]++;
            p1[u]--;
            p1[v]--;
        }
    }
    dfs2(0);
    for(int i=0;i<n;++i) cout << ans[i];
    cout << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}