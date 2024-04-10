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
void solve() {
    int n; cin >> n;
    vi cs;cs.reserve(3*n+2);
    cs.push_back(-2*oo-1);
    cs.push_back(2*oo+1);
    vector<array<int,2>> ivs(n);
    for(auto& [l,r] : ivs) {
        cin >> l >> r;
        l*=2,r*=2;
        cs.push_back(l),cs.push_back(r);
        cs.push_back(r+1);
    }
    sort(all(cs));
    cs.erase(unique(all(cs)),cs.end());
    int m = cs.size();
    vi pref(m+1);
    for(auto& [l,r] : ivs) {
        l = lower_bound(all(cs),l)-cs.begin();
        r = lower_bound(all(cs),r)-cs.begin();
        pref[l]++;
        pref[r+1]--;
    }
    vi sts;
    int zeros=1;
    for(int i=1;i<=m;++i) {
        pref[i]+=pref[i-1];
        if(pref[i]>1 and pref[i-1]<2) {
            sts.push_back(i);
        }
        if(pref[i]==0 and pref[i-1]!=0) {
            zeros++;
        }
    }
    if(pref.back()==0) zeros--;
    int ans = 0;
    for(auto [l,r] : ivs) {
        auto bigs = upper_bound(all(sts),r)-lower_bound(all(sts),l);
        if(pref[l-1]>=2 and pref[l]>=2) bigs++;
        if(bigs==0) {
            if(pref[l-1]==0 and pref[r+1]==0) ans = max(ans,zeros-1);
            else if(pref[l-1]!=0 and pref[r+1]!=0) ans = max(ans,zeros+1);
            else ans = max(ans,zeros);
        } else {
            int cur = bigs - 1 +zeros;
            
            if(pref[l]==1 and pref[l-1]!=0) cur++;
            if(pref[r]==1 and pref[r+1]!=0) cur++;
            ans = max(cur,ans);
        }
    }
    cout << ans << '\n';

}
int main() {
    int t; cin >> t;
    while(t--) solve();
}