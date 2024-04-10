#include <iostream>

using namespace std;
int n, m, k;
long long dp[5001][5001];
long long a[5001], s[5001];
int main()
{
cin>>n>>m>>k;

for(int i=1;i<=n;i++)
    cin>>a[i], s[i]=s[i-1]+1LL*a[i];

    for(int i=1;i<=k;i++)
    for(int j=m;j<=n;j++)
        dp[i][j]=max(dp[i][j-1], dp[i-1][j-m] + s[j]-s[j-m]);
    cout<<dp[k][n];

    return 0;
}