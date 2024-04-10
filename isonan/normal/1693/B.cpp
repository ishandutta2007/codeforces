#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long

int t;
std::vector<int>son[200001],req[200001];
int n,p[200001],l[200001],r[200001],ans;
long long fl[200001],fr[200001],sub[200001];
void solve(int x){
	sub[x]=0;
	for(int v:son[x]){
		solve(v);
		l[x]-=sub[v];
		sub[x]+=sub[v];
	}
	if(l[x]<=0){
		sub[x]=std::min(sub[x],r[x]);
	}
	else{
		++ans;
		sub[x]=r[x];
	}
}
signed main(){
	scanf("%lld",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)son[i].clear();
		for(int i=2;i<=n;++i)scanf("%lld",p+i),son[p[i]].push_back(i);
		ans=0;
		for(int i=1;i<=n;++i)if(son[i].empty());
		for(int i=1;i<=n;++i)scanf("%lld%lld",l+i,r+i);
		solve(1);
		printf("%lld\n",ans);
	}
}