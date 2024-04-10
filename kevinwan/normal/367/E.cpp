#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;
const ll mn=3e5+10;
ll dp[2][400][400];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x;
    cin>>n>>m>>x;
    if(n>m){printf("0");return 0;}
    dp[0][0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                dp[1][j][k]=(j?dp[0][j-1][k]:0)+(i!=x?dp[0][j][k]:0),dp[1][j][k]%=mod;
            }
        }
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                dp[0][j][k]=(k?dp[1][j+1][k-1]:0)+dp[1][j][k],dp[0][j][k]%=mod;
            }
        }
    }
    for(int i=1;i<=n;i++)dp[0][0][n]*=i,dp[0][0][n]%=mod;
    printf("%lld",dp[0][0][n]);
}