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

struct minq {
    vi q;int p=0;
    void add(int val) {
        while(q.size()-p>0) {
            if(val<q.back()) q.pop_back();
            else break;
        }
        q.push_back(val);
    }
    void pop(int val) {
        if(q[p]==val) p++;
    }
    int min() {
        return q[p];
    }
};
struct segtree {
    struct node {
        ll sm=0,add=0;
        int len=1;
        node() {}
    };
    vector<node> seg;
    int n,ptwo;
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
    }
    void puttag(int i, ll add) {
        auto& v = seg[i];
        v.sm+=v.len*add;
        v.add+=add;
    }
    void pull(int i) {
        auto& v = seg[i];
        v.sm = seg[i*2].sm+seg[i*2+1].sm;
        v.len = seg[i*2].len+seg[i*2+1].len;
    }
    void push(int i) { // TODO!
        auto& v = seg[i];
        puttag(i*2,v.add);
        puttag(i*2+1,v.add);
        v.add=0;
    }
    ll get(int i, int l, int r, int ql, int qr) {
        if(qr<l or r<ql) return 0;
        if(ql<=l and r<=qr) {
            return seg[i].sm;
        }
        int mid = (l+r)/2;
        push(i);
        auto res = get(i*2,l,mid,ql,qr)+get(i*2+1,mid+1,r,ql,qr); // TODO
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
    ll get(int l, int r) {
        return get(1,0,ptwo-1,l,r);
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
    int n,q,k; cin >> n >> q >> k;
    vi a(n); for(auto& i : a) cin >> i;
    vector<vector<pi>> qs(n);
    for(int i=0;i<q;++i) {
        int l,r; cin >> l >> r;
        --l,--r;
        qs[l].push_back({i,r});
    }
    vi b(n+k,-oo);
    {
    minq mq;
    for(int i=0;i<k-1;++i) mq.add(a[i]);
    
    for(int i=k-1;i<n;++i) {
        mq.add(a[i]);
        b[i]=mq.min();
        mq.pop(a[i-k+1]);
    }
    }
    vector<ll> ans(q);
    for(int md=0;md<k;++md) {
        // solve for all things mod md
        int i = md;
        while(i+k<n) i+=k;
        segtree seg((n+k-1)/k);
        vi st = {i+k};
        while(i>=0) {
            while(a[i]<=b[st.back()]) {
                int j = st.back();
                st.pop_back();
                seg.set(j/k, (st.back()-md-1)/k,-b[j]);
            }
            
            seg.set(i/k,(st.back()-md-1)/k,a[i]);
            for(auto [id,r] : qs[i]) {
                ans[id] = seg.get(i/k,(r-md)/k);
            }
            seg.set(i/k,(st.back()-md-1)/k,-a[i]);
            if(i>=k) {
                while(b[i]<=b[st.back()]) {
                    int j = st.back();
                    st.pop_back();
                    seg.set(j/k, (st.back()-md-1)/k,-b[j]);
                }
            }
            seg.set(i/k,(st.back()-md-1)/k,b[i]);
            st.push_back(i);
            i-=k;
        }
    }
    for(auto i : ans) cout << i << '\n';
}