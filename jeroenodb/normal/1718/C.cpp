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
    ll mx=0;
    node() {
    }
    void merge(const node& o) {
        mx = max(mx,o.mx);
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
        seg[i].mx+=val;
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
void solve() {
    int n,q; cin >> n >> q;
    vi a(n);
    for(auto& i : a) cin >> i;
    vi ps;
    {int on=n;
    for(int i=2;i<=on;++i) {
        if(on%i==0) {
            ps.push_back(i);
            while(on%i==0) on/=i;
        }
    }
    }
    vector<segtree> segs;
    for(auto p : ps) {
        segs.push_back(segtree(n/p));
        for(int i=0;i<n;++i) {
            segs.back()[i%(n/p)].mx+=a[i];
        }
        segs.back().build();
    }
    int k = ps.size();
    auto getBest = [&]() {
        ll ans=0;
        
        for(int i=0;i<k;++i) {
            ans=max(ans,(n/ps[i])*segs[i].seg[1].mx);
        }
        return ans;
    };
    cout << getBest() << '\n';
    while(q--) {
        int p,x; cin >>  p>> x;
        --p;
        for(int i=0;i<k;++i) {
            segs[i].update(p%(n/ps[i]),x-a[p]);
            
        }
        a[p]=x;
        cout << getBest() << '\n';
    }


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}