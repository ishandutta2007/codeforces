#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll dp[5001][5001];
int main(){
    int n,a,b,k,i,j;
    scanf("%d%d%d%d",&n,&a,&b,&k);
    dp[0][a]=1;
    for(i=1;i<=n;i++)dp[0][i]+=dp[0][i-1];
    for(i=1;i<=k;i++){
        for(j=1;j<=n;j++){
            if(j<b)dp[i][j]=dp[i-1][(j+b-1)/2]-(dp[i-1][j]-dp[i-1][j-1]);
            if(j>b)dp[i][j]=dp[i-1][n]-dp[i-1][(j+b)/2]-(dp[i-1][j]-dp[i-1][j-1]);
        }
        for(j=1;j<=n;j++)dp[i][j]+=dp[i][j-1],dp[i][j]%=mod;
    }
    printf("%lld",(dp[k][n]+mod)%mod);
}