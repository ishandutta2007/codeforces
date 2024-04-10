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
int main() {
    int n,m,k; cin >> n >> m >> k;
    vector<ll> a(n); for(auto& i : a) cin >> i;
    sort(all(a));
    a.insert(a.begin(),0);
    for(int i=1;i<a.size();++i) a[i]+=a[i-1];
    vector<ll> dp(k+1,(ll)oo*oo);
    dp[0]=0;
    vector<pi> offer(m);
    for(auto& [x,y]: offer) cin >> x >> y;
    offer.push_back({1,0});
    for(int i=0;i<k;++i) {
        for(auto [x,y] : offer) {
            if(i+x<=k) {
                dp[i+x] = min(dp[i+x],dp[i]+a[i+x]-a[i+y]);
            }
        }
    }
    cout << dp[k] << '\n';
    
}