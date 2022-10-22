#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=3e3+10;
string s[mn];
ll dp[mn][mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    if(s[0][1]=='#'||s[1][0]=='#'||s[n-2][m-1]=='#'||s[n-1][m-2]=='#'){
        printf("0");
        return 0;
    }
    dp[0][1]=1;
    for(int i=0;i<n;i++)for(int j=1;j<m;j++){
        if((i==0&&j==1)||s[i][j]=='#')continue;
        dp[i][j]=((i?dp[i-1][j]:0)+dp[i][j-1])%mod;
    }
    ll aa,ab,ba,bb;
    aa=dp[n-2][m-1],ab=dp[n-1][m-2];
    memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    for(int i=1;i<n;i++)for(int j=0;j<m;j++){
        if((i==1&&j==0)||s[i][j]=='#')continue;
        dp[i][j]=(dp[i-1][j]+(j?dp[i][j-1]:0))%mod;
    }
    ba=dp[n-2][m-1],bb=dp[n-1][m-2];
    ll ans=(aa*bb-ab*ba)%mod;
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}