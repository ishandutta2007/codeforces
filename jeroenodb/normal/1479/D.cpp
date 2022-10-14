#pragma GCC optimize "Ofast"
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int mxN = 3e5+1, oo = 1e9;
bool minerals[mxN]={};
int help[mxN/100]={};
struct LCA {
    int n;
    vi chain, sz, parent,d;
    vector<vector<int>> adj;
    void dfs(int at=0, int path=-1) {
        chain[at] = (path==-1)?at:path;
        if(adj[at].empty()) 
            return;
        int mx=-2,heavy = -1;
        for(auto to: adj[at]) {
            if(sz[to] > mx) {
                mx = sz[to];
                heavy=to;
            } 
        }
        assert(heavy!=-1);
        dfs(heavy,chain[at]);
        for(auto to: adj[at]) {
            if(to!=heavy)
                dfs(to);
        }
    }
    LCA(int nn) {
        n=nn;
        adj.assign(n,{});
        chain.assign(n,-1);
        sz.assign(n,1);
        parent.assign(n,-1);
        d.assign(n,0);
    }

    void init() {
        vector<pi> q; q.reserve(n); q.emplace_back(0,-1);
        // Graph must be a tree
        // Do a bfs on nodes
        for(int i=0;i<(int)q.size();++i) {
            int at,from; tie(at,from) = q[i];
            for(int j=0;j<(int)adj[at].size();++j) {
                auto& to = adj[at][j];
                if(to!=from) {
                    parent[to] = at;
                    d[to] = d[at]+1;
                    q.emplace_back(to,at);
                } else {
                    swap(to,adj[at].back());
                    adj[at].pop_back();
                    j--;
                }
            }
        }
        assert((int)q.size()==n);
        for(int i=n-1;i>=0;--i) {
            int at = q[i].first;
            for(auto to: adj[at]) 
                sz[at]+=sz[to];
        }
        dfs();
        // for(auto& v : cv) reverse(all(v));
    }
    auto lca(int a, int b) {
        while(chain[a]!=chain[b]) {
            if(d[chain[a]]<d[chain[b]]) 
                swap(a,b);
            a = parent[chain[a]];
        }
        if(d[a]<d[b]) return a;
        else return b;
    }
};
int B;
struct query {
    int l,r,p;
    int lo,hi,id;
    bool operator<(const query& o) const {
        if(l/B==o.l/B) {
            return (l/B&1)?(r<o.r):(o.r<r);
        }
        return l/B < o.l/B;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,Q; cin >> n >> Q;
    vi a(n); 
    for(int& i: a) {
        cin >> i;
        --i;
    }
    vvi adj(n);
    LCA lca(n);
    for(int i=0;i<n-1;++i) {
        int c,b; cin >> c >> b;--c,--b;
        lca.adj[c].push_back(b);
        lca.adj[b].push_back(c);
    }
    vi flatten(2*n);
    vi in(n), out(n);
    // Make euler tour
    int cntflat=0;
    function<void(int,int)> dfse = [&](int at, int from) {
        in[at] = cntflat;
        flatten[cntflat++] = at;
        for(int to: lca.adj[at]) {
            if(to==from) continue;
            dfse(to,at);
        }
        out[at] = cntflat;
        flatten[cntflat++] = at;
    };
    dfse(0,-1);
    lca.init();
    vector<query> qs(Q);
    B = max(1.0,sqrt(n));
    for(int i=0;i<Q;++i) {
        int u,v,lo,hi; cin >> u >> v >> lo >> hi; --u,--v,--lo,--hi;
        // cerr << u << ' ' << v << ' ' << lo << ' ' << hi <<'\n';
        if(in[u]> in[v]) swap(u,v);
        int mlca = lca.lca(u,v);
        if(mlca==u) {
            qs[i] = {in[u], in[v],-1  ,lo,hi,i};
        } else {
            qs[i] = {out[u],in[v],mlca,lo,hi,i};
        }
    }
    // eulerin.clear();
    // lca.seg.clear();
    sort(all(qs));
    int l=qs[0].l, r = qs[0].l-1;

    auto toggle = [&](int i) {
        // assert(0<=i and i < n);
        int change = 1-2*minerals[i];
        minerals[i] = !minerals[i];
        help[i/B]+=change;
    }; 
    auto inner = [&](int lo, int hi) {
        for(int i=lo;i<=hi;++i) {
            if(minerals[i]) return i;
        }
        return -1;
    };
    auto get = [&](int lo, int hi) {
        int firstb = (lo+B-1)/B, lastb = (hi+1)/B;
        
        for(int j=firstb; j <lastb;++j) {
            if(help[j]>0) {
                // Found block with an answer
                return inner(j*B, hi);
            }
        }
        auto tmp = inner(lo,min(firstb*B - 1,hi));
        if(tmp!=-1) return tmp;
        return inner(max(lo,lastb*B),hi);
    };
    vi ans(Q,-1);
    for(auto& q: qs) {
        while(r<q.r) {
            toggle(a[flatten[++r]]);
        }
        while(l>q.l) {
            toggle(a[flatten[--l]]);
        }
        while(r>q.r) {
            toggle(a[flatten[r--]]);
        }
        while(l<q.l) {
            toggle(a[flatten[l++]]);
        }
        if(q.p!=-1) 
            toggle(a[q.p]);
        // answer
        int choice = get(q.lo, q.hi);
        if(choice!=-1 or choice > q.hi) {
            ans[q.id] = choice+1;
        }
        if(q.p!=-1) 
            toggle(a[q.p]);
    }
    for(int c: ans) {
        cout << c << '\n';
    }
}