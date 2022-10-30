#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=151;
ll cnt,lx,rx,pp,qq,val,maxn;
ll dp[MAXN][MAXN][5][5];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
int main()
{
    cnt=read();
    memset(dp,-63,sizeof(dp));
    for(register int i=1;i<=cnt;i++)
    {
        lx=read(),val=read(),rx=read();
        dp[i][i][lx][rx]=dp[i][i][rx][lx]=val;
    }
    for(register int i=cnt;i;i--)
    {
        for(register int j=i;j<=cnt;j++)
        {
            for(register int l=1;l<=4;l++)
            {
                for(register int r=1;r<=4;r++)
                {
                    for(register int k=i;k<=j+1;k++)
                    {
                        dp[i][j][l][r]=max(dp[i][j][l][r],dp[i][k][l][r]);
                        dp[i][j][l][r]=max(dp[i][j][l][r],dp[k+1][j][l][r]);
                        for(register int p=1;p<=4;p++)
                        {
                            pp=dp[i][k][p][r]+dp[k+1][j][l][p];
                            qq=dp[k+1][j][p][r]+dp[i][k][l][p];
                            dp[i][j][l][r]=max(dp[i][j][l][r],max(pp,qq));
                        }
                    }
                    maxn=max(maxn,dp[i][j][l][r]);
                }
            }
        }
    }
    printf("%d\n",maxn);
}