#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long double a[1010][1010],b[1010],c[1010];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){int k; scanf("%d",&k); a[i][k]=1;}
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		memcpy(b,a[k1],sizeof a[k1]);
		memcpy(c,a[k2],sizeof a[k2]);
		for (int i=1;i<=n;i++) a[k1][i]=a[k1][i]/2.0+c[i]/2.0;
		for (int i=1;i<=n;i++) a[k2][i]=a[k2][i]/2.0+b[i]/2.0;
	}
	long double ans=0; memset(b,0x00,sizeof b);
	for (int i=1;i<=n;i++){
		double now=0;
		for (int j=n;j;j--){ans+=now*a[i][j]; now+=b[j];}
		for (int j=1;j<=n;j++) ans+=b[j]*a[i][j]/2.0;
		for (int j=1;j<=n;j++) b[j]+=a[i][j];
	}
	printf("%.11lf\n",(double)ans); return 0;
}