#include<bits/stdc++.h>
using namespace std;
int n; double h[3100],r[3100],R[3100],k[3100],dp[3100];
double calc(int x,int y){
	if (R[x]<=r[y]) return dp[x]+h[y];
	if (R[y]<=r[x]) return dp[x]-h[x]+h[y];
	 
	double res=dp[x]-h[x]+h[y],d;
	
//	r[x]+k[x]*d==r[y]
	d=(r[y]-r[x])/k[x];
	res=max(res,dp[x]-h[x]+d+h[y]);
	
//	r[y]+k[y]*d==R[x]
	d=(R[x]-r[y])/k[y];
	if (R[y]>=R[x]) res=max(res,dp[x]-d+h[y]);
	
//	r[x]+k[x]*d==R[y]
	d=(R[y]-r[x])/k[x];
	if (R[x]>=R[y]) res=max(res,dp[x]-h[x]+d);
	return res;
}
int main(){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&h[i],&r[i],&R[i]);
		k[i]=(R[i]-r[i])/h[i];
	}
	dp[1]=h[1]; double ans=dp[1];
	for (int i=2;i<=n;i++){
		for (int j=1;j<i;j++)
			dp[i]=max(dp[i],calc(j,i));
		ans=max(ans,dp[i]);
	}
	printf("%.8lf\n",ans);
	return 0;
}