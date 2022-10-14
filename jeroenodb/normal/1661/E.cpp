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
    array<char,12> sz,parent,rnk;
    bool got[12];
    DSU() {}
    DSU(int n) {
        fill(all(sz),1);
        iota(all(parent),0);
        fill(all(got),0);
        fill(all(rnk),0);
    }
    void link(int a, int b) {
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
DSU dsu;
struct node {
    int ans=0;
    array<char,3> cc[2] = {};
    array<bool,3> b[2] = {};
    node() {
        *this = node({0,0,0});
    }
    node(array<bool,3> bb) {
        b[0]=b[1] = bb;
        int rnk=0;
        for(int i=0;i<3;++i) {
            if(bb[i] and (i==0 or !bb[i-1])) {
                rnk++;
            }
            cc[0][i]=cc[1][i] = rnk;
        }
    }
    void merge(const node& o) {
        
        ans+=o.ans;
        for(int i=0;i<2;++i) for(int j=0;j<3;++j) {
            cc[i][j]+=6;
        }
        dsu = DSU(12);
        for(int i=0;i<3;++i) {
            if(b[1][i] and o.b[0][i]) {
                dsu.unite(cc[1][i],o.cc[0][i]);
            }
        }
        
        int r=0;
        array<char,3> nwc = {};
        for(int i=0;i<3;++i) {
            
            if(b[0][i]) {
                auto rt = dsu.find(cc[0][i]);
                if(!dsu.got[rt]) {
                    dsu.got[rt]=true;
                    dsu.rnk[rt]=r++;
                }
                cc[0][i] = dsu.rnk[rt];
            }
            if(o.b[1][i]) {
                auto rt = dsu.find(o.cc[1][i]);
                if(!dsu.got[rt]) {
                    dsu.got[rt]=true;
                    dsu.rnk[rt]=r++;
                }
                nwc[i] = dsu.rnk[rt];
            }
        }
        for(int i=0;i<3;++i) {
            if(b[1][i]) {
                auto rt = dsu.find(cc[1][i]);
                if(!dsu.got[rt]) {
                    dsu.got[rt]=true;
                    ans++;
                }
            }
            if(o.b[0][i]) {
                auto rt = dsu.find(o.cc[0][i]);
                if(!dsu.got[rt]) {
                    dsu.got[rt]=true;
                    ans++;
                }
            }
        }
        b[1] = o.b[1];
        cc[1]=nwc;

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
        ptwo=nn;
        seg.resize(ptwo*2);
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        node resl, resr;
        while(l and l<=r) {
            if(l%2==1) resl = merge(resl,seg[l++]);
            if(r%2==0) resr = merge(seg[r--],resr);
            l/=2; r/=2;
        }
        return merge(resl,resr);
    }
    // void update(int i, int val) {
    //     assert(i>=0 and i<ptwo);
    //     i+=ptwo;
    //     seg[i] = node(val);
    //     for(i/=2;i>=1;i/=2) {
    //         seg[i] = merge(seg[2*i],seg[2*i+1]);
    //     }
    // }
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s[3] = {};
    for(auto& i : s) cin >> i;
    segtree seg(n);
    for(int i=0;i<n;++i) {
        seg[i] = node(array<bool,3>{s[0][i]=='1', s[1][i]=='1',s[2][i]=='1'});
    }
    seg.build();
    int q; cin >> q;
    while(q--) {
        int l,r; cin >> l >> r,--l,--r;
        auto nd = seg.query(l,r);
        int res=0;
        for(int i=0;i<2;++i) for(int j=0;j<3;++j) {
            if(nd.b[i][j]) res=max(res,nd.cc[i][j]+1);
        }
        cout << res+nd.ans << '\n';
    }
}