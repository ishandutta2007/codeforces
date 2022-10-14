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
vi a;
struct node {
    ll best=0,pref=0,suf=0, sm=0;
    node(){}
    node(int val) {
        sm=val;
        best=pref=suf=max(val,0);
    }
    friend node merge(const node& a,const node& b) {
        node res;
        res.best = max({a.best,b.best,a.suf+b.pref});
        res.pref = max(a.pref,a.sm+b.pref);
        res.suf = max(b.suf,a.suf+b.sm);
        res.sm=a.sm+b.sm;
        return res;
    }
};
vector<node> solve(int l, int r) {
    if(l+1==r) {
        return {node(a[l])};
    }
    int m = (l+r)/2;
    auto ra = solve(l,m), rb = solve(m,r);
    vector<node> res(r-l);
    m = (r-l)/2;
    for(int i=0;i<m;++i) {
        res[i] = merge(ra[i],rb[i]);
    }
    for(int i=m;i<r-l;++i) {
        res[i] = merge(rb[i-m],ra[i-m]);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    a.resize(1<<n);
    for(auto& i : a) cin >> i;
    auto ans = solve(0,1<<n);
    int q; cin >> q;
    int f=0;
    while(q--) {
        int k; cin >> k;
        f^=1<<k;
        cout << ans[f].best << '\n';
    }
}