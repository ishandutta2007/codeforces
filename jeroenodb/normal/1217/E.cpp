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
struct node {
    array<int,9> best;
    int ans=2*oo;
    node() {
        fill(all(best),oo);
    }
    node(int val) {
        int cur = val;
        for(int i=0;i<9;++i) {
            int dig = cur%10;
            if(dig!=0) best[i]=val;
            else best[i]=oo;
            cur/=10;
        }
    }
    void merge(const node& o) {
        ans = min(ans,o.ans);
        for(int i=0;i<9;++i) {
            if(best[i]!=oo and o.best[i]!=oo) ans=min(ans,best[i]+o.best[i]);
            best[i] = min(best[i],o.best[i]);
        }
    }
    friend node merge(node a, const node& b) {
        a.merge(b);
        return a;
    }
};
struct segtree {
    int ptwo;
    vector<node> seg;
    segtree(){}
    node& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=nn;
        seg.assign(ptwo*2,0);
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        node resl, resr;
        while(l and l<=r) {
            if(l%2==1) resl = merge(resl,seg[l++]);
            if(r%2==0) resr = merge(seg[r--],resr);
            l/=2; r/=2;
        }
        return merge(resl,resr);
    }
    void update(int i, int val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = node(val);
        for(i/=2;i>=1;i/=2) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    segtree seg(n);
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        seg[i] = node(a);
    }
    seg.build();
    while(m--) {
        int t; cin >> t;
        if(t==1) {
            int i,x; cin >> i >> x;
            seg.update(i-1,x);
        } else {
            int l,r; cin >> l >> r,--l,--r;
            int tmp = seg.query(l,r).ans;
            if(tmp==2*oo) tmp=-1;
            cout << tmp << '\n';
        }
    }
}