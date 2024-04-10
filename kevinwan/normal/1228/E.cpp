#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll ch[251][251],dp[251][251],pp[251],p1[251];
int main(){
    int n,p;
    scanf("%d%d",&n,&p);
    ch[0][0]=1;
    pp[0]=p1[0]=1;
    for(int i=1;i<=n;i++)pp[i]=pp[i-1]*p%mod,p1[i]=p1[i-1]*(p-1)%mod;
    for(int i=1;i<=n;i++){
        ch[i][0]=1;
        for(int j=1;j<=i;j++){
            ch[i][j]=(ch[i-1][j-1]+ch[i-1][j])%mod;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=j;k++){
                dp[i][j]+=dp[i-1][k]*ch[n-k][j-k]%mod*p1[n-j]%mod*(pp[k]-((j==k)?p1[k]:0))%mod;
                dp[i][j]%=mod;
            }
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    if(dp[n][n]<0)dp[n][n]+=mod;
    printf("%lld",dp[n][n]);
}