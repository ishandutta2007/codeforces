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
    ll worst = 0, sm=0;
    node() {
        *this = node(0);
    }
    node(int val) {
        sm = worst = val;
    }
    void merge(const node& o) {
        worst = min(worst,sm+o.worst);
        sm+=o.sm;
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
        ptwo = 1;
        while(ptwo<=nn) ptwo*=2;
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
    int t; cin >> t;
    while(t--) {
        int n,s; cin >> n >> s;
        segtree seg(n);
        for(int i=0;i<n;++i) {
            int a; cin >> a;
            seg[i] = node(a);
        }
        seg.build();
        array<int,3> ans = {-1,-1,-1};
        for(int i=0;i<n;++i) {
            if(seg.query(i,i).worst>=-s) {
                int l=i,r=n-1;
                while(l<r) {
                    int mid = (l+r+1)/2;
                    if(seg.query(i,mid).worst>=-s) {
                        l = mid;
                    } else r=mid-1;
                }
                ans = max(ans,{r-i+1,i+1,r+1});
            }
        }
        if(ans[0]==-1) cout << "-1\n";
        else cout << ans[1] << ' ' << ans[2] << '\n';
    }
}