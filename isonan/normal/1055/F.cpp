#include <cstdio>
#include <algorithm>

int n,L[1000010],R[1000010],nxt[1000010];
long long val[1000010],w,k;
long long a[1000010];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=2,p;i<=n;i++){
		scanf("%d%lld",&p,&w);
		a[i]=val[i]=val[p]^w;
	}
	for(int i=1;i<=n;i++)L[i]=1,R[i]=n;
	std::sort(val+1,val+n+1);
	long long ans=0;
//	for(int j=1;j<=n;j++)printf("%lld ",val[j]);putchar('\n');
	for(long long i=61;~i;--i){
//		for(int j=1;j<=n;j++)printf("%lld(%d %d)",a[j],L[j],R[j]);putchar('\n');
		nxt[n+1]=n+1;
		for(int j=n;j;j--)
			nxt[j]=(val[j]&(1ll<<i))?j:nxt[j+1];
		long long sum=0;
		for(int j=1;j<=n;j++)
			if(L[j]<=R[j]){
				if(a[j]&(1ll<<i))sum+=std::max(R[j]-nxt[L[j]]+1,0);
				else sum+=std::min(nxt[L[j]]-L[j],R[j]-L[j]+1);
			}
		if(sum>=k){
			for(int j=1;j<=n;j++)
				if(L[j]<=R[j]){
					if(a[j]&(1ll<<i))L[j]=nxt[L[j]];
					else R[j]=std::min(R[j],nxt[L[j]]-1);
				}
		}
		else{
			k-=sum;
			ans|=1ll<<i;
			for(int j=1;j<=n;j++)
				if(L[j]<=R[j]){
					if(a[j]&(1ll<<i))R[j]=std::min(R[j],nxt[L[j]]-1);
					else L[j]=nxt[L[j]];
				}
		}
	}
	printf("%lld\n",ans);
}