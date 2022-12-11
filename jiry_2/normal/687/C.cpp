#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[510][510];
int n,K,A[510];
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	dp[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=K;j>=A[i];j--)
			for (int k=K;k>=0;k--){
				dp[j][k]|=dp[j-A[i]][k];
				if (k>=A[i]) dp[j][k]|=dp[j-A[i]][k-A[i]];
			}
	}
	int now=0;
	for (int i=0;i<=K;i++) if (dp[K][i]) now++;
	printf("%d\n",now);
	for (int i=0;i<=K;i++) if (dp[K][i]){
		printf("%d ",i);
	}
	printf("\n");
}