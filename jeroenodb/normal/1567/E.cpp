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
struct node {
    int len,lv,rv,pref,suf;
    ll ans=1;
    node() {
        *this = node(0);
        len=0;
    }
    node(int val) {
        pref=suf=len=1,lv=rv=val;
    }
    void merge(const node& o) {
        if(len==0) {
            *this = o;
            return;
        } else if(o.len==0) return;
        ans+=o.ans;
        if(rv<=o.lv) {
            ans+=(ll)suf*o.pref;
            if(o.suf==o.len) suf+=o.len;
            else suf=o.suf;
            if(pref==len) pref+=o.pref;
        } else {
            suf=o.suf;
        }
        rv = o.rv;
        len+=o.len;
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
        seg.assign(ptwo*2,0);
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
    int n,q; cin >> n >> q;
    segtree seg(n);
    for(int i=0;i<n;++i) {
        int a;cin >> a;
        seg[i] = node(a);
    }
    seg.build();
    while(q--) {
        int t,l,r; cin >> t >> l >> r;
        if(t==1) {
            seg.update(l-1,r);
        } else {
            cout << seg.query(l-1,r-1).ans << '\n';
        }

    }
}