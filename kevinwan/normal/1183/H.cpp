#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=101;
const ll mod=1e9+7;
ll dp[mn][mn],pre[mn][mn];
int lst[mn],ch[26];
int main(){
    int n,i,j,k;
    ll kk;
    scanf("%d%lld",&n,&kk);
    string s;
    cin>>s;
    s=" "+s;
    for(i=1;i<=n;i++)lst[i]=ch[s[i]-'a'],ch[s[i]-'a']=i;
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            dp[i][j]=min(dp[i-1][j-1]-(lst[i]?dp[lst[i]-1][j-1]:0)+dp[i-1][j],kk);
        }
        dp[i][0]=1;
    }
    ll ans=0;
    for(i=n;i>=0;i--){
        ans+=min(kk,dp[n][i])*(n-i);
        kk-=min(kk,dp[n][i]);
    }
    if(kk)printf("-1");
    else printf("%lld",ans);
}