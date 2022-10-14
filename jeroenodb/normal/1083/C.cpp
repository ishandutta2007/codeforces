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
struct LCA {
    vvi adj;
    vi in,out;
    vector<vi> tab;
    int n;
    LCA(){}
    LCA(int n) : adj(n), in(n),out(n),tab(1,vi{}),n(n) {}
    void addE(int u, int v) {
        adj[u].push_back(v);
    }
    int op(int a, int b) {
        if(in[a]<in[b]) return a;
        return b;
    }
    void dfs(int at) {
        in[at] = tab[0].size();
        tab[0].push_back(at);
        for(int to : adj[at]){
            dfs(to);
            tab[0].push_back(at);
        }
        out[at]=tab[0].size()-1;
    }
    void init() {
        dfs(0);
        int m = tab[0].size();
        for(int i=1;1<<i<=m;++i) {
            int len = m - (1<<i);
            tab.push_back(vi(len));
            for(int j=0;j<len;++j) {
                tab[i][j] = op(tab[i-1][j],tab[i-1][j + (1<<(i-1))]);
            }
        }
    }
    bool insub(int a, int b) {
        return in[b]<=in[a] and out[a] <= out[b];
    }
    int lca(int a, int b) {
        a= in[a], b= in[b];
        if(a>b) swap(a,b);
        int g = __lg(b-a+1);
        return op(tab[g][a],tab[g][b- (1<<g) + 1]);
    }
} lca;

struct node {
    int a,b;
    bool bad=true,unity=false;
    node() {}
    node(int val) {
        a=b=val;
        bad=false;
    }
    void setU() {
        unity=true;
        bad=false;
    }
    void merge(const node& o) {
        if(o.bad) {bad=true;}
        if(bad) return;
        if(unity) return void(*this=o);
        if(o.unity) return;
        array<int,4> p = {a,b,o.a,o.b};
        sort(all(p));
        bad=true;
        do {
            if(p[1]>p[2] or p[0]>p[3]) continue;
            int l = lca.lca(p[0],p[3]);
            if(lca.insub(p[1],l) and lca.insub(p[2],l)) {
                int cnt=0;
                for(auto i : {1,2}) {
                    cnt+=lca.insub(p[0],p[i]) or lca.insub(p[3],p[i]);
                }
                if(cnt==2) {
                    a=p[0],b=p[3];
                    bad=false;
                    break;
                }
            }
        } while(next_permutation(all(p)));
    }
    friend node merge(node a, const node& b) {
        a.merge(b);
        return a;
    }
};
struct segtree {
    int ptwo;
    vector<node> seg;
    segtree(){}
    node& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=1;
        while(ptwo<=nn) ptwo*=2;
        seg.assign(ptwo*2,{});
    }
    auto query() {
        node nd;
        nd.setU();
        int at=1;
        while(at<ptwo) {
            
            auto nwnd = merge(nd,seg[at*2]);
            if(nwnd.bad) {
                at*=2;
            } else {
                nd=nwnd;
                at=at*2+1;
            }
        }
        return at-ptwo;
    }
    void update(int i, int val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = node(val);
        for(i/=2;i>=1;i/=2) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi p(n);
    for(auto& i : p) cin >> i;
    segtree seg(n);
    for(int i=0;i<n;++i) {
        seg[p[i]] = node(i);
    }
    lca = LCA(n);
    for(int i=1;i<n;++i) {
        int p; cin >> p;
        lca.addE(p-1,i);
    }
    lca.init();
    seg.build();
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t==1) {
            int i,j; cin >> i >> j;
            --i,--j;
            swap(p[i],p[j]);
            seg.update(p[i],i);
            seg.update(p[j],j);
        } else {
            cout << seg.query() << '\n';
        }
    }

}