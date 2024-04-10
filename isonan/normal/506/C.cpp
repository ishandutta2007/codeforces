#include <cstdio>
#include <queue>

int n,m,k;
long long h[100001],a[100001],p;
long long now[100001];
std::priority_queue<std::pair<int,int> >h1;
bool judge(long long x){
	long long req=0;
	while(!h1.empty())h1.pop();
	for(int i=1;i<=n;i++){
		now[i]=x-a[i]*m;
		if(now[i]<h[i])req+=(h[i]-now[i]+p-1)/p;
		if(now[i]<0)h1.push(std::make_pair((-now[i]+a[i]-1)/a[i],i));
	}
	if(req>k*m)return 0;
	for(int i=m;i;i--){
		for(int j=1;j<=k;j++){
			if(h1.empty())return 1;
			if(h1.top().first>=i)return 0;
			int x=h1.top().second;
			h1.pop();
			now[x]+=p;
			if(now[x]<0)h1.push(std::make_pair((-now[x]+a[x]-1)/a[x],x));
		}
	}
	return h1.empty();
}
int main(){
	scanf("%d%d%d%I64d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)scanf("%I64d%I64d",h+i,a+i);
	long long l=0,r=2000000000000000ll,mid,ans=-1ll;
	while(l<=r){
		mid=(l+r)>>1ll;
		if(judge(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%I64d",ans);
}