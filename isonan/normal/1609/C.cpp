#include <cstdio>

int t,a[200001],n,e,pre[200001],nxt[200001];
bool pri[1000001];
int main(){
	scanf("%d",&t);
	pri[1]=1;
	for(int i=2;i<=1000000;++i){
		if(!pri[i]){
			for(int j=i+i;j<=1000000;j+=i)pri[j]=1;
		}
	}
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&e);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		// for(int i=1;i<=n;++i)printf("%d ",pri[a[i]]);putchar('\n');
		long long ans=0;
		for(int i=1;i<=n;++i){
			if(i<=e)pre[i]=(a[i]==1);
			else if(a[i]==1)pre[i]=pre[i-e]+1;
			else pre[i]=0;
		}
		for(int i=n;i;--i){
			if(i+e>n)nxt[i]=(a[i]==1);
			else if(a[i]==1)nxt[i]=nxt[i+e]+1;
			else nxt[i]=0;
		}
		for(int i=1;i<=e;++i){
			int Now=0,last=-1;
			for(int j=i;j<=n;j+=e)
				if(!pri[a[j]]){
					int l=0,r=0;
					if(j<=e)l=1;
					else l=pre[j-e]+1;
					if(j+e>n)r=1;
					else r=nxt[j+e]+1;
					// printf("%d %d %d\n",j,l,r);
					ans+=1ll*l*r-1ll;
				}
		}
		printf("%lld\n",ans);
	}
}