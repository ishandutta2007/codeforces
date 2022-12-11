#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[2][152][12000];
int n,t,k,p[152];
int main(){
    scanf("%d%d%d",&n,&k,&t);
    for (int i=1;i<=n;i++) scanf("%d",&p[i]);
    t=min(t,n*(n-1)/2);// cout<<t<<endl;
    memset(dp,0x3f,sizeof dp); int now=0;
    dp[0][0][0]=0; int lim=1e9;
    for (int i=1;i<=n;i++){
        memcpy(dp[now^1],dp[now],sizeof dp[now]);
        for (int j=0;j<i;j++)
            for (int k=0;k<=t;k++)
                if (dp[now][j][k]<lim)
                    dp[now^1][j+1][k+i-j-1]=min(dp[now^1][j+1][k+i-j-1],dp[now][j][k]+p[i]);
        now^=1;
    }
    int ans=lim;
    for (int i=0;i<=t;i++) ans=min(ans,dp[now][k][i]);
    printf("%d\n",ans);
}