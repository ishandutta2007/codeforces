#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long n,x,k,p,i,a[2002],b[2002],dp[2002][2002],j;
int main()
{
    io
    vll v;
    cin>>n>>k>>p;
    for(i=1;i<=n;++i)
    cin>>a[i];
    for(i=1;i<=k;++i)
    cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+k+1);
    for(i=0;i<=n;++i)
    for(j=0;j<=k;++j)
    dp[i][j]=1e15;
    for(i=0;i<=k;++i)
    dp[0][i]=0;
    for(i=1;i<=n;++i)
    for(j=1;j<=k;++j)
    dp[i][j]=min(dp[i][j-1],max(dp[i-1][j-1],abs(a[i]-b[j])+abs(b[j]-p)));
    cout<<dp[n][k];
    return 0;
}