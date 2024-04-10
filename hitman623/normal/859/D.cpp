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
vl val[130];
long m,n,i,j;
double a[65][65],dp[130][65][10],p[130][65][10]={0},ans=0;
void gen(long node,long h)
{
    if(h==m) {val[node].pb(node-n+1);return;}
    gen(2*node+1,h+1);
    gen(2*node+2,h+1);
    val[node]=val[2*node+1];
    val[node].insert(val[node].end(),val[2*node+2].begin(),val[2*node+2].end());
}
void sol(long node,long x,long h)
{
    long i;
    if(dp[node][x][h]>=0) return ;
    if(h==m) {dp[node][x][h]=0;p[node][x][h]=1;return;}
    double score=(1<<(m-h-1)),t,cur=0,tt=0;
    if(val[2*node+1].back()>=x)
    {
        sol(2*node+1,x,h+1);
        for(i=0;i<val[2*node+2].size();++i)
        {
            sol(2*node+2,val[2*node+2][i],h+1);
            t=p[2*node+1][x][h+1]*p[2*node+2][val[2*node+2][i]][h+1]*a[x][val[2*node+2][i]]/100;
            cur=max(cur,dp[2*node+2][val[2*node+2][i]][h+1]+dp[2*node+1][x][h+1]);
            tt+=t*score;
            p[node][x][h]+=t;
        }
    }
    else
    {
        sol(2*node+2,x,h+1);
        for(i=0;i<val[2*node+1].size();++i)
        {
            sol(2*node+1,val[2*node+1][i],h+1);
            t=p[2*node+2][x][h+1]*p[2*node+1][val[2*node+1][i]][h+1]*a[x][val[2*node+1][i]]/100;
            cur=max(cur,dp[2*node+1][val[2*node+1][i]][h+1]+dp[2*node+2][x][h+1]);
            tt+=t*score;
            p[node][x][h]+=t;
        }
    }
    dp[node][x][h]=cur+tt;
}
int main()
{
    io
    cout<<fixed<<setprecision(10);
    cin>>m;
    n=(1<<m);
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    cin>>a[i][j];
    gen(0,0);
    memset(dp,-1,sizeof dp);
    for(i=0;i<n;++i)
    {
        sol(0,i,0);
        ans=max(ans,dp[0][i][0]);
    }
    cout<<ans;
    return 0;
}