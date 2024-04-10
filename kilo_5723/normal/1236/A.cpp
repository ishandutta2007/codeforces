#include<iostream>
#include<cstdio>
using namespace std;
const int n=105;
int dp[n][n][n];
int main(){
    int tt;
    int i,j,k;
    int a,b,c;
    for (i=0;i<n;i++) for (j=0;j<n;j++) for (k=0;k<n;k++){
        if (i>0&&j>1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-2][k]+3);
        if (j>0&&k>1) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-2]+3);
    }
    scanf("%d",&tt);
    while (tt--){
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",dp[a][b][c]);
    }
    return 0;
}