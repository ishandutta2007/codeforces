#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mx=1e8;
int a[5009],pr[5009],n;
int dp[5009][5009];
int go(int x,int u)
{
    if(x==n)
    {
        if(u==pr[n-1])return 0;
        return mx;
    }
    int &rt=dp[x][u];
    if(rt!=-1)return rt;
    if(a[x]==1)
        {if(u>=pr[x])return rt=x+go(x+1,u);
        else return rt=go(x+1,u)-x;}
    rt=go(x+1,u);
    if(u<pr[x])rt=min(rt,go(x+1,u+1)+x);
    else rt=min(rt,go(x+1,u+1)-x);
    return rt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

cin>>n;
for(int i=0;i<n;i++){cin>>a[i];pr[i]=a[i]+pr[i-1];}
memset(dp,-1,sizeof dp);
cout<<go(0,0);
    return 0;
}