#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 4E6+7;
int dp[N],MOD;
void solve(){
    int n;
    cin>>n>>MOD;
    dp[n] = 1;
    for(int i = n-1;i>=1;--i){
        dp[i] = dp[i+1];
        if (dp[i]<0)
            dp[i]+=MOD;
        for(int mult = 2;mult*i<=n;++mult){
            int l = mult*i,r = min(n+1,mult*(i+1));
            dp[i]+=dp[l]-dp[r];
            if (dp[i]<0)
                dp[i]+=MOD;
            if (dp[i]>=MOD)
                dp[i]-=MOD;
        }
        dp[i]+=dp[i+1];
        if (dp[i]>=MOD)
            dp[i]-=MOD;
    }
    dp[1]-=dp[2];
    if (dp[1]<0)
        dp[1]+=MOD;
    cout<<dp[1]<<endl;
}
int main() {
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}