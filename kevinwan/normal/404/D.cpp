#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e6+10;
ll dp[mn][3];
int main()
{
    string s;
    cin>>s;
    int i,j,n=s.size();
    s=" "+s+" ";
    if(s[1]=='?')dp[1][0]=dp[1][1]=1;
    else if(s[1]=='*')dp[1][0]=1;
    else if(s[1]!='2')dp[1][1]=1;
    for(i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        dp[i][1]=dp[i-1][1]+dp[i-1][2];
        dp[i][2]=dp[i-1][0];
        if(s[i-1]=='0')dp[i][0]=0;
        else if(s[i-1]=='2')dp[i][1]=dp[i][2]=0;
        else if(s[i-1]=='1'){
            dp[i][0]-=dp[i-1][2];
            dp[i][1]-=dp[i-1][1];
        }
        if(s[i]=='*'){
            dp[i][1]=dp[i][2]=0;
        }
        if(s[i]=='0'){
            dp[i][0]=dp[i][2]=0;
        }
        if(s[i]=='1'){
            dp[i][0]=0;
        }
        if(s[i]=='2'){
            dp[i][0]=dp[i][1]=0;
        }
        for(j=0;j<3;j++)dp[i][j]%=mod;
    }
    if(s[n]=='2')printf("0");
    else if(s[n]=='1')printf("%lld",dp[n][2]);
    else printf("%lld",(dp[n][0]+dp[n][1]+dp[n][2])%mod);
}