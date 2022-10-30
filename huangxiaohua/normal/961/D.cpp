#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,used[200500];
ll x[200500],y[200500],xx,yy,dx,dy,dx1,dy1;
int main(){
	long c=clock();
	srand(time(0));
	scanf("%d",&n);
	if(n<=4){puts("YES");return 0;}
	mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count()+1);
	uniform_int_distribution<int>lim(1,n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	while(clock()-c<=1800){
		memset(used,0,n*4+50);
		xx=lim(rd);yy=lim(rd);
		while(xx==yy){xx=lim(rd);yy=lim(rd);}
		used[xx]=used[yy]=1;
		dx=x[yy]-x[xx];dy=y[yy]-y[xx];
		for(i=1;i<=n;i++){
			dx1=x[i]-x[xx];dy1=y[i]-y[xx];
			if(!dx){
				if(!dx1){used[i]=1;}continue;
			}
			if(!dy){
				if(!dy1){used[i]=1;}continue;
			}
			if(dx*dy1==dy*dx1){used[i]=1;}
		}
		xx=yy=dx=dy=0;
		for(i=1;i<=n;i++){
			if(used[i]){continue;}
			if(!xx){xx=i;used[i]=1;continue;}
			if(!yy){
				yy=i;used[i]=1;
				dx=x[yy]-x[xx];dy=y[yy]-y[xx];continue;
			}
			dx1=x[i]-x[xx];dy1=y[i]-y[xx];
			if(!dx){
				if(!dx1){used[i]=1;}continue;
			}
			if(!dy){
				if(!dy1){used[i]=1;}continue;
			}
			if(dx*dy1==dy*dx1){used[i]=1;}
		}
		for(i=1;i<=n;i++){
			if(!used[i]){goto aaa;}
		}
		puts("YES");return 0;
		aaa:;
	}
	puts("NO");
}