//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 2E5+7;
const ll MOD = 1E9+7;
ll po[N],dp[2][N];
void solve(){
    int n,k;
    cin>>n>>k;
    dp[0][0] = 1;
    for(int i = 1;i<=k;++i){
        dp[1][i] = dp[0][i] = 0;
        if (!(n&1)){
            dp[1][i] = (dp[1][i]+dp[0][i-1])%MOD;
            dp[0][i] = (dp[0][i]+dp[0][i-1]*(po[n-1]-1))%MOD;
        }
        else{
            dp[0][i] = (dp[0][i]+dp[0][i-1]*(po[n-1]+1))%MOD;
        }
        dp[1][i] = (dp[1][i]+dp[1][i-1]*po[n])%MOD;
    }
    cout<<(dp[1][k]+dp[0][k])%MOD<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    po[0] = 1;
    for(int i = 1;i<N;++i)
        po[i] = po[i-1]*2%MOD;
    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}