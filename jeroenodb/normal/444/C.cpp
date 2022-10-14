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
        int col=1,lazy=0,len=1;
        ll sm=0,delta=0;
        ll sum() {
            return delta*len+sm;
        }
        node() {}
    };
    vector<node> seg;
    int n,ptwo;
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
    }
    void puttag(int i, int val) {
        // assuming node i has all the same color, make it all a new color
        auto& v = seg[i];
        assert(v.col);
        v.delta+=abs(v.col-val); // this forgets information
        v.col=val;
        v.lazy=val;
    }

    void pull(int i) {
        auto& v = seg[i];
        assert(!v.lazy);
        v.sm = seg[i*2].sum()+seg[i*2+1].sum();
        v.len = seg[i*2].len+seg[i*2+1].len;
        v.col=seg[i*2].col;
        if(seg[i*2+1].col!=v.col) v.col=0;
    }
    void push(int i) { // TODO!
        auto& v = seg[i];
        if(v.lazy) for(auto t : {0,1}) {
            seg[i*2+t].delta+=v.delta;
            seg[i*2+t].col=v.lazy;
            seg[i*2+t].lazy=v.lazy;
        }
        v.lazy=0,v.delta=0;
    }
    int ql, qr;
    ll get(int i, int l, int r) {
        if(qr<l or r<ql) return 0LL;
        if(ql<=l and r<=qr) {
            return seg[i].sum();
        }
        int mid = (l+r)/2;
        push(i);
        auto res = get(i*2,l,mid)+get(i*2+1,mid+1,r); // TODO
        pull(i);
        return res;
    }
    void set(int i, int l, int r, int v) {
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr and seg[i].col) {
            puttag(i,v); // correct?
            return;
        }
        int mid = (l+r)/2;
        push(i);
        set(i*2,l,mid,v),set(i*2+1,mid+1,r,v);
        pull(i);
    }
    void set(int l, int r, int v) {
        ql=l,qr=r;
        set(1,0,ptwo-1,v);
    }
    ll get(int l, int r) {
        ql=l,qr=r;
        return get(1,0,ptwo-1);
    }
    node& operator[](int i) {return seg[i+ptwo];}
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            pull(i);
        }
    }
};

vector<ll> solve(int n,vector<array<int,4>> ops) {
    segtree seg(n);
    for(int i=0;i<n;++i) {
        seg[i].col=i+1;
    }
    seg.build();
    vector<ll> ans;
    for(auto [t,l,r,x] : ops) {
        if(t==1) seg.set(l,r,x);
        else ans.push_back(seg.get(l,r));
    }
    return ans;
}
vector<ll> brute(int n,vector<array<int,4>> ops) {
    vi col(n);
    iota(all(col),1);
    vector<ll> sm(n);
    vector<ll> ans;
    for(auto [t,l,r,x] : ops) {
        ll res=0;
        for(int i=l;i<=r;++i) {
            if(t==1) {
                sm[i]+=abs(col[i]-x);
                col[i]=x;
            } else res+=sm[i];
        }
        if(t==2) ans.push_back(res);
    }
    return ans;
}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
void gen() {

    while(true) {
        int n = 4, m = 4;
        vector<array<int,4>> ops;
        for(int i=0;i<m;++i) {
            int t = rnd(1,2);
            int l = rnd(0,n-1), r = rnd(0,n-1);
            // int l = 0,r=1;
            if(l>r) swap(l,r); 
            if(t==1) ops.push_back({t,l,r,rnd(1,10)});
            else ops.push_back({t,l,r,0});
        }
        auto ra = solve(n,ops), rb = brute(n,ops);
        if(ra!=rb) {
            debug(n);
            debug(ra);
            debug(rb);
            for(int i=0;i<m;++i) {
                debug(ops[i]);
            }
            
            brute(n,ops);
            solve(n,ops);
            exit(0);

        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<array<int,4>> ops(m);
    for(auto& [t,l,r,x] : ops) {
        cin >> t >> l >> r;
        --l,--r;
        if(t==1) cin >> x;
    }
    for(auto i : solve(n,ops)) cout << i << '\n';
}