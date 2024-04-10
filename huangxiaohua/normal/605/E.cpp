#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,id;
int vis[1050];
double a[1050][1050],f[1050],p[1050],mn;

int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%lf",&a[i][j]),a[i][j]/=100;
	for(i=1;i<n;i++)f[i]=p[i]=1;
	for(t=1;t<=n;t++){
		if(t==1){id=n;goto aaa;}
		mn=1e9;
		for(i=1;i<=n;i++){
			if(vis[i])continue;
			if((f[i]/(1-p[i]))<mn){mn=f[i]/(1-p[i]);id=i;}
		}
		f[id]/=(1-p[id]);
		aaa:vis[id]=1;
		for(i=1;i<=n;i++){
			if(vis[i])continue;
			f[i]+=p[i]*f[id]*a[i][id];
			p[i]*=(1-a[i][id]);
		}
		if(id==1){printf("%.20lf",f[1]);return 0;}
	}
	return 1;
}