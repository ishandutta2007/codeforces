#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 1000050
using namespace std;
int dp[N],f[N][12];
int calc(int x){
	int re=1,y;
	while(x){
		y=x%10;x/=10;
		if(y) re=re*y;
	}
	return re;
}
int main(){
	for(int i=1;i<=1000000;i++){
		if(i<10) dp[i]=i;
		else dp[i]=dp[calc(i)];
		for(int j=1;j<=9;j++) f[i][j]=f[i-1][j];
		f[i][dp[i]]++;
	}
	int t,l,r,k,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&l,&r,&k);
		ans=f[r][k]-f[l-1][k];
		printf("%d\n",ans);
	}
	return 0;
}