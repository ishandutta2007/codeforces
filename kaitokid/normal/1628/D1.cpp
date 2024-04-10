#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll dp[2009][2009],n,m,k;
ll go(int x,int y)
{
    if(dp[x][y]!=-1)return dp[x][y];
    if(y==x)return (k*y)%mod;
    ll p=go(x-1,y);
    ll g=go(x-1,y-1);
    p+=g;
    if(p%2)p+=mod;
    p/=2;
    return dp[x][y]=p%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n>>m>>k;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)dp[i][j]=-1;
    cout<<go(n,m)<<endl;
    }
    return 0;
}