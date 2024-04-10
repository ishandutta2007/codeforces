#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,a,b,m1,m2;
ll dp[5050][5050],sb[400050],tmp1,tmp2;
int main(){
	memset(dp,63,sizeof(dp));
	scanf("%d%d",&n,&m);
	a=n/m;b=a+1;
	m2=n%m;m1=m-m2;
	for(i=1;i<=n;i++){
		scanf("%lld",&sb[i]);
	}
	sort(sb+1,sb+n+1);
	for(i=0;i<=m1;i++){
		for(j=0;j<=m2;j++){
			if(!i&&!j){dp[0][0]=0;continue;}
			tmp1=tmp2=1e17;
			if(i){tmp1=dp[i-1][j]+sb[(i-1)*a+j*b+a]-sb[(i-1)*a+j*b+1];}
			if(j){tmp2=dp[i][j-1]+sb[i*a+(j-1)*b+b]-sb[i*a+(j-1)*b+1];}
			dp[i][j]=min(tmp1,tmp2);
		}
	}
	printf("%lld",dp[m1][m2]);
}