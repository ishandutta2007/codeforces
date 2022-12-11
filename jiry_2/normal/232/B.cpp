#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int C[111][110],mo=1e9+7,n,dp[110][11000],K,A[110];
long long m;
int quick(int k1,long long k2){
    int k3=1;
    while (k2){
        if (k2&1) k3=1ll*k3*k1%mo; k1=1ll*k1*k1%mo; k2>>=1;
    }
    return k3;
}
int main(){
    scanf("%d%I64d%d",&n,&m,&K);
    for (int i=0;i<=n;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
    }
    dp[0][0]=1;
    for (int i=1;i<=n;i++){
        long long k1=(m-i)/n+1;
        for (int j=0;j<=n;j++) A[j]=quick(C[n][j],k1);
        for (int j=0;j<=n;j++)
            for (int k=j;k<=K;k++)
                dp[i][k]=(dp[i][k]+1ll*dp[i-1][k-j]*A[j])%mo;
    }
    printf("%d\n",dp[n][K]);
    return 0;
}