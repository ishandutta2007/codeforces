#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1100],n,d,mo,num[1100][11],A[1100],w[11],B[11][11],nI[11];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int main(){
	scanf("%d%d%d",&n,&d,&mo);
	nI[0]=1; for (int i=1;i<=d;i++) nI[i]=1ll*nI[i-1]*quick(i,mo-2)%mo;
	dp[1]=1; num[1][0]=1; B[0][0]=1;
	for (int i=1;i<=d;i++)
		for (int j=1;j<=i;j++)
			for (int k=1;k<=i;k++)
				B[i][j]=(B[i][j]+B[i-k][j-1])%mo;
	for (int i=1;i<=n/2;i++){
		dp[i]=num[i][d-1]; int pre=1;
		if (i==1) dp[i]++;
		if (i*2==n) continue;
		if (dp[i]==0) continue;
		memset(w,0x00,sizeof w);
		for (int j=1;j<=d;j++){
			pre=1ll*pre*(dp[i]-j+1)%mo;
			for (int k=j;k<=d;k++)
				w[k]=(w[k]+1ll*pre*nI[j]%mo*B[k][j])%mo;
		}
		for (int a=d;a;a--){
			for (int b=1,si=i;b<=a;b++,si+=i)
				for (int k=si+1;k<=n;k++)
					num[k][a]=(num[k][a]+1ll*w[b]*num[k-si][a-b])%mo;
		}
	}
	int ans=0;
	if (n%2==0) ans=1ll*dp[n/2]*(dp[n/2]+1)%mo*nI[2]%mo;
	ans=(ans+num[n][d])%mo;
	if (n==1) ans=(ans+1)%mo;
	cout<<(ans+mo)%mo<<endl;
	return 0;
}