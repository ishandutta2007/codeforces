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
        int mx=0,cnt=1;
        int lazy=0;
        node() {}
        node(int val) {
            mx=val;
        }
    };
    vector<node> seg;
    int n,ptwo;
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
    }
    void updateNode(int i, int lazy) {
        seg[i].mx+=lazy;
        seg[i].lazy+=lazy;
    }
    void push(int i, int len) {
        updateNode(i*2,seg[i].lazy);
        updateNode(i*2+1,seg[i].lazy);
        seg[i].lazy=0;
    }
    void pull(int i) {
        auto& v = seg[i];
        v.mx = max(seg[i*2].mx,seg[i*2+1].mx);
        v.cnt = 0;
        if(seg[i*2].mx==v.mx) v.cnt+=seg[i*2].cnt;
        if(seg[i*2+1].mx==v.mx) v.cnt+=seg[i*2+1].cnt;
    }
    void add(int i, int l, int r, int ql, int qr, int val) {
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr) {
            updateNode(i,val);
            return;
        }
        push(i,r-l+1);
        int mid = (l+r)/2;
        add(i*2,l,mid,ql,qr,val), add(i*2+1,mid+1,r,ql,qr,val);
        pull(i);
    }
    void add(int l, int r, int v) {
        if(l>r) return;
        add(1,0,ptwo-1,l,r,v);
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
    segtree seg(n+1);
    seg.build();
    seg.add(1,n,n);
    vi prev(n+1);
    vi last(n);
    ll ans=0;
    for(int i=1;i<=n;++i) {
        int a; cin >> a,--a;
        prev[i] = last[a];
        seg.add(prev[i]+1,i,-1);
        int e = prev[prev[i]];
        seg.add(prev[e]+1,e,1);
        seg.add(prev[prev[e]]+1,prev[e],-1);
        if(seg.seg[1].mx==n) 
            ans+=seg.seg[1].cnt-n+i;
        last[a]=i;
    }
    cout << ans << '\n';
}