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
        int cnt=1, mn=0, lazy=0;
        node() {}
    };
    vector<node> seg;
    int n,ptwo;
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
    }
    inline void puttag(int i, int val) {
        auto& v = seg[i];
        v.mn+=val,v.lazy+=val;
    }
    void pull(int i) {
        auto& v = seg[i];
        v.mn = min(seg[i*2].mn,seg[i*2+1].mn);
        v.cnt = 0;
        if(seg[i*2].mn==v.mn) v.cnt = seg[i*2].cnt;
        if(seg[i*2+1].mn==v.mn) v.cnt+=seg[i*2+1].cnt;
    }
    void push(int i) { // TODO!
        if(seg[i].lazy!=0) {
            puttag(i*2,seg[i].lazy);
            puttag(i*2+1,seg[i].lazy);
            seg[i].lazy=0;
        }
    }
    int ql, qr,v;
    void set(int i, int l, int r) {
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr) {
            puttag(i,v); // correct?
            return;
        }
        int mid = (l+r)/2;
        push(i);
        set(i*2,l,mid),set(i*2+1,mid+1,r);
        pull(i);
        return;
    }
    void Set(int l, int r, int _v) {
        ql = l,qr = r,v=_v;
        set(1,0,ptwo-1);
    }
    ll get() {
        return ptwo-seg[1].cnt;
    }
    node& operator[](int i) {return seg[i+ptwo];}
    void build() {
        for(int i=ptwo-1;i>=1;--i) pull(i);
    }
};
struct event {
    int x,y1,y2;
    short sgn;
    bool operator<(const event& o) const {return x<o.x;}
};
int n;
ll area(const vector<event>& es) {
    segtree seg(n+1);
    seg.build();
    ll lastx = 0, ans=0;
    for(auto& e : es) {
        ans+=(e.x-lastx)*seg.get();
        seg.Set(e.y1,e.y2,e.sgn);
        lastx=e.x;
    }
    return ans;
}

template<typename T> vi smaller(T a, const bool equal=false) {
    vi res(n,-1);
    for(int i=0;i<n;++i) {
        res[i]=i-1;
        while(res[i]!=-1 and (equal?a[i]>=a[res[i]]:a[i]>a[res[i]])) {
            res[i] = res[res[i]];
        }
    }
    return res;
}
void getEvents(const vector<ll>& a, const vi& b, vector<event>& es) {
    auto l = smaller(a.begin());
    auto r = smaller(a.rbegin(),true);
    reverse(all(r));
    for(auto& i : r) i = n-1-i;
    for(int i=0;i<n;++i) {
        es.push_back({l[i]+b[i],i,r[i]-1,1});
        es.push_back({i+b[i],i,r[i]-1,-1});
    }
}
const int SHIFT = 1e7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<ll> a(n); for(auto& i : a) cin >> i;
    vi b(n);
    transform( all(a), b.begin(), [&](ll u) {return bitset<64>(u).count()*SHIFT;}); 
    vector<event> es;
    es.reserve(4*n);
    getEvents(a,b,es);
    for(auto& i : a) i=-i;
    getEvents(a,b,es);
    ll ans = ll(n)*(n+1);
    sort(all(es));
    ans-=area(es);
    cout << ans << '\n';
}