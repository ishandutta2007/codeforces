#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s[2];
int dp[2][200009];
int go(int x,int y)
{
    if(y>=n-1)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    if(s[1-x][y]=='0')return dp[x][y]=go(x,y+1);
    dp[x][y]=1+go(x,y+1);
    if(s[x][y+1]=='0')return dp[x][y]=min(dp[x][y],go(1-x,y+1));
    dp[x][y]=min(dp[x][y],1+go(1-x,y+2));
    return dp[x][y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s[0]>>s[1];
    memset(dp,-1,sizeof dp);
    int res=go(0,0),tot=0;
    for(int j=0;j<2;j++)
    for(int i=0;i<n;i++)
        if(s[j][i]=='1')tot++;
    tot-=res;
    cout<<tot;
    return 0;
}