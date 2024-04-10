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
struct node {
    ll res=-oo,maxf=-oo,maxt=-oo;
    node() {}
    void update(ll v) {
        maxf = max(v,maxf);
        res = maxf+maxt;
    }
    node(ll from, ll to) {
        maxf=from,maxt=to;
        res = maxf+maxt;
    }
    void merge(const node& o) {
        res = max({res,o.res,maxf+o.maxt});
        maxf = max(maxf,o.maxf);
        maxt = max(maxt,o.maxt);
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
    void update(int i, ll val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i].update(val);
        
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
    vector<ll> from(n),to(n);
    ll addAtEnd=0;
    { // make into nicer form
        array<vi,3> v = {vi(n),vi(n),vi(n)};
        for(auto& row : v) for(auto& i : row) cin >> i;
        copy(all(v[0]),from.begin());
        copy(all(v[2]),to.begin());
        addAtEnd=accumulate(all(v[1]),0LL);
        for(int i=1;i<n;++i) from[i]-=v[1][i-1];
        for(int i=0;i<n-1;++i) to[i]-=v[1][i+1];
        partial_sum(all(from),from.begin());
        partial_sum(to.rbegin(),to.rend(),to.rbegin());
    }
    // segment tree
    segtree seg(n);
    for(int i=0;i<n;++i) seg[i] = node(from[i],to[i]);
    seg.build();
    vector<vector<pi>> ivs(n);
    while(q--) {
        int l,r,v; cin >> l >> r >> v;
        --l,--r;
        ivs[r].push_back({l,v});
    }
    ll ans=-oo;
    for(int i=0;i<n;++i) {
        for(auto [l,v] : ivs[i]) {
            auto nd = seg.query(l,i);
            auto cost = nd.res-v;
            ans = max(ans,cost);
            if(i<n-1) seg.update(i+1,nd.maxf-v);
        }
    }
    cout << ans+addAtEnd << '\n';
}