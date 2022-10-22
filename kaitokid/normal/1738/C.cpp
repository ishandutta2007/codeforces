#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[209][209][2];
int f[2];
int go(int x,int y,int u)
{
    if(dp[x][y][u]!=-1)return dp[x][y][u];
    if(x+y==0)
        return (u==0);
    if(x+y==1)
    {
        if(y)u=1-u;
        return (u==0);
    }
    dp[x][y][u]=0;
    int d00=1,d01=1,d10=1,d11=1;
    if(x>0)
    {
        if(x>1)d00=go(x-2,y,u);
        if(y>0)d01=go(x-1,y-1,u);
        if(d00&&d01)return dp[x][y][u]=1;

    }
    if(y>0)
    {
        if(y>1)d10=go(x,y-2,1-u);
        if(x>0)d11=go(x-1,y-1,1-u);
        if(d10&&d11)return dp[x][y][u]=1;

    }
    return dp[x][y][u]=0;


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof dp);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        f[0]=f[1]=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x<0)x*=-1;
            f[(x%2)]++;
        }
        int u=go(f[0],f[1],0);
        if(u)cout<<"Alice"<<endl;
          else cout<<"Bob"<<endl;

    }
    return 0;
}