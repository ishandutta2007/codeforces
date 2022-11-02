#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=5e3+5;
int dp[maxn][maxn];
int a[maxn],n;
int main(){
    int i,j,n,m;
    scanf("%d",&m);
    scanf("%d",&a[1]); n=1;
    for (i=1;i<m;i++){
        scanf("%d",&a[n+1]);
        if (a[n]!=a[n+1]) n++;
    }
    for (i=0;i<n;i++) for (j=1;j<=n-i;j++){
        if (j>1) dp[j-1][j+i]=max(dp[j-1][j+i],dp[j][j+i]);
        if (j+i<n) dp[j][j+i+1]=max(dp[j][j+i+1],dp[j][j+i]);
        if (j>1&&j+i<n&&a[j-1]==a[j+i+1])
            dp[j-1][j+i+1]=max(dp[j-1][j+i+1],dp[j][j+i]+1);
    }
    printf("%d\n",n-dp[1][n]-1);
    return 0;
}