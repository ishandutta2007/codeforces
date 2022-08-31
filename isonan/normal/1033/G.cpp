#include <cstdio>
#include <algorithm>

int n,m;
long long a[101],wf,ws;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=2;i<=(m<<1);i++){
		int l=1,r=std::min(m,(i-1)>>1);
		l=std::max(l,i-m);
		r=std::min(r,i-1);
		bool par=0;
		int mx=-1;
		int nl=l,nr=r;
		for(int j=1;j<=n;j++){
			int x=a[j]%i;
			if(mx<x)mx=x;
			nl=std::max(nl,std::min(x+1,i-x));
			if(((x+1)<<1)<i)nl=std::max(nl,x+1);
			else nl=std::max(nl,std::max(i-x,(x+2)>>1)),par^=1;
		}
		(par?wf:ws)+=2ll*std::max(nr-nl+1,0);
		par=0;
		nl=l,nr=r;
		for(int j=1;j<=n;j++){
			int x=a[j]%i;
			nl=std::max(nl,std::min(x+1,i-x));
			if(mx==x){
				mx=-1;
				nr=std::min(nr,x>>1);
			}
			else if(((x+1)<<1)<i)nl=std::max(nl,x+1);
			else nl=std::max(nl,std::max(i-x,(x+2)>>1)),par^=1;
		}
		if(!par)wf+=2ll*std::max(nr-nl+1,0);
		par=0;
//		printf("%d %d\n",i,wf);
		if(i&1)continue;
		for(int j=1;j<=n;j++)par^=((a[j]/(i>>1))&1);
		++(par?wf:ws);
	}
	long long x=(1ll*m*m-wf-ws)>>1ll;
	printf("%lld %lld %lld %lld\n",x,x,wf,ws);
}