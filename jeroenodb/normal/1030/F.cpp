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
typedef __int128_t Int;
struct node {
    Int wa=0;
    ll smw=0;
    node() {
        *this = node(0,0);
    }
    node(int a,int w) {
        smw = w;
        wa = ll(a)*w;
        // wr = ll(a + i)*w;
    }
    void merge(const node& o) {
        smw+=o.smw;
        wa+=o.wa;
        // wr+=o.wr;
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
        seg.assign(ptwo*2,{});
    }
    auto query(int l, int r) {
        if(l>r) return node();
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
    void update(int i, int a,int w) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = node(a,w);
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
    vi a(n); for(auto& i : a) cin >> i;
    for(int i=0;i<n;++i) {
        a[i]-=i;
        int w; cin >> w;
        seg[i] = {a[i],w};
    }
    seg.build();
    while(q--) {
        int x,y; cin >> x >> y;
        if(x<0) {
            x=-x;
            seg.update(x-1,a[x-1],y);
        } else {
            int l=x-1,r=y-1;
            auto f = [&](int i) {
                if(i>r or i<l) return Int(1)<<120;
                Int pos = a[i];
                auto lef = seg.query(l,i), right = seg.query(i+1,r);
                auto costl = lef.smw*pos -lef.wa;
                auto costr = right.wa - right.smw*pos;
                return costl + costr;
            };
            auto total = seg.query(l,r).smw;
            auto half = total/2;
            int lo = l, hi = r;
            while(lo<hi) {
                int mid = (lo+hi+1)/2;
                if(seg.query(l,mid).smw>half) 
                    hi = mid-1;
                else lo = mid;
            }
            const int MOD = 1e9+7;
            int ans = min(f(lo), f(lo+1)) % MOD;
            if(ans<0) ans+=MOD;
            cout << ans << '\n';
        }
    }
}