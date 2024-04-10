#include <cstdio>
#include <vector>

int n,m,head[300001],nxt[600001],b[600001],k,dep[300001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
std::vector<std::pair<int,int> >vec[300001];
int lson[300001],rson[300001],dis[300001],root[300001],ord[300001],cnt;
long long val[300001],lazy[300001],f[300001];
void pushdown(int x,long long v){if(x)val[x]+=v,lazy[x]+=v;}
void spread(int x){
	if(!x)return;
	if(lson[x])pushdown(lson[x],lazy[x]);
	if(rson[x])pushdown(rson[x],lazy[x]);
	lazy[x]=0;
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	spread(x),spread(y);
	if(val[x]>val[y])x^=y^=x^=y;
	rson[x]=merge(rson[x],y);
	if(dis[rson[x]]>dis[lson[x]])lson[x]^=rson[x]^=lson[x]^=rson[x];
	dis[x]=rson[x]?dis[rson[x]]+1:0;
	return x;
}
bool sb=0;
void dfs(int x,int F){
	long long sum=0;
	dep[x]=dep[F]+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F)dfs(b[i],x),sum+=f[b[i]];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			pushdown(root[b[i]],sum-f[b[i]]);
			root[x]=merge(root[x],root[b[i]]);
		}
	for(int i=0;i<vec[x].size();i++){
		ord[++cnt]=vec[x][i].first;
		val[cnt]=sum+vec[x][i].second;
		root[x]=merge(root[x],cnt);
	}
	while(root[x]&&dep[ord[root[x]]]>=dep[x])root[x]=merge(lson[root[x]],rson[root[x]]);
	f[x]=x==1?sum:(root[x]?val[root[x]]:sb=1);
	if(sb)return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		vec[u].push_back(std::make_pair(v,w));
	}
	dfs(1,0);
	if(sb)puts("-1");
	else printf("%lld\n",f[1]);
}