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
        int mx=0,lazy=0;
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
        auto& v = seg[i];
        v.lazy+=lazy;
        v.mx+=lazy;
    }
    void push(int i, int len) {
        updateNode(i*2,seg[i].lazy);
        updateNode(i*2+1,seg[i].lazy);
        seg[i].lazy=0;
    }
    void pull(int i) {
        auto& v = seg[i];
        v.mx = max(seg[i*2].mx,seg[i*2+1].mx);
    }
    void set(int i, int l, int r, int ql, int qr, int val) {
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr) {
            updateNode(i,val);
            return;
        }
        push(i,r-l+1);
        int mid = (l+r)/2;
        set(i*2,l,mid,ql,qr,val),set(i*2+1,mid+1,r,ql,qr,val);
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
    int n,k,m; cin >> n >> k >> m;
    auto closest = [&](pi a) {
        return a.second+abs(a.first-k)-1;
    };
    set<pi> s; 
    segtree seg(2*n);
    vi cnt(2*n);
    for(int i=0;i<m;++i) {
        int x,y; cin >> x >> y;
        int a = closest({x,y});
        if(s.count({x,y})) {
            s.erase({x,y});
            seg.set(1,0,seg.ptwo-1,0,a,-1);
            if(--cnt[a] == 0) 
                seg.set(1,0,seg.ptwo-1,a,a,-a);
        } else {
            s.insert({x,y});
            seg.set(1,0,seg.ptwo-1,0,a,1);
            if(cnt[a]++ == 0) 
                seg.set(1,0,seg.ptwo-1,a,a,a);
        }
        cout << max(0,seg.seg[1].mx-n) << '\n';
    }

}