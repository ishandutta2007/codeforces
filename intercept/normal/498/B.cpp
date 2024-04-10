#include<bits/stdc++.h>
using namespace std;
const int M=5009;
int n,m;
int t[M];
double ans,dp[M][M],p[M];
double kpow(double x,int y,double rex=1){
	for(;y;y>>=1,x=x*x)if(y&1)rex=x*rex;
	return rex;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lf%d",&p[i],&t[i]);
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		p[i]/=100;
		double x=kpow(1-p[i],t[i]-1),now=dp[i-1][0];
		for(int j=1;j<=m;++j){
			if(j>=t[i])now-=dp[i][j]=dp[i-1][j-t[i]]*x;
			dp[i][j]+=now*p[i];
			now*=1-p[i];
			now+=dp[i-1][j];
			ans+=dp[i][j];
		}
	}
	printf("%.8lf\n",ans);
	return 0;
}