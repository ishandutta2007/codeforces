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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vi last(n+1,-1);
    a.erase(unique(all(a)),a.end());
    n = a.size();
    
    vi dp(n);
    for(int i=0;i<n;++i) {
        auto& l = last[a[i]];
        if(l!=-1) {
            dp[i]=1+dp[l+1];
        }
        l=i;
        if(i) dp[i] = max(dp[i],dp[i-1]);
    }
    cout << n-dp[n-1] << '\n';
}