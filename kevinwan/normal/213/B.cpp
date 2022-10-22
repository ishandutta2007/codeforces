#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll num[11];
ll ch[101][101];
ll dp[11][101];
int main(){
    int n;
    scanf("%d",&n);
    ch[0][0]=1;
    for(int i=1;i<=n;i++){
        ch[i][0]=1;
        for(int j=1;j<=i;j++)ch[i][j]=(ch[i-1][j-1]+ch[i-1][j])%mod;
    }
    for(int i=0;i<10;i++)scanf("%lld",num+i);
    dp[10][0]=1;
    for(int i=9;i>=0;i--){
        for(int j=num[i];j<=n;j++){
            for(int k=num[i];k<=j;k++){
                dp[i][j]+=ch[j-(i==0)][k]*dp[i+1][j-k];
                dp[i][j]%=mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=dp[0][i],ans%=mod;
    printf("%lld",ans);
}