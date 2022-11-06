#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef double ld;
const int N=1010;
ld f[N],c[N];
int a[N][N],n;
int d[N],l,r,vis[N];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
		c[i]=1;
	}
	d[++r]=n;vis[n]=1;
	for (int i=1;i<=n;i++){
		int x=d[i],z=0;
		ld nx=1e20;
		for (int j=1;j<=n;j++){
			if (vis[j])continue;
			f[j]+=f[x]*c[j]*a[j][x]*0.01;
			c[j]*=1-a[j][x]*0.01;
			if ((f[j]+1)/(1-c[j])<nx)nx=(f[j]+1)/(1-c[j]),z=j;
		}
		f[z]=(f[z]+1)/(1-c[z]);
		d[++r]=z;
		vis[z]=1;
	}
	printf("%.12lf\n",f[1]);
}