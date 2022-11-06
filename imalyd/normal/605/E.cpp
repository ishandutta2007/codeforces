#include<bits/stdc++.h>
using namespace std;
#define db double
const int N=1005;
int n,v[N];
db p[N][N],a[N],b[N],f[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lf",&p[i][j]),p[i][j]/=100;
	for(int i=1;i<n;i++)a[i]=b[i]=1,f[i]=1e30;
	for(int i=1;i<=n;i++){
		int mn=1;
		while(v[mn])mn++;
		for(int j=mn;j<=n;j++)if(!v[j]&&f[j]<f[mn])mn=j;
		v[mn]=1;//printf("%d %lf\n",mn,f[mn]);
		for(int j=1;j<=n;j++)if(!v[j]){
			a[j]+=f[mn]*p[j][mn]*b[j],b[j]*=1-p[j][mn];
			if(b[j]!=1)f[j]=a[j]/(1-b[j]);
		}
	}
	printf("%.15lf",f[1]);
	return 0;
}