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
const int mxN = 1e5+1, oo = 1e8;
struct segtree {
    int ptwo,n;
    vi segmn, segmx;
    segtree(){}
    segtree(int nn) {
        ptwo=1;
        n=nn;
        while(ptwo<nn) 
            ptwo*=2;
        segmn.assign(ptwo*2,oo);
        segmx.assign(ptwo*2,-oo);
    }
    void build() {
        for(int i=ptwo;i<ptwo*2;++i) {
            segmx[i] = segmn[i];
        }
        for(int i=ptwo-1;i>0;--i) {
            segmx[i] = max(segmx[2*i],segmx[2*i+1]);
            segmn[i] = min(segmn[2*i],segmn[2*i+1]);
        }
    }
    auto query(int l, int r) {
        if(l>=n or r<0) return pi{oo,-oo};
        l+=ptwo; r+=ptwo;
        int mn = oo, mx = -oo;
        while(l and l<=r) {
            if(l%2==1) {
                mn = min(mn,segmn[l]);
                mx = max(mx,segmx[l++]);
            }
            if(r%2==0) {
                mn = min(mn,segmn[r]);
                mx = max(mx,segmx[r--]);
            }
            l/=2; r/=2;
        }
        return pi{mn,mx};
    }
    // void update(int i, int val) {
    //     assert(i>=0 and i<ptwo);
    //     i+=ptwo;
    //     seg[i] += val;
    //     for(i/=2;i>=1;i/=2) {
    //         segmx[i] = max(segmx[2*i],segmx[2*i+1]);
    //         segmn[i] = min(segmn[2*i],segmn[2*i+1]);
    //     }
    // }
};
int main() {
    int t; cin >> t;

    while(t--) {
        int n,m; cin >> n >> m;
        segtree seg(n+1);
        vi pref(n+1);
        seg.segmn[seg.ptwo]=0;
        for(int i=1;i<=n;++i) {
            char c; cin >> c;
            if(c=='+') {
                seg.segmn[i+seg.ptwo] = seg.segmn[seg.ptwo+i-1]+1;
            } else {
                seg.segmn[i+seg.ptwo] = seg.segmn[seg.ptwo+i-1]-1;
            }
            pref[i] = seg.segmn[i+seg.ptwo];
        }
        seg.build();
        while(m--) {
            int l,r; cin >> l >> r;
            auto [mn,mx] = seg.query(0,l-1);
            auto [mn2,mx2] = seg.query(r, n);
            mn = min(mn, mn2+pref[l-1]-pref[r]);
            mx = max(mx, mx2+pref[l-1]-pref[r]);
            cout << max(1,mx-mn+1) << '\n';
        }
        
    }
}