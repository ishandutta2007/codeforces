#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[2009][2009],n,m;
int vis[2009][2009];
string s[2009];
void cal(int u,int v)
{
    int x=u,y=v,r=0;
    do
    {
    if(s[x][y]=='U')x--;
    else if(s[x][y]=='D')x++;
    else if(s[x][y]=='R')y++;
    else if(s[x][y]=='L')y--;
    r++;
    }
    while(u!=x || v!=y);
    x=u,y=v;
    do
    {
    dp[x][y]=r;
    if(s[x][y]=='U')x--;
    else if(s[x][y]=='D')x++;
    else if(s[x][y]=='R')y++;
    else if(s[x][y]=='L')y--;



    }
    while(u!=x || v!=y);
}
void go(int x,int y)
{

    if(x>=n || y>=m || x<0 || y<0)return ;
    if(vis[x][y]==1){cal(x,y);return ;}
    if(vis[x][y]==2)return ;
    vis[x][y]=1;
    if(s[x][y]=='U')go(x-1,y);
    else if(s[x][y]=='D')go(x+1,y);
    else if(s[x][y]=='R')go(x,y+1);
    else if(s[x][y]=='L')go(x,y-1);
    vis[x][y]=2;



}
int rn(int x,int y)
{

    if(x>=n || y>=m || x<0 || y<0)return 0;
    if(dp[x][y]!=-1)return dp[x][y];

    if(s[x][y]=='U')return dp[x][y]=1+rn(x-1,y);
    if(s[x][y]=='D')return dp[x][y]=1+rn(x+1,y);
    if(s[x][y]=='R')return dp[x][y]=1+rn(x,y+1);
    if(s[x][y]=='L')return dp[x][y]=1+rn(x,y-1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>s[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            vis[i][j]=0,dp[i][j]=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            go(i,j);
        int ans=0,r=0,c=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int g=rn(i,j);
                if(g>ans){ans=g;r=i;c=j;}

            }
         cout<<r+1<<" "<<c+1<<" "<<ans<<endl;
    }
    return 0;
}