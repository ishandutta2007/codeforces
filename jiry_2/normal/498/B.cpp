#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,T,x[6000],t[6000];
long double dp[2][6000];
int main(){
    scanf("%d%d",&n,&T);
    for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&t[i]);
    memset(dp,0x00,sizeof dp); dp[0][0]=1;
    long double ans=0; int k=0;
    for (int i=1;i<=n;i++){
        memset(dp[k^1],0x00,sizeof dp[k^1]);
        long double now=dp[k][0],k1=1;
        for (int j=1;j<t[i];j++) k1=k1*(100-x[i])/100.0;
        for (int j=1;j<=T;j++){
            if (j>=t[i]){
                dp[k^1][j]+=k1*dp[k][j-t[i]]; now-=k1*dp[k][j-t[i]];
            }
            dp[k^1][j]+=now*(x[i])/100.0;
            now=now*(100-x[i])/100.0+dp[k][j];
        }
        ans+=now*(i-1); k^=1;
    }
    for (int i=1;i<=T;i++) ans+=dp[k][i]*n;
    printf("%.11lf\n",(double)ans); return 0;
}