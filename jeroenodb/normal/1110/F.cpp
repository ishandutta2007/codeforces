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
        ll mn=ll(oo),lazy=0;
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
    void puttag(int i, ll vv) {
        auto& v = seg[i];
        v.mn+=vv;
        v.lazy+=vv;
    }
    void pull(int i) {
        auto& v = seg[i];
        v.mn = min(seg[i*2].mn,seg[i*2+1].mn);
    }
    void push(int i) { // TODO!
        auto& v = seg[i];
        puttag(i*2,v.lazy);
        puttag(i*2+1,v.lazy);
        v.lazy=0;
    }
    ll get(int i, int l, int r, int ql, int qr) {
        if(qr<l or r<ql) return oo;
        if(ql<=l and r<=qr) {
            return seg[i].mn;
        }
        int mid = (l+r)/2;
        push(i);
        auto res = min(get(i*2,l,mid,ql,qr),get(i*2+1,mid+1,r,ql,qr)); // TODO
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
        if(l>r) return;
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
    int n,Q; cin >> n >> Q;
    struct query {
        int v,l,r;
        int id;
        ll ans=oo;
        int read() {
            cin >> v>> l >> r;
            --v,--l,--r;
            return v;
        }
        bool operator<(const query& o) {
            return id<o.id;
        }
    };
    vector<ll> d(n);
    vector<vector<pi>> adj(n);
    vi p(n,-1);
    for(int i=1;i<n;++i) {
        int w; cin >> p[i] >> w,--p[i];
        adj[p[i]].push_back({i,w});
    }
    for(int i=0;i<n;++i) {
        for(auto [to,w] : adj[i]) {
            d[to]=d[i]+w;
        }
    }
    vector<vector<query>> qs(n);
    for(int i=0;i<Q;++i) {
        query myq;
        myq.id=i;
        int at = myq.read();
        qs[at].push_back(myq);
    }
    
    for(int rep=0;rep<2;++rep) {
        vector<pair<ll,int>> st = {{-oo,-1}};
        segtree seg(n);
        for(int i=0;i<n;++i) {
            if(adj[i].empty()) {
                seg.set(i,i,-oo+d[i]);
            }
            auto update = [&](ll w, int at) {
                while(st.back().first>=w) {
                    auto [old,j] = st.back();
                    st.pop_back();
                    seg.set(st.back().second+1,j,2*old);
                }
                
                seg.set(st.back().second+1,at,-2*w);
                st.push_back({w,at});
            };
            
            if(rep==0 and p[i]>=0 and p[i]<n) {
                update(d[p[i]],i-1);
            }
            update(d[i],i);
            for(auto& q : qs[i]) {
                q.ans = min(q.ans,seg.get(q.l,q.r)+d[i]);
            }
            if(rep==1 and p[i]>=0 and p[i]<n) {
                update(d[p[i]],i);
            }
        }
        reverse(all(p));
        reverse(all(qs));
        for(auto& i : p) i=n-1-i;
        for(auto& v : qs) for(auto& i : v) {
            swap(i.l,i.r);
            i.l=n-1-i.l;
            i.r=n-1-i.r;
        }
        reverse(all(d));
        reverse(all(adj));
    }
    vector<ll> ans(Q);
    for(auto& v : qs) for(auto& i : v) ans[i.id]=i.ans;
    for(auto i : ans) cout << i << '\n';
}