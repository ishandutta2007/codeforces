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
const int mxN = 1e5+1, oo = 1e8;
struct Diam {
    int mn=oo,mx=-oo,mxl=-oo,mxr=-oo,diam=0;
    Diam(){}
    Diam(int dep) {
        mn = mx = dep;
        mxl=mxr = -dep;
    }
    void merge(const Diam& o) {
        diam = max({diam,o.diam, mxl+o.mx, mx+o.mxr});
        mxr = max({mxr,o.mxr,-2*mn + o.mx});
        mxl = max({mxl,o.mxl,mx-2*o.mn});
        mx = max(mx,o.mx);
        mn = min(mn,o.mn);
    }
};
template<typename T> T merge(T a, const T& b) {
    a.merge(b);
    return a;
}
struct segtree {
    struct node {
        Diam d[2] = {};
        bool lazy=false;
        void merge(const node& o) {
            d[0].merge(o.d[0]);
            d[1].merge(o.d[1]);
            lazy=false;
        }
        node(bool parity,int dep) {
            d[parity] = dep;
            d[!parity].mn = dep;
        }
        node() {}
    };
    vector<node> seg;
    int n,ptwo;
    segtree(){}
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
    }
    void puttag(int i, bool flip) {
        if(flip) {
            auto& v = seg[i];
            swap(v.d[0],v.d[1]);
            v.lazy^=flip;
        }
    }
    void pull(int i) {
        auto& v = seg[i];
        v = merge(seg[i*2],seg[i*2+1]);
    }
    void push(int i) { // TODO!
        auto& v = seg[i];
        puttag(i*2,v.lazy);
        puttag(i*2+1,v.lazy);
        v.lazy=0;
    }
    void set(int i, int l, int r, int ql, int qr) {
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr) {
            puttag(i,1); // correct?
            return;
        }
        int mid = (l+r)/2;
        push(i);
        set(i*2,l,mid,ql,qr),set(i*2+1,mid+1,r,ql,qr);
        pull(i);
    }
    void set(int l, int r) {
        set(1,0,ptwo-1,l,r);
    }
    int best() {
        return max(seg[1].d[0].diam,seg[1].d[1].diam);
    }
    node& operator[](int i) {return seg[i+ptwo];}
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            pull(i);
        }
    }
};
segtree seg;
struct edge {
    int u,v,l,r;
    bool par;
    int to(int at) {
        return at^u^v;
    }
    
};

namespace DFS {
    vector<edge> es;
    vvi adj;
    int cnt=0;
    bool par=0;
    int d=0;
    void dfs(int at, int pe) {
        seg[cnt++] = segtree::node(par,d);
        for(int ei : adj[at]) if(ei!=pe) {
            auto& e = es[ei];
            e.l = cnt;
            par^=e.par;
            d++;
            dfs(e.to(at),ei);
            e.r = cnt-1;
            par^=e.par;
            d--;
            seg[cnt++] = segtree::node(par,d);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    seg = segtree(2*n-1);
    {
        using namespace DFS;
        es.resize(n-1);
        adj.resize(n);
        for(int i=0;i<n-1;++i) {
            auto& e = es[i];
            cin >> e.u >> e.v >> e.par;
            --e.u,--e.v;
            adj[e.u].push_back(i);
            adj[e.v].push_back(i);
        }
        dfs(0,-1);
    }
    seg.build();
    int q; cin >> q;
    while(q--) {
        int id; cin >> id;
        --id;
        seg.set(DFS::es[id].l,DFS::es[id].r);
        cout << seg.best() << '\n';
    }
}