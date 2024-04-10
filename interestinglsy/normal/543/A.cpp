/*
codeforces-543A
nmia[i]bugbugb
[DP]
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#define maxxx 509
using namespace std;

int n,m,b;
long long i,j,k,mod;
int a[maxxx];
long long dp[maxxx][maxxx];

int main(){
	//freopen("input-543A.txt","r",stdin);
	memset(dp,0,sizeof(dp));
	n=m=b=i=j=k=mod=0;
	scanf("%d%d%d%I64d",&n,&m,&b,&mod);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
   	for(i=0;i<=b;i++)dp[0][i]=1;

   	
   	for(k=1;k<=n;k++)
        for(i=1;i<=m;i++)
            for(j=a[k];j<=b;j++)
                dp[i][j]=(dp[i-1][j-a[k]] + dp[i][j]) % mod;
                
                
	cout<<dp[m][b]%mod<<endl;
	
	
	return 0;
}