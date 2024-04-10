#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
ll dp[mn][4];
int main()
{
    string s;
    cin>>s;
    int n=s.size(),i,j;
    s=" "+s;
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<4;j++)dp[i][j]=dp[i-1][j];
        if(s[i]=='v'&&s[i-1]=='v'){
            dp[i][1]+=dp[i-2][0];
            dp[i][3]+=dp[i-2][2];
        }
        if(s[i]=='o')dp[i][2]+=dp[i-1][1];
    }
    printf("%lld",dp[n][3]);
}