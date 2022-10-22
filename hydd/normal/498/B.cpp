#include<cstdio>
#include<cmath>
using namespace std;
int n,T,t[5100];
double p[5100],f[5100][5100];
int main(){
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++){
		scanf("%lf%d",&p[i],&t[i]);
		p[i]/=100;
	}
	f[0][0]=1; double ans=0;
	for (int i=1;i<=n;i++){
		double sum=0,tmp=pow(1-p[i],t[i]-1);
		for (int j=1;j<=T;j++){
			sum*=(1-p[i]);
			sum+=f[i-1][j-1]*p[i];
			if (j>=t[i]){
				sum-=f[i-1][j-t[i]]*tmp*p[i];
				f[i][j]+=f[i-1][j-t[i]]*tmp;
			}
			f[i][j]+=sum;
			ans+=f[i][j];
		}
	}
	printf("%.12lf\n",ans);
	return 0;
}