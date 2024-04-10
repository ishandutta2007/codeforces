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
    struct node {
        ll mx=-1e18,lazy=0;
        bool bad = false;
        node() {}
    };
    vector<node> seg;
    int n,ptwo;
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
    }
    void puttag(int i, ll val) {
        auto& v = seg[i];
        v.mx+=val;
        v.lazy+=val;
    }

    void pull(int i) {
        auto& v = seg[i];
        v.mx = max(seg[i*2].mx,seg[i*2+1].mx);
    }
    void push(int i) { // TODO!
        puttag(i*2,seg[i].lazy);
        puttag(i*2+1,seg[i].lazy);
        seg[i].lazy=0;
    }
    ll get(int i, int l, int r, int ql, int qr) {
        if(qr<l or r<ql) return 0;
        if(ql<=l and r<=qr) {
            return seg[i].mx;
        }
        int mid = (l+r)/2;
        push(i);
        auto sum = max(get(i*2,l,mid,ql,qr),get(i*2+1,mid+1,r,ql,qr)); // TODO
        pull(i);
        return sum;
    }
    void set(int i, int l, int r, int ql, int qr, ll v) {
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr) {
            puttag(i,v); // correct?
            return;
        }
        int mid = (l+r)/2;
        push(i);
        set(i*2,l,mid,ql,qr,v),set(i*2+1,mid+1,r,ql,qr,v);
        pull(i);
    }
    node& operator[](int i) {return seg[i+ptwo];}
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            pull(i);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,p; cin >> n >> m >> p;
    auto get = [](int n) {
        vector<pi> a(n);
        for(auto& [p,c] : a) cin >> p >> c;
        sort(all(a));
        // vector<pi> res;
        // for(auto& [p,c] : a) {
        //     if(res.empty()) res.push_back({p,c});
        //     else if(res.back().second<c and res.back().first<p) {
        //         res.push_back({p,c});
        //     }
        // }
        return a;
    };
    auto a = get(n), b= get(m);
    vector<array<int,3>> monsters(p);
    for(auto& [x,y,z] : monsters) 
        cin >> x >> y >> z;
    sort(all(monsters));
    ll ans = -1e18;
    n = a.size(),m = b.size();
    segtree seg(m+1);
    for(int i=0;i<m;++i) {
        seg[i].mx = -b[i].second;
    }
    seg.build();
    for(int i=0,j=0;i<n;++i) {
        auto [pp,c] = a[i];
        while(j < p and monsters[j][0]<pp) {
            int id = upper_bound(all(b), pi{monsters[j][1],oo})-b.begin();
            seg.set(1,0,seg.ptwo-1, id,m, monsters[j][2]);
            ++j;
        }
        ans = max(ans, seg.seg[1].mx - c);
    }
    cout << ans << '\n';


}