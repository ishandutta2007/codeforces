#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>

long long n,m,head[500001],nxt[1000001],b[1000001],T,k,u,v,val[500001],stat[500001],stat2[500001],d[500001];
std::map<long long,long long>map;
std::set<int>set[500001];
long long c[500001];
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
	scanf("%lld",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%lld%lld",&n,&m);
		srand(time(0));
		for(int i=1;i<=n;i++)head[i]=0;
		k=0;
		unsigned int tot=0;
		for(int i=1;i<=n;i++)stat[i]=0;
		for(int i=1;i<=n;i++)scanf("%lld",c+i),tot+=c[i]^((i)?c[i-1]:0)^((i>1)?c[i-2]:0);
		srand(rand()+tot);
		for(int i=1;i<=n;i++)val[i]=1ll*(rand()+1)*(rand()+1)*(rand()+1);
		for(int i=1;i<=m;i++){
			scanf("%lld%lld",&u,&v);
			stat[v]^=val[u];
		}
		map.clear();
		for(int i=1;i<=n;i++)if(stat[i])map[stat[i]]+=c[i];
		long long ans=0;
		for(auto it=map.begin();it!=map.end();++it)
			ans=gcd(ans,it->second);
		printf("%lld\n",ans);
	}
}