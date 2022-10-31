#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 207;
const ll INF = 1E18;
ll A[DIM],dp[DIM*2][DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i)cin>>A[i];
        sort(A+1,A+1+n);
        for(ll i = 1;i<=n;++i)dp[0][i] = INF;
        for(ll i = 1;i<DIM*2;++i){
            for(ll j = 1;j<=n;++j){
                dp[i][j] = INF;
                for(ll t = 0;t<i;++t){
                    dp[i][j] = min(dp[i][j],dp[t][j-1]+abs(i-A[j]));
                }
            }
        }
        ll res = INF;
        for(ll i = 1;i<DIM*2;++i)res = min(res,dp[i][n]);
        cout<<res<<endl;
    }
    return 0;

}