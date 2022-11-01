#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=505,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,m,nex[N],nexval[N][2];
char s[N],t[N];
int dp[N][N][N];
void update(int &x,int y){if(y<x)x=y;}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s%s",s+1,t+1);
    nex[0]=-1;
    nexval[0][t[1]-'0']=1;
    for(int i=1;i<=m;i++)
    {
        int k=nex[i-1];
        while(k!=-1&&t[k+1]!=t[i]) k=nex[k];
        nex[i]=++k;
        k=i;
        while(k!=-1)
        {
            if(k+1<=m)
            {
                if(t[k+1]=='0'&&!nexval[i][0]) nexval[i][0]=k+1;
                if(t[k+1]=='1'&&!nexval[i][1]) nexval[i][1]=k+1;
            }
            k=nex[k];
        }
        // cout<<i<<' '<<nexval[i][0]<<' '<<nexval[i][1]<<endl;
    }
    memset(dp,inf,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=n-m+1;j++)
        for(int k=0;k<=m;k++)
        if(dp[i][j][k]!=inf)
        {
            update(dp[i+1][j+(nexval[k][0]==m)][nexval[k][0]],dp[i][j][k]+(s[i+1]!='0'));
            update(dp[i+1][j+(nexval[k][1]==m)][nexval[k][1]],dp[i][j][k]+(s[i+1]!='1'));
        }
    for(int i=0;i<=n-m+1;i++)
    {
        int ans=inf;
        for(int k=0;k<=m;k++)
            ans=min(ans,dp[n][i][k]);
        if(ans==inf) ans=-1;
        printf(i==n-m+1?"%d\n":"%d ",ans);
    }
}