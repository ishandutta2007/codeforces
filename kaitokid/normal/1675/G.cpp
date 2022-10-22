#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[266],dp[251][251][502];
int go(int x,int mx,int f)
{
    if(f>m || f<(-m))return 1000000000;
    if(x==n){if(f==0)return 0;return 1000000000;}
    if(dp[x][mx][250+f]!=-1)return dp[x][mx][250+f];
    int res=1000000000;
    if(mx>0)res=go(x,mx-1,f);
    int u=a[x]+f;
    int tmp=abs(mx-u)+go(x+1,mx,u-mx);
    res=min(tmp,res);
    return dp[x][mx][250+f]=res;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<go(0,m,0);
    return 0;

}