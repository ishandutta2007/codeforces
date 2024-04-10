//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+7;
const int MOD = 998244353;
int n,m;
pair<int,int> A[N];
ll dp[N],pref[N],ans[N];
ll F(int div){
    int mx = m/div;
    for(int i = 0;i<=mx;++i){
        pref[i] = 1;
    }
    for(int i = 1;i<=n;++i){
        int l = A[i].first/div+(A[i].first%div!=0);
        int r = A[i].second/div;
        for(int val = 0;val<=mx;++val){
            dp[val] = 0;
            int lb = max(0,val-r);
            int rb = val-l;
            if (lb<=rb)
                if (lb!=0)
                    dp[val] = pref[rb]-pref[lb-1];
                else dp[val] = pref[rb];
            if (dp[val]<0)
                dp[val]+=MOD;
            if (dp[val]>=MOD)
                dp[val]-=MOD;
        }
        pref[0] = dp[0];
        for(int val = 1;val<=mx;++val){
            pref[val] = (pref[val-1]+dp[val])%MOD;
        }
    }
    return pref[mx];
}
void solve(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        cin>>A[i].first>>A[i].second;
    memset(dp,-1,sizeof(dp));
    for(int i = 1;i<=m;++i){
        ans[i] = F(i);
    }
    for(int i = m;i>=1;--i){
        for(ll j = i*2;j<=m;j+=i){
            ans[i] = (ans[i]-ans[j]+MOD)%MOD;
        }
    }
    cout<<ans[1]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    //cin>>t;
    t = 1;
    while(t--)
        solve();
    return 0;
}