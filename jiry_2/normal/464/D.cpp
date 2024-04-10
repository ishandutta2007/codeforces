#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k;
double dp[700];
int main(){
    scanf("%d%d",&n,&k); double k1=(k-1)/(double)k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=600;j++)
            dp[j]=dp[j]*k1+(dp[j]*j/(j+1)+1.0*j/2+dp[j+1]/(j+1)+1.0*j/(j+1))/k;
    printf("%.11f\n",dp[1]*k); return 0;
}