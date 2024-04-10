#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,it,b[500500];
ll a[500500],sum,res,dp[105][105],res2,tmp,tmp2;
int main(){
	memset(dp,1,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);b[i]*=-1;
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++){
		b[i]*=-1;
		if(sum>=0){res+=sum;}
		sum+=b[i];
		if(it){a[++it]=b[i];}
		if(!it&&sum<0){a[++it]=sum;}
	}
	n=it;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		res+=(i-1)/(m+1)*a[i];
	}
	printf("%lld",res);
}