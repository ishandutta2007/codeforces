#include <cstdio>
#include <algorithm>
#define int long long
 
int n,m,head[2000001],nxt[4000001],b[4000001],k,s,f[2000001],d[2000001];
bool vis[2000001];
long long w[2000001],ans=0,sum[2000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x){
	vis[x]=1;
	int ch=0,un=0;
	long long ans=0ll;
	f[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		if(!vis[b[i]]){
			dfs(b[i]);
			if(f[b[i]])sum[x]=std::max(sum[x],sum[b[i]]);
			else f[x]=0;
			++un;
		}
		else ++ch;
	}
	sum[x]+=w[x];
	if(ch>1)f[x]=0;
	else if(un==0)f[x]=1;
	if(f[x])::ans=std::max(::ans,sum[x]);
	else sum[x]=0;
}
signed main(){
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%I64d",w+i);
	for(int i=1,u,v;i<=m;i++){
		scanf("%I64d%I64d",&u,&v);
		push(u,v);
		push(v,u);
		++d[u],++d[v];
	}
	scanf("%d",&s);
	dfs(s);
	for(int i=1;i<=n;i++)if(!f[i])ans+=w[i];
	printf("%I64d\n",ans);
}