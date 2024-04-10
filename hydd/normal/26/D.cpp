#include<cstdio>
using namespace std;
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	long double ans1=1,ans2=1;
	for (int i=m-k;i<=m;i++) ans1*=i;
	for (int i=n+1;i<=n+k+1;i++) ans2*=i;
	if (ans1>ans2) puts("0.00000000");
	else{
		double ans=(ans2-ans1)/ans2;
		printf("%.8lf\n",ans);
	}
	return 0;
}