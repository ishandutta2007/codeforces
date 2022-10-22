#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k;
long double lnfac[110000];
long double lnC(int n,int m){ return lnfac[n]-lnfac[m]-lnfac[n-m];}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++) lnfac[i]=lnfac[i-1]+log(i);
	long double ans=0;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++){
			int num=(i+j)*n-i*j;
			if (num<=k){
				long double lntmp=lnC(n,i)+lnC(n,j)+lnC(m-num,k-num)-lnC(m,k);
				ans+=exp(lntmp); if (ans>1e99){ ans=1e99; break;}
			}
		}
	printf("%.12lf\n",(double)ans);
	return 0;
}