#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[501];
ll dp[2][501][501];
const ll mod=1e9+7;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)cin>>s[i];
    dp[0][0][n-1]=(s[0][0]==s[n-1][m-1]);
    for(int i=1;i<(n+m)/2;i++){
        memset(dp[i&1],0,sizeof(dp[i&1]));
        for(int j=max(0,i-m+1);j<=min(n-1,i);j++){
            int jj=i-j;
            for(int k=n-1-max(0,i-m+1);k>=n-1-min(n-1,i);k--){
                int kk=(n+m-2)-i-k;
                if(s[j][jj]==s[k][kk]){
                    dp[i&1][j][k]=(dp[i&1^1][j][k]+(j?dp[i&1^1][j-1][k+1]:0)+dp[i&1^1][j][k+1]+(j?dp[i&1^1][j-1][k]:0))%mod;
                }
                else dp[i&1][j][k]=0;
            }
        }
    }
    ll ans=0;
    if((n+m)&1){
        for(int i=0;i<n;i++)ans+=dp[(n+m-2)/2%2][i][i]+dp[(n+m-2)/2%2][i][i+1];
    }
    else{
        for(int i=0;i<n;i++)ans+=dp[(n+m-2)/2%2][i][i];
    }
    ans%=mod;
    printf("%lld",ans);
}