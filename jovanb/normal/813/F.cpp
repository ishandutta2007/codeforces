#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

struct DSU{
    int par[N+5];
    int sz[N+5];
    int dif[N+5];
    bool bipartite;
    int n;
    struct operation{
        int a, b, sza, szb;
        bool was;
    };
    stack <operation> st;
    int color(int x){ return (par[x] == x ? 0 : dif[x] ^ color(par[x])); }
    int root(int x){ return (par[x] == x ? x : root(par[x])); }
    void init(int _n){
        n = _n;
        bipartite = 1;
        for(int i=1; i<=n; i++){
            sz[i] = 1;
            par[i] = i;
        }
    }
    void povezi(int _a, int _b){
        int a = root(_a);
        int b = root(_b);
        st.push({a, b, sz[a], sz[b], bipartite});
        if(a == b){
            if(color(_a) == color(_b)) bipartite = 0;
            return;
        }
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        dif[b] = 1 ^ color(_a) ^ color(_b);
    }
    void rollback(){
        operation op = st.top();
        st.pop();
        int a = op.a;
        int b = op.b;
        par[a] = a;
        par[b] = b;
        dif[a] = 0;
        dif[b] = 0;
        sz[a] = op.sza;
        sz[b] = op.szb;
        bipartite = op.was;
    }

} dsu;

map <int, int> last[N+5];

vector <pair <int, int>> seg[4*N+5];

void upd(int node, int l, int r, int tl, int tr, pair <int, int> edg){
    if(tl > r || l > tr) return;
    if(tl <= l && r <= tr){
        seg[node].push_back(edg);
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr, edg);
    upd(node*2+1, mid+1, r, tl, tr, edg);
}

void dfs(int node, int l, int r){
    for(auto c : seg[node]){
        dsu.povezi(c.first, c.second);
    }
    if(l == r){
        if(dsu.bipartite) cout << "YES\n";
        else cout << "NO\n";
        for(auto c : seg[node]) dsu.rollback();
        return;
    }
    int mid = (l+r)/2;
    dfs(node*2, l, mid);
    dfs(node*2+1, mid+1, r);
    for(auto c : seg[node]) dsu.rollback();
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, qrs;
    cin >> n >> qrs;
    dsu.init(n);
    for(int i=1; i<=qrs; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(last[a][b]){
            upd(1, 1, qrs, last[a][b], i-1, {a, b});
            last[a][b] = 0;
        }
        else last[a][b] = i;
    }
    for(int a=1; a<=n; a++){
        for(auto pr : last[a]){
            if(!pr.second) continue;
            int b = pr.first;
            upd(1, 1, qrs, pr.second, qrs, {a, b});
        }
    }
    dfs(1, 1, qrs);
    return 0;
}