#include <bits/stdc++.h>
using namespace std;

long long dp[50000][5];
long long vreme[50000][5];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long i,j,m,n;
    cin>>m>>n;
    for(i=0;i<m;i++)for(j=0;j<n;j++)cin>>vreme[i][j];
    dp[0][0]=vreme[0][0];
    for(i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]+vreme[0][i];
    }
    for(i=1;i<m;i++){
        dp[i][0]=vreme[i][0]+dp[i-1][0];
    }
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])+vreme[i][j];
        }
    }
    for(i=0;i<m;i++)cout<<dp[i][n-1]<<" ";
    return 0;
}