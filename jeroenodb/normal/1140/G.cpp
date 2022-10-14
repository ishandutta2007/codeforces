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
const int mxN = 1e5+1;
const ll oo = 1e18;
struct edge {
    ll w[2] = {};
    int u,v;
    int to(int at) {return at^u^v;}
};
struct node {
    array<array<ll,2>,2> d = {0,oo,oo,0};
    node() {}
    node(ll paritycross) {
        d[0][1]=d[1][0]=paritycross;
    }
    node(const edge& e) {
        d[0][0] = e.w[0],d[1][1]=e.w[1];
    }
    void merge(const node& o) {
        array<array<ll,2>,2> res = {oo,oo,oo,oo};

        for(int i : {0,1}) for(int j : {0,1}) for(int k : {0,1}) {
            res[i][k] = min(res[i][k],d[i][j]+o.d[j][k]);
        }
        d=res;
    }
};
node merge(node a, const node& b) {
    a.merge(b);
    return a;
}

vector<ll> a;
vector<edge> es;
vvi adj;

struct binlift {
    vi d,jmp,par;
    vector<node> wpar,wjmp;
    binlift() {}
    binlift(int n) : d(n),jmp(n),par(n),wpar(n),wjmp(n) {}
    void add(int p,int i, edge& e) {
        par[i]=p;
        wpar[i] = merge(node(a[i]),node(e));
        d[i]=1+d[p];
        if(d[p] - d[jmp[p]] == d[jmp[p]] - d[jmp[jmp[p]]]) {
            wjmp[i] = merge(merge(wpar[i], wjmp[p]), wjmp[jmp[p]]);
            jmp[i] = jmp[jmp[p]];
        } else {
            jmp[i] = p;
            wjmp[i] = wpar[i];
        }
    }
    pair<int,node> jump(int a, int k) { // kth ancestor, max along path from a to ancestor
        node ans;
        int D = max(0,d[a]-k);
        while(d[a]>D) {
            if(d[jmp[a]]>=D) ans=merge(ans,wjmp[a]), a = jmp[a];
            else ans=merge(ans,wpar[a]), a=par[a];
        }
        return {a,ans};
    }
    pair<node,node> query(int a, int b) { // LCA, max along path from a to b
        bool flip=false;
        if(d[a]<d[b]) swap(a,b),flip=true;
        node na,nb;
        tie(a,na) = jump(a,d[a]-d[b]);
        while(a!=b) {
            if(jmp[a]!=jmp[b]) na.merge(wjmp[a]), nb.merge(wjmp[b]), a=jmp[a],b=jmp[b];
            else na.merge(wpar[a]),nb.merge(wpar[b]), a=par[a],b=par[b];
        }
        if(flip) swap(na,nb);
        na.merge(node(::a[a]));
        return {na,nb};
    }
};
binlift bl;
void dfs(int at, int ef) {
    for(auto eto : adj[at]) if(eto!=ef) {
        auto& e = es[eto];
        int to = e.to(at);
        dfs(to,eto);
        a[at] = min(a[at],a[to]+e.w[0]+e.w[1]);
    }
}
void dfs2(int at, int ef) {
    for(auto eto : adj[at]) if(eto!=ef) {
        auto& e = es[eto];
        int to = e.to(at);
        a[to] = min(a[to],a[at]+e.w[0]+e.w[1]);
        bl.add(at,to,e);
        dfs2(to,eto);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    adj.resize(n),a.resize(n);
    for(auto& i : a) cin >> i;
    es.resize(n-1);
    {
    int id=0;
    for(auto& e : es) {
        cin >> e.u >> e.v >> e.w[0] >> e.w[1];
        e.u--,e.v--;
        adj[e.u].push_back(id);
        adj[e.v].push_back(id);
        id++;
    }
    }
    dfs(0,-1);
    bl = binlift(n);
    dfs2(0,-1);
    int q; cin >> q;
    while(q--) {
        int u,v; cin >> u >> v;
        --u,--v;
        int bu=u%2,bv = v%2;
        u/=2,v/=2;
        auto [nu,nv] = bl.query(u,v);
        cout << min(nu.d[bu][0]+nv.d[bv][0],nu.d[bu][1]+nv.d[bv][1]) << '\n';
    }
    


}