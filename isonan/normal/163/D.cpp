#include <algorithm>
#include <cstdio>
#include <cmath>

int t,k;
long long p[21],a[21],now[21],V,ans,A,b,c,ta,lim,tem;
int cnt;
void dfs2(int x,long long st){
	if(st>lim)return;
	tem=std::max(tem,st);
	if(x>k)return;
	if(st*p[x]>lim)return;
	for(int i=0;i+now[x]<=a[x];++i){
		dfs2(x+1,st);
		st*=p[x];
		if(st>lim)return;
	}
}
void dfs1(int x,long long st){
	if(st>1000000ll||st*st*st>V)return;
	if(x>k){
		ta=st;
		lim=floor(sqrt(V/ta));
		while(lim*lim>(V/ta))--lim;
		while((lim+1)*(lim+1)<=(V/ta))++lim;
//		printf("%lld %lld\n",ta,lim);
		if(4ll*st*(lim)+2ll*(lim)*(lim)>=ans)return;
		tem=0;
		dfs2(1,1);
//		printf("%lld\n",tem);
		long long v=2ll*(ta*tem+(ta+tem)*(V/(ta*tem)));
		if(ans>v){
			ans=v;
			A=ta;
			b=tem;
			c=V/(ta*tem);
		}
		return;
	}
	for(int i=0;i<=a[x];++i){
		now[x]=i;
		dfs1(x+1,st),st*=p[x];
	}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&k);
		V=1;
		for(int i=1;i<=k;i++){
			scanf("%lld%lld",p+i,a+i);
			for(int j=1;j<=a[i];j++)V*=p[i];
		}
		for(int i=1;i<=k;i++)
			for(int j=1;j<k;j++)
				if(p[j]>p[j+1])std::swap(p[j],p[j+1]),std::swap(a[j],a[j+1]);
		ans=6*V;
		dfs1(1,1);
		printf("%lld %lld %lld %lld\n",ans,A,b,c);
	}
}