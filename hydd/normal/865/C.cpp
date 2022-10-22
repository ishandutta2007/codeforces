#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[55],b[55],p[55];
double dp[55][5500];
bool check(double k){
	for (int i=n;i>=1;i--){
		for (int j=m+1;j<=5100;j++) dp[i+1][j]=k;
		for (int j=0;j<=m;j++)
			dp[i][j]=min((dp[i+1][j+a[i]]+a[i])*p[i]/100+(dp[i+1][j+b[i]]+b[i])*(100-p[i])/100,k);
	}
	return dp[1][0]<k;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&p[i]);
	double l=0,r=1e9,mid;
	for (int i=1;i<=100;i++){
		mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%.12lf\n",r);
	return 0;
}