#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=998244353;
int n;
string s;
int dp[1009][1009];
int num[1009][1009];
int pw[18][1009];
int go(int x,int y)
{
    if(x>=y)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    if(s[x]==s[y])return dp[x][y]=go(x+1,y-1);
    if(s[x]!='?' && s[y]!='?')return dp[x][y]=(1<<20);
    dp[x][y]=0;
    if(s[x]!='?')dp[x][y]|=(1<<(s[x]-'a'));
    if(s[y]!='?')dp[x][y]|=(1<<(s[y]-'a'));
    dp[x][y]|=go(x+1,y-1);
    return dp[x][y];

}
int cal(int x,int y)
{
    if(x>y)return 0;
    if(x==y)
    {
        if(s[x]=='?')return 1;
        else return 0;
    }
    if(num[x][y]!=-1)return num[x][y];
    num[x][y]=cal(x+1,y-1);
    if(s[x]=='?' && s[y]=='?')num[x][y]++;
    return num[x][y];
}
int  sos[18][(1<<18)];
int tot;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof dp);
    memset(num,-1,sizeof num);
    for(int i=1;i<18;i++)
    {
        pw[i][0]=1;
        for(int j=1;j<=1000;j++)pw[i][j]=(pw[i][j-1]*1LL*i)%mod;
    }
    cin>>n>>s;
    for(int i=0;i<n;i++)
        if(s[i]=='?')tot++;
    int cur=0;

    for(int i=0;i<n;i++)
    {
        cur=0;
       for(int j=i;j<n;j++)
    {
        if(s[j]=='?')cur++;
        int g=go(i,j);
        if(g&(1<<20))continue;
        int h=tot-cur+cal(i,j);
        for(int d=1;d<18;d++)sos[d][g]=(sos[d][g]+pw[d][h])%mod;
    }
    }
        for(int k=0;k<17;k++)
            for(int i=0;i<(1<<17);i++)
            if(i&(1<<k))
            for(int r=1;r<18;r++)
            sos[r][i]=(sos[r][i]+sos[r][i^(1<<k)])%mod;

    int q;
    cin>>q;
    while(q--)
    {
        string x;
        cin>>x;
        int msk=0,u=x.size();
        for(int i=0;i<u;i++)msk|=(1<<(x[i]-'a'));
        cout<<sos[u][msk]<<endl;
    }

    return 0;
}