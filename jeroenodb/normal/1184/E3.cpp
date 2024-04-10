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
const int mxN = 1e5+10, oo = 1e9;
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
int d[mxN], jmp[mxN], mx[mxN],par[mxN], wpar[mxN], wjmp[mxN]; // weight of parent edge and max weight of jump
void add(int i) {
    int p = par[i];
    d[i]=1+d[p];
    if(d[p] - d[jmp[p]] == d[jmp[p]] - d[jmp[jmp[p]]]) {
        wjmp[i] = max({wpar[i], wjmp[p], wjmp[jmp[p]]});
        jmp[i] = jmp[jmp[p]];
    } else {
        jmp[i] = p;
        wjmp[i] = wpar[i];
    }
}
void cmax(int& a, int b) {
    a = max(a,b);
}
pi jump(int a, int k) { // kth ancestor, max along path from a to ancestor
    int ans=-oo;
    int D = max(0,d[a]-k);
    while(d[a]>D) {
        if(d[jmp[a]]>=D) cmax(ans,wjmp[a]), a = jmp[a];
        else cmax(ans,wpar[a]), a=par[a];
    }
    return {a,ans};
}
pi lca(int a, int b) { // LCA, max along path from a to b
    if(d[a]<d[b]) swap(a,b);
    int ans;
    tie(a,ans) = jump(a,d[a]-d[b]);
    
    while(a!=b) {
        if(jmp[a]!=jmp[b]) cmax(ans, max(wjmp[a],wjmp[b])), a=jmp[a],b=jmp[b];
        else cmax(ans,max(wpar[a],wpar[b])), a=par[a],b=par[b];
    }
    return {a,ans};
}
vi adj[mxN]; // tree adjacency lists
vi nontree[mxN], lcarem[mxN]; // nontree edges hanging here, LCA removal ops

struct edge{
    int a,b,w,lca=-1, ans;
    int LCA() {
        if(lca==-1) {
            tie(lca,ans) = ::lca(a,b);
        }
        return lca;
    }
    int o(int i) {return a^b^i;}
};
vector<edge> es;
void dfs(int at, int from=0) {
    for(auto ei : adj[at]) {
        auto& e = es[ei];
        auto to = e.o(at);
        if(to==from) continue;
        par[to]=at, wpar[to]=e.w;
        add(to);
        dfs(to,at);
    }
}
multiset<int> s[mxN];
void dfs2(int at, int from=0) {
    for(auto ei : adj[at]) {
        auto& e = es[ei];
        auto to = e.o(at);
        if(to==from) continue;
        dfs2(to,at);
        e.ans = s[to].empty()?oo:*s[to].begin();
        if(s[at].size()<s[to].size()) swap(s[at],s[to]);
        for(auto i : s[to]) s[at].insert(i);
        s[to].clear();
    }
    for(auto ei : nontree[at]) {
        s[at].insert(es[ei].w);
        lcarem[es[ei].LCA()].push_back(es[ei].w);
    }
    for(auto w : lcarem[at]) s[at].erase(s[at].find(w));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    es.resize(m);
    for(auto& e : es) {
        cin >> e.a >> e.b >> e.w;
    }
    // calculate min spanning tree
    vi ord(m); iota(all(ord),0);
    sort(all(ord), [&](int i, int j) {return es[i].w<es[j].w;});
    DSU dsu(n+1);
    for(auto& ei : ord) {
        auto& e = es[ei];
        if(dsu.unite(e.a,e.b)) {
            adj[e.a].push_back(ei);
            adj[e.b].push_back(ei);
        } else nontree[e.a].push_back(ei), nontree[e.b].push_back(ei);
    }
    jmp[1]=1;
    par[1]=1;
    dfs(1);
    dfs2(1);
    for(auto& e : es) {
        cout << e.ans << '\n';
    }
}