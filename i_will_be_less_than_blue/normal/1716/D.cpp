#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
const ll mod=998244353;
ll dp[N];
ll dp1[N];
ll ans[N];
void solve(){
    int n,k;cin>>n>>k;
    dp[0]=1;
    ll sum=0;
    for (int j=0;j<=n;j++) dp1[j]=0;
    ll res=0ll;
    for (int i=k;;i++){
        sum+=i;
        if (sum>n) break;
        for (int j=0;j<i;j++){
            ll val=0ll;
            for (int t=j;t<=n;t+=i){
                dp1[t]=val;
                val+=dp[t];
                if (val>=mod) val-=mod;
            }
        }
        for (int j=0;j<=n;j++) {
            dp[j]=dp1[j];
            dp1[j]=0;
            ans[j]+=dp[j];
            if (ans[j]>=mod) ans[j]-=mod;
        }
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}