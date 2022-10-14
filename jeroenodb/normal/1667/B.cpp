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
    int ptwo;
    vector<ll> seg;
    segtree(){}
    ll& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=1;
        while(ptwo<nn) 
            ptwo*=2;
        seg.assign(ptwo*2,-(1e9));
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        ll res = -oo;
        while(l and l<=r) {
            if(l%2==1) res = max(res,seg[l++]);
            if(r%2==0) res = max(res,seg[r--]);
            l/=2; r/=2;
        }
        return res;
    }
    void update(int i, ll val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = max(seg[i],val);
        for(i/=2;i>=1;i/=2) {
            seg[i] = max(seg[2*i],seg[2*i+1]);
        }
    }
};
void solve() {
    int n; cin >> n;
    vector<ll> p(n+1);
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        p[i+1]=p[i]+a;
    }
    auto cs = p;
    cs.push_back(-1e18-1);
    sort(all(cs));
    cs.erase(unique(all(cs)),cs.end());
    for(auto& i : p) i = lower_bound(all(cs),i)-cs.begin();
    segtree seg(n+3),seg2(n+3);
    vi dp(2+n,-oo);
    int r=0;
    int mydp=0;
    for(auto i : p) {
        // best ending here
        if(r==0) mydp=0;
        else mydp = max({(ll)dp[i],seg.query(0,i-1)+r, seg2.query(i+1,n+2)-r});

        dp[i] = max(dp[i],mydp);
        seg.update(i,mydp-r);
        seg2.update(i,mydp+r);
        ++r;
    }
    cout << mydp << '\n';

    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}