#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=998244353;
int nt[10],pos[10];
int dp[50009][(1<<10)],n,m;
int go(int x,int lst)
{
    if(x==0)return 1;
    if(dp[x][lst]!=-1)return dp[x][lst];
    dp[x][lst]=0;
    for(int i=0;i<10;i++)
    {
        if((lst&(1<<i))==0)continue;
        int g=lst;
        g|=nt[i];
        g=(g|pos[i])^pos[i];
        dp[x][lst]+=go(x-1,g);
        dp[x][lst]%=mod;
    }
    return dp[x][lst];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<10;i++)nt[i]=(1<<10)-1;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        nt[x]^=(1<<y);
        nt[y]^=(1<<x);
        pos[max(x,y)]|=(1<<min(x,y));

    }
    memset(dp,-1,sizeof dp);
    cout<<go(n,(1<<10)-1);
    return 0;
}