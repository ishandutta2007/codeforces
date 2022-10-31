#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,q;
ll res,a[5050],x;
ll dp[5050][5050],sum[5050];

int main(){
	scanf("%d%d%d",&n,&k,&q);
	k++;
	for(i=1;i<=n;i++){
		dp[k][i]=1;
	}
	for(i=k-1;i>=1;i--){
		for(j=1;j<=n;j++){
			dp[i][j]=(dp[i+1][j-1]+dp[i+1][j+1])%M;
		}
	}
	
	for(i=1;i<=k;i++){
		for(j=1;j<=n;j++){
			sum[j]=(sum[j]+dp[i][j]*dp[k+1-i][j])%M;
		}
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		res=(res+sum[i]*a[i])%M;
	}
	
	while(q--){
		scanf("%d%lld",&j,&x);
		res=(res-(a[j]-x)*sum[j])%M;
		res=(res+M)%M;
		a[j]=x;
		printf("%lld\n",res);
	}
}