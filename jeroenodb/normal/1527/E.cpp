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
        unsigned mn=0, lazy=0;
        node() {}
        node(int val) {
            mn=val;
        }
    };
    vector<node> seg;
    int n,ptwo;
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
    }
    void putsumtag(int i, int val) {
        auto& v = seg[i];
        v.mn+=val;
        // minset(v.lazy), +=lazysum, +=val
        v.lazy+=val;
    }

    void pull(int i) {
        auto& v = seg[i];
        v.mn = min(seg[i*2].mn,seg[i*2+1].mn);
    }
    void add(int i, int l, int r, int ql, int qr, int val) {
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr) {
            putsumtag(i,val);
            return;
        }
        int mid = (l+r)/2;
        push(i,r-l+1);
        add(i*2,l,mid,ql,qr,val),add(i*2+1,mid+1,r,ql,qr,val);
        pull(i);
    }
    void add(int a, int b, int v) {
        add(1,0,ptwo-1,a,b,v);
    }
    void push(int i, int len) {
        if(seg[i].lazy!=0) {
            putsumtag(i*2,seg[i].lazy);
            putsumtag(i*2+1,seg[i].lazy);
        }
        seg[i].lazy=0;
    }
    ll get(int i, int l, int r, int ql, int qr) {
        if(qr<l or r<ql) return 1.5*oo;
        if(ql<=l and r<=qr) {
            return seg[i].mn;
        }
        int mid = (l+r)/2;
        push(i,r-l+1);
        auto sum = min(get(i*2,l,mid,ql,qr),get(i*2+1,mid+1,r,ql,qr));
        pull(i);
        return sum;
    }
    ll get(int a, int b) {
        return get(1,0,ptwo-1,a,b);
    }

    node& operator[](int i) {return seg[i+ptwo];}
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            pull(i);
        }
    }
};
int main() {
    int n,k; cin >> n >> k;
    vi a(n); for(auto& i : a) cin >> i;
    vi prv(n);
    {
        vi last(n+1,-1);
        for(int i=0;i<n;++i) {
            prv[i]=last[a[i]];
            last[a[i]]=i;
        }
    }

    vi dp(n+1,1.5*oo);
    dp[0]=0;
    while(k--) {
        // do DP with segtree
        segtree seg(n+1);
        vi ndp(n+1,oo);
        for(int i=0;i<n;++i) {
            if(prv[i]!=-1) {
                seg.add(0,prv[i],i-prv[i]);
            }
            seg.add(i,i,dp[i]);
            ndp[i+1] = seg.get(0,i);
        }
        swap(dp,ndp);
    }
    cout << dp[n] << '\n';
}