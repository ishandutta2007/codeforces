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
struct segtree {
    int n, ptwo;
    struct Node {
        // Change here the values you want to propagate, and store
        ll prop=-1, sm = 0;
        int l=-99,r=-99;
        Node () {}
        Node(int val, int i) {
            sm = val;
            l = r = i;
        }
        ll sum() {
            if(prop==-1) return sm;
            int sz = r-l+1;
            return (ll)sz*prop;
        }
    };
    vector<Node> d;

    void pull(int i) {
        // Recalculates all values stored in node from children
        assert(d[i].prop==-1);
        Node& lc = d[2*i], &rc = d[2*i+1];
        d[i].sm = lc.sum() + rc.sum();
    }
    void push(int i) {
        // Pushes the propagation values down to the children
        Node& lc = d[2*i], &rc = d[2*i+1];
        if(d[i].prop==-1)
            return;
        lc.prop=d[i].prop;
        rc.prop=d[i].prop;
        d[i].prop=-1;
    }
    segtree(int _n) {
        n = _n;
        ptwo= 1;
        while(ptwo<n) ptwo*=2;
        d.resize(2*ptwo);
        for(int i=ptwo; i<2*ptwo;++i) {
            d[i].l = d[i].r = i-ptwo;
        }
    }
    ll query(int l, int r, int i=1) {
        Node& c = d[i];
        if(c.l < l or r < c.r ) {
            ll res = 0;
            push(i);
            int mid = (c.r+c.l)/2;
            if(l<=mid) {
                res=query(l,min(mid,r),i*2);
            }
            if(r>mid) {
                res+=query(max(mid+1,l),r,i*2+1);
            }
            pull(i);
            return res;
        } else {
            return c.sum();
        }
    }
    void update(int l, int r, ll a, int i=1) {
        Node& c = d[i];
        if(c.l < l or r < c.r ) {
            push(i);
            int mid = (c.r+c.l)/2;
            if(l<=mid) {
                update(l,min(mid,r),a,i*2);
            }
            if(r>mid) {
                if(l>=mid+1) {
                    update(l,r,a,i*2+1);
                } else {
                    update(mid+1,r,a,i*2+1);
                }
                
            }
            pull(i);
        } else {
            c.prop=a;
        }
    }
    void build() {
        for(int i=ptwo-1;i>0;--i) {
            pull(i);
            d[i].l = d[i*2].l; d[i].r = d[i*2+1].r;
        }
    }

};
bool solve() {
    int n,q; cin >> n >> q;
    string s; cin >> s;
    string f; cin >> f;
    segtree seg(n);
    for(int i=0;i<n;++i) {
        seg.d[i+seg.ptwo].sm =  f[i]=='1';
    }
    seg.build();
    vector<pi> qs;
    for(int i=0;i<q;++i) {
        int l, r; cin >> l >> r; --l, --r;
        qs.push_back({l,r});
    }
    for(int i=q-1;i>=0;--i) {
        auto [l,r] = qs[i];
        auto sm = seg.query(l,r);
        if(sm*2==r-l+1) {
            return false;
        } else {
            seg.update(l,r,sm*2>r-l+1);
        }
    }
    for(int i=0;i<n;++i) {
        bool on = s[i]=='1';
        if(seg.query(i,i)!=on) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {

        cout << (solve()?"YES\n":"NO\n");
    }
}