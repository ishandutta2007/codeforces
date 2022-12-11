#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=75,lim=5e8;
int dp[3000][N*2][N],A[5000],n,L[5000],R[5000];
int find(int k1,int k2,int k3){
	if (dp[k1][k2][k3]<lim) return dp[k1][k2][k3];
	int &ans=dp[k1][k2][k3];
	if (k1+k1+k2+k3-N>n){
		ans=L[k1]-R[k1+k2-N]; return ans;
	}
	ans=-1e9;
	for (int i=k3;i<=k3+1;i++){
		if (k1+k1+k2-N+i>n) continue;
		int num=lim;
		for (int j=i;j<=i+1;j++)
			if (k1+k1+i+j+k2-N<=n)
				num=min(num,find(k1+i,k2+j-i,j));
		if (num==lim) num=L[k1+i]-R[k1+k2-N];
	//	cout<<"asd "<<k1<<" "<<k2-N<<" "<<k3<<" "<<i<<" "<<num<<endl;
		ans=max(ans,num);
	}
//	cout<<k1<<" "<<k2-N<<" "<<k3<<" "<<ans<<endl; 
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++) L[i]=L[i-1]+A[i];
	for (int i=n;i;i--) R[n-i+1]=R[n-i]+A[i];
	memset(dp,0x3f,sizeof dp);
	printf("%d\n",find(0,N,1));
	return 0;
}