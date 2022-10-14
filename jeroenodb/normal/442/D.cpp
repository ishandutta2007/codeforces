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
const int mxN = 1e6+2, oo = 1e9;
int dp[mxN];
int mx[mxN],mx2[mxN],par[mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int ans =0;
    for(int j=2;j<n+2;++j) {
        int i=j;
        cin >> par[i];
        dp[i]=1;
        while(par[i]!=1) {
            int p=par[i];
            if(dp[mx[p]]<dp[mx2[p]]) swap(mx[p],mx2[p]);
            if(i!=mx[p] and i!=mx2[p]) {
                if(dp[i]>dp[mx[p]]) {
                    mx2[p]=mx[p];
                    mx[p]=i;
                } else if(dp[i]>dp[mx2[p]]) {
                    mx2[p]=i;
                }
            }
            int prv = dp[p];
            dp[p] = max(dp[mx[p]],dp[mx2[p]]+1);
            if(dp[p]==prv) {
                break;
            }
            i=p;
        }
        if(par[i]==1) ans=max(ans,dp[i]);
        cout << ans << ' ';
    }
}