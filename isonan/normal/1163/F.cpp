#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#define int long long

int n,m,q;
int head[200001],nxt[400010],b[400010],v[400010],k=1;
int pre[200001];
int L[200001],R[200001],ind[200001];
long long dis1[200001],disn[200001],val[200001];
bool vis[200001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
std::priority_queue<std::pair<long long,int> >heap;
std::vector<long long>add[200001],del[200001];
void update(int l,int r,long long x){
	if(l>r)return;
	add[l].push_back(x);
	del[r].push_back(x);
}
void getdis(int s,long long *dis){
	memset(vis,0,sizeof vis);
	for(;!heap.empty();){
		int p=heap.top().second;
		heap.pop();
		if(vis[p])continue;
		vis[p]=1;
		for(int i=head[p];i;i=nxt[i])
			if(!vis[b[i]]&&dis[b[i]]>dis[p]+v[i]){
				dis[b[i]]=dis[p]+v[i];
				pre[b[i]]=i;
				heap.push(std::make_pair(-dis[b[i]],b[i]));
			}
	}
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%lld%lld%lld",&u,&v,&w);
		push(u,v,w);
		push(v,u,w);
	}
	for(int i=1;i<=n;++i)dis1[i]=1e18;
	dis1[1]=0;
	heap.push(std::make_pair(0,1));
	getdis(1,dis1);
	int tem=n,len=0;
	while(tem!=1){
		++len;
		tem=b[pre[tem]^1];
	}
	tem=n;
	int tl=len;
	while(tem!=1){
		ind[pre[tem]>>1]=tl--;
		tem=b[pre[tem]^1];
	}
	std::vector<std::pair<long long,int> >vec;
	for(int i=2;i<=n;++i)vec.push_back(std::make_pair(dis1[i],i));
	std::sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();++i){
		int u=vec[i].second;
		if(ind[pre[u]>>1])L[u]=ind[pre[u]>>1];
		else L[u]=L[b[pre[u]^1]];
	}
	for(int i=1;i<=n;++i)disn[i]=1e18;
	tem=n;
	int last=0;
	while(tem){
		disn[tem]=dis1[n]-dis1[tem];
		std::swap(pre[tem],last);
		last^=1;
		heap.push(std::make_pair(-disn[tem],tem));
		tem=b[last];
	}
	getdis(n,disn);
	vec.clear();
	for(int i=1;i<n;++i)vec.push_back(std::make_pair(disn[i],i));
	std::sort(vec.begin(),vec.end());
	R[n]=len+1;
	for(int i=0;i<vec.size();++i){
		int u=vec[i].second;
		if(ind[pre[u]>>1])R[u]=ind[pre[u]>>1];
		else R[u]=R[b[pre[u]^1]];
	}
	for(int i=1;i<=n;++i)
		for(int j=head[i];j;j=nxt[j])
			if(!ind[j>>1])
				update(L[i]+1,R[b[j]]-1,dis1[i]+disn[b[j]]+v[j]);
	std::multiset<long long>set;
	set.insert(1e18);
	for(int i=1;i<=len;++i){
		for(int j=0;j<add[i].size();++j)
			set.insert(add[i][j]);
		val[i]=*set.begin();
		for(int j=0;j<del[i].size();++j)
			set.erase(set.find(del[i][j]));
	}
	val[0]=dis1[n];
	for(int i=1;i<=q;++i){
		int t,x;
		scanf("%lld%lld",&t,&x);
		printf("%lld\n",std::min(val[ind[t]],std::min(dis1[b[t<<1]]+disn[b[t<<1|1]],disn[b[t<<1]]+dis1[b[t<<1|1]])+x));
	}
}