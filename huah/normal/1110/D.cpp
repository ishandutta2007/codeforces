#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[1000005];
long long dp[1000005][3][3];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&x),a[x]++;
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=m;i++)
        for(int x=0;x<3;x++)
            for(int y=0;y<3;y++)
                for(int z=0;z<3;z++)
    {
        if(a[i]<x+y+z) continue;
        dp[i][x][y]=max(dp[i][x][y],dp[i-1][z][x]+(a[i]-x-y-z)/3+z);
    }
    cout<<dp[m][0][0]<<endl;
}