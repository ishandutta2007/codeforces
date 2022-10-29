#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector < pair < pll , pll > > v;
int n,i,t,d,p,dp[2002][101]={0},m=0,j;
vl ddp[2002][101];
int main()
{
    io
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>t>>d>>p;
        v.pb({{d-1,i},{t,p}});
        m=max(m,d);
    }
    sort(v.begin(),v.end());
    for(i=1;i<=m;++i)
    {
        if(i>=v[0].y.x && v[0].y.x<=v[0].x.x)
        {
            dp[i][0]=v[0].y.y;
            ddp[i][0].pb(v[0].x.y);
        }
        for(j=1;j<n;++j)
        if(i>=v[j].y.x && v[j].x.x>=v[j].y.x && dp[min(i-v[j].y.x,v[j].x.x-v[j].y.x)][j-1]+v[j].y.y>dp[i][j-1])
        {
            dp[i][j]=dp[min(i-v[j].y.x,v[j].x.x-v[j].y.x)][j-1]+v[j].y.y;
            ddp[i][j]=ddp[min(i-v[j].y.x,v[j].x.x-v[j].y.x)][j-1];
            ddp[i][j].pb(v[j].x.y);
        }
        else
        {
            dp[i][j]=dp[i][j-1];
            ddp[i][j]=ddp[i][j-1];
        }
    }
    cout<<dp[m][n-1]<<endl;
    cout<<ddp[m][n-1].size()<<endl;
    for(j=0;j<ddp[m][n-1].size();++j)
    cout<<ddp[m][n-1][j]<<" ";
    cout<<endl;
    return 0;
}