#include<cstdio>
#include<cstring>
const double EPS=1e-50;
double dp[605];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	dp[1]=1;
	double ans=0;
	for(int i=1;i<=n;++i){
		for(int j=600;j;--j){
			double v=dp[j]<EPS?0:dp[j],u=1.0/k/(j+1.0);
			ans+=v*(j/2.0+j/(j+1.0));
			dp[j+1]+=v*u;dp[j]=v*(1.0-u);
		}
	}
	printf("%.10f\n",ans);
	return 0;
}