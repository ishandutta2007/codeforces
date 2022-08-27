#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef double db;
typedef long long ll;
int n;
int x[100005],y[100005];
db ans=0;
#define N 1000000
db x1[2000005],x2[2000005];
int cnt[2000005];
void work(){
	int mi=1000000000,ma=-1000000000;
	for (int i=0;i<=2000000;i++)x1[i]=ma,x2[i]=mi;
	for (int i=1;i<=n;i++){
		int ux=x[i],uy=y[i],vx=x[i+1>n?1:i+1],vy=y[i+1>n?1:i+1];
		mi=min(mi,ux);
		ma=max(ma,ux);
		if(ux==vx){
				x1[ux+N]=max(1.0*max(uy,vy),x1[ux+N]);
				x2[ux+N]=min(1.0*min(uy,vy),x2[ux+N]);
		}else{
			if(ux>vx)swap(ux,vx),swap(uy,vy);
			for (int i=ux;i<=vx;i++){
				db y=1.0*(vy-uy)/(vx-ux)*(i-ux)+uy;
				x1[i+N]=max(x1[i+N],y);
				x2[i+N]=min(x2[i+N],y);
			}
		}
	}
	ll tot=0;
	for (int i=mi;i<=ma;i++){	
		int down=int(x2[i+N]+N-(1e-5))+1-N;
		int up=int(x1[i+N]+N)-N;
		tot+=(cnt[i-mi]=up-down+1);
	}
	db sum=0;
	db s1=0,s2=0,s3=0;
	for (int i=0;i<=ma-mi;i++){
		sum+=1.0*cnt[i]*(1.0*i*i*s1-2.0*i*s2+s3);
		s1+=cnt[i];
		s2+=1.0*i*cnt[i];
		s3+=1.0*i*i*cnt[i];
	}
	sum/=(1.0*tot*(tot-1)/2);
	ans+=sum;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	work();
	for (int i=1;i<=n;i++)swap(x[i],y[i]);
	work();
	printf("%.10lf\n",ans/2.0);
	return 0;
}