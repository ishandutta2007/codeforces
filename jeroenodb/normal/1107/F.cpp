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
const int mxN = 503, oo = 1e9;
ll dp[mxN];
typedef array<int,3> ar3;
int main() {
    int n; cin >> n;
    vector<ar3> ab(n);
    for(auto& [a,b,k]: ab) cin >> a >> b >> k;
    sort(all(ab), [&](ar3 a, ar3 b) { return a[1]<b[1];});
    fill(dp,dp+n+1,-oo);
    dp[0]=0;
    for(int i=n-1;i>=0;--i) {
        auto [a,b,k] = ab[i];
        for(int j=n;j>=0;--j) {
            if(a-(ll)b*k>0) dp[j]+=a-(ll)b*k;
            if(j) dp[j] = max(dp[j],dp[j-1]+a-(ll)b*(j-1));
        }
    }
    cout << *max_element(dp,dp+n+1) << '\n';
}