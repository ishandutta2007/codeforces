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
    struct mincount {
        int mn[2]={oo,oo}, cnt[2]={};
        friend mincount merge(mincount a, mincount b) {
            mincount res;
            if(b.mn[0]==a.mn[0]) {
                if(a.mn[1]>b.mn[1]) swap(a,b);
                res=a;
                res.cnt[0]+=b.cnt[0];
                if(b.mn[1]==res.mn[1]) res.cnt[1]+=b.cnt[1];
                
            } else {
                if(a.mn[0]>b.mn[0]) swap(a,b);
                res = a;
                if(b.mn[0]==res.mn[1]) {
                    res.cnt[1]+=b.cnt[0];
                } else if(b.mn[0]<res.mn[1]) {
                    res.mn[1]=b.mn[0];
                    res.cnt[1]=b.cnt[1];
                }
            } 
            return res;
        }
    };
struct segtree {
    struct node {
        ll lazy=0;
        ll sm=0,mn[2]={(ll)1e12,(ll)1e12};
        int len=0;
        // alternating sum and minima of alternating sums of odd and even parity
        node() {}
        node(int val) {
            len=1;
            mn[0]=sm=val;
        }
        friend node merge(const node& a, const node& b) {
            node res;
            res.len=a.len+b.len;
            res.sm=b.sm;
            if(a.len%2==0) {
                res.mn[0]=min(a.mn[0],-a.sm+b.mn[0]);
                res.mn[1]=min(a.mn[1],+a.sm+b.mn[1]);
            } else {
                res.mn[0]=min(a.mn[0],+a.sm+b.mn[1]);
                res.mn[1]=min(a.mn[1],-a.sm+b.mn[0]);
            }
            if(b.len%2==0) res.sm+=a.sm;
            else res.sm-=a.sm;
            return res;
        }
    };
    vector<node> seg;
    int n,ptwo;
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
        for(auto& i : seg) {
            i.len=1;
        }
    }
    void updateNode(int i, int lazy) {
        if(lazy==0) return;
        auto& v = seg[i];
        v.lazy+=lazy;
        v.mn[0]+=lazy;
        if(v.len%2) v.sm+=lazy;
    }
    void push(int i) {
        if(!seg[i].lazy) return;
        updateNode(i*2,seg[i].lazy);
        updateNode(i*2+1,seg[i].lazy);
        seg[i].lazy=0;
    }
    void pull(int i) {
        seg[i] = merge(seg[i*2],seg[i*2+1]);
    }
    node get(int i, int l, int r, int ql, int qr) {
        if(ql<=l and r<=qr) return seg[i];
        push(i);
        int mid = (l+r)/2;
        if(qr<=mid) return get(i*2,l,mid,ql,qr);
        if(mid+1<=ql) return get(i*2+1,mid+1,r,ql,qr);
        auto ans = merge(get(i*2,l,mid,ql,qr),get(i*2+1,mid+1,r,ql,qr));
        pull(i);
        return ans;
    }
    void add(int i, int l, int r, int ql, int qr, int v) {
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr) {
            updateNode(i,v);
            return;
        }
        push(i);
        int mid = (l+r)/2;
        add(i*2,l,mid,ql,qr,v),add(i*2+1,mid+1,r,ql,qr,v);
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
    int n; cin >> n;
    segtree seg(n);
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        seg[i]=segtree::node(a-1);
    }
    seg.build();
    int q; cin >> q;
    for(int i=0;i<q;++i) {
        int t,a,b; cin >> t >> a >> b;
        if(t==1) {
            int k; cin >> k;
            if(k==0) continue;
            seg.add(1,0,seg.ptwo-1,a,b,k);
        } else {
            auto ans = seg.get(1,0,seg.ptwo-1,a,b);
            if(ans.sm==0 and ans.mn[0]>=0 and ans.mn[1]>=0) {
                cout << "1\n";
            } else cout << "0\n";
        }
    }
}