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
        // need to store historic sum
        ll total=0, lazy=0; 
        int add=0, sm=0;
        int t=0,len=1, myt=0;
        bool isL=0;
        node() {}
    };
    int t=0;
    vector<node> seg;
    int n,ptwo;
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
    }
    void apply(int i) {
        auto& v = seg[i];
        v.total+=v.len*v.lazy+(ll)(v.t-v.myt)*v.sm;
        v.sm+=v.add*v.len;
        v.add=v.lazy=0;
        v.isL=0;
        v.myt=v.t;
    }
    void puttag(int i, int add, int mt, ll lazy=0) {
        auto& v = seg[i];
        if(v.isL) v.lazy+=(mt-v.t)*ll(v.add);
        v.lazy+=lazy;
        v.add+=add;
        v.t = mt;
        v.isL=true;
    }
    void pull(int i) {
        auto& v = seg[i];
        v.len = seg[i*2].len+seg[i*2+1].len;
        v.total=seg[i*2].total+seg[i*2+1].total;
        v.sm = seg[i*2].sm+seg[i*2+1].sm;
        v.t = max(seg[i*2].t,seg[i*2+1].t);
        v.total+=ll(v.t-seg[i*2].t)*seg[i*2].sm + ll(v.t-seg[i*2+1].t)*seg[i*2+1].sm;
    }
    void push(int i) { // TODO!
        auto& v = seg[i];
        if(!v.isL) return;
        if(v.len!=1) {
            puttag(i*2,v.add,v.t,v.lazy);
            puttag(i*2+1,v.add,v.t,v.lazy);
        }
        apply(i);
    }
    ll get(int i, int l, int r, int ql, int qr) {
        push(i);
        if(qr<l or r<ql) return 0;
        
        if(ql<=l and r<=qr) {
            return seg[i].total;
        }
        int mid = (l+r)/2;
        auto res = get(i*2,l,mid,ql,qr)+get(i*2+1,mid+1,r,ql,qr); // TODO
        return res;
    }
    void set(int i, int l, int r, int ql, int qr, int v) {
        push(i);
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr) {
            puttag(i,v,t); // correct?
            push(i);
            return;
        }
        
        int mid = (l+r)/2;
        set(i*2,l,mid,ql,qr,v),set(i*2+1,mid+1,r,ql,qr,v);
        pull(i);
    }
    ll get(int l, int r) {
        return get(1,0,ptwo-1,l,r);
    }
    void set(int l, int r, int v) {
        if(l>r) return;
        set(1,0,ptwo-1,l,r,v);
    }
    node& operator[](int i) {return seg[i+ptwo];}
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            pull(i);
        }
    }
    void incT() {
        t++;
        set(0,ptwo-1,0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    vi p(n),ip(n+1);
    for(auto& i : p) cin >> i;
    for(int i=0;i<n;++i) {
        ip[p[i]]=i;
    }
    vector<vector<pi>> qs(n);
    for(int i=0;i<q;++i) {
        int l,r; cin >> l >> r;
        --l,--r;
        qs[r].push_back({l,i});
    }
    vi goods(n,-1),prv(n,-1),nxt(n);
    vector<bool> active(n);
    segtree seg(n+1);
    seg.build();
    auto update = [&](int i, int x) {
        x = min(i,x);
        if(active[i]) {
            seg.set(goods[i]+1,x,1);
        }
        goods[i] = max(goods[i],min(i,x));
    };
    auto toggle = [&](int i) {
        if(active[i]) {
            active[i]=0;
            seg.set(prv[i]+1,goods[i],-1);
        } else {
            active[i]=1;
            seg.set(prv[i]+1,goods[i],1);
        }
    };
    vector<ll> ans(q);
    for(int i=0;i<n;++i) {
        int v = p[i];
        for(int o=v;o<=n;o+=v) {
            int w = o/v;
            if(ip[w]<i) {
                update(ip[o],ip[w]);
            }
        }
        // activate or deactivate?
        prv[i]=i-1;
        
        while(prv[i]!=-1) {
            if(p[prv[i]]<v) {
                // deactivate
                int j = prv[i];
                toggle(j);
                prv[i]=prv[prv[i]];
            } else break;
        }
        goods[i] = max(goods[i],prv[i]);
        toggle(i);
        seg.incT();
        for(auto [l,id] : qs[i]) {
            ans[id] = seg.get(l,i);
        }
       
    }
    for(auto v : ans) cout << v << '\n';
}