#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10000;
double dp[1100],w[110000],A[1100];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++) A[i]=1.0*i/n;
	dp[0]=2000;
	for (int i=1;i<=N;i++){
		for (int j=n;j;j--)
			dp[j]=dp[j]*A[j]+dp[j-1]*A[n-j+1];
		dp[0]=0;
		w[i]=dp[n];
	}
	for (;m;m--){
		int k1; scanf("%d",&k1);
		int l=1,r=N+1,ans=0;
		while (l<r){
			int mid=l+r>>1;
			if (w[mid]>k1-1e-7){
				ans=mid; r=mid;
			} else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}