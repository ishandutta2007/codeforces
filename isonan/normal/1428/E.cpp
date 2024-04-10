#include <cstdio>
#include <queue>
#include <cassert>
#define int long long

std::priority_queue<std::pair<long long,int> >heap;
int n,k,a[100001],c[100001],now[100001];
long long ans;
long long cost(int a,int b){
	int x=a%b;
//	printf("cost %lld %lld=%lld\n",a,b,1ll*x*((a+b-1)/b)*((a+b-1)/b)+1ll*(b-x)*(a/b)*(a/b));
	return 1ll*x*((a+b-1)/b)*((a+b-1)/b)+1ll*(b-x)*(a/b)*(a/b);
}
signed main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		ans+=1ll*a[i]*a[i];
		now[i]=1;
		if(a[i]>1){
			c[i]=cost(a[i],1)-cost(a[i],2);
			heap.push(std::make_pair(c[i],i));
		}
	}
	for(int i=n;i<k;i++){
		int x=heap.top().second;
//		printf("%d %d\n",x,c[x]);
		heap.pop();
		++now[x];
		ans-=c[x];
		if(a[x]>now[x]){
			c[x]=cost(a[x],now[x])-cost(a[x],now[x]+1);
			heap.push(std::make_pair(c[x],x));
		}
	}
	printf("%lld\n",ans);
}