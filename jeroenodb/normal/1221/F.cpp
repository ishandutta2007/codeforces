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
struct segtree {
    struct node {
        ll mx=-oo,lazy=0;
        int id=-1;
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
        v.mx = max(seg[i*2].mx, seg[i*2+1].mx);
        if(seg[i*2].mx>=seg[i*2+1].mx) v.id=seg[i*2].id;
        else v.id = seg[i*2+1].id;
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
        auto res = max(get(i*2,l,mid,ql,qr),get(i*2+1,mid+1,r,ql,qr)); // TODO
        pull(i);
        return res;
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
    void set(int l, int r, ll v) {
        set(1,0,ptwo-1,l,r,v);
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
    int n; cin >> n;
    vi cs; cs.reserve(n);
    vector<array<int,3>> pts(n);
    for(auto& [x,y,c] : pts) {
        cin >> x >> y >> c;
        if(x>y) swap(x,y);
        cs.push_back(y);
    }
    sort(all(cs));
    cs.erase(unique(all(cs)),cs.end());
    int k = cs.size();
    sort(pts.rbegin(),pts.rend());
    segtree seg(k);
    for(int i=0;i<k;++i) seg[i].id=i;
    seg.build();
    array<ll,3> ans = {0,(ll)2e9,(ll)2e9};
    int prevx=pts[0][0];
    vector<bool> vis(k);
    for(auto [x,y,c] : pts) {
        if(x!=prevx) 
            ans=max(ans,{seg.seg[1].mx+prevx, prevx,cs[seg.seg[1].id]});
        auto id = lower_bound(all(cs),y)-cs.begin();
        seg.set(id,k-1,c);
        seg.set(id,id,(vis[id]?0LL:oo-y));
        vis[id]=true;
        prevx=x;
    }
    ans=max(ans,{seg.seg[1].mx+prevx, prevx,cs[seg.seg[1].id]});
    cout << ans[0] << '\n';
    cout << ans[1] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[2] << '\n';
}