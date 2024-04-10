#include <cstdio>
#include <cstring>
#include <set>

std::set<std::pair<int,int> >set;
int head[3010],nxt[6010],b[6010],k,n,u,v,fa[3010],cnt,rt;
bool vis[3010];
long double ans;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getloop(int x,int f){
	if(vis[x]){
		u=x,v=f;
		return;
	}
	vis[x]=1;
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getloop(b[i],x);
}
void dfs(int x,int f,int tot,int dis){
//	printf("%d %d %d %d\n",x,f,tot,dis);
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]]){
			tot+=set.count(std::make_pair(b[i],x))?1:0;
//			printf("%d %d %d %d %d %d\n",b[i],x,rt,f,set.count(std::make_pair(b[i],x))?1:0,tot);
			++dis;
			if(!tot)ans+=(long double)1/(long double)dis;
			else ans+=(long double)1/(long double)dis+(long double)1/(long double)(dis-tot-tot+cnt)-(long double)1/(long double)(dis-tot+cnt-1);
			dfs(b[i],x,tot,dis);
			--dis;
			tot-=set.count(std::make_pair(b[i],x))?1:0;
		}
}
int main(){
	scanf("%d",&n);
	for(int i=1,s,t;i<=n;i++){
		scanf("%d%d",&s,&t);
		++s,++t;
		push(s,t);
		push(t,s);
	}
	getloop(1,0);
	memset(vis,0,sizeof vis);
	int tem=u;
	while(tem){
		vis[tem]=1;
		tem=fa[tem];
	}
	int last=0;
	tem=v;
	while(tem){
		if(!last&&vis[tem])last=tem;
		vis[tem]^=1;
		tem=fa[tem];
	}
	vis[last]=1;
	set.insert(std::make_pair(u,v));
	set.insert(std::make_pair(v,u));
	while(u){
		if(vis[u]&&vis[fa[u]])set.insert(std::make_pair(u,fa[u])),set.insert(std::make_pair(fa[u],u));
		u=fa[u];
	}
	while(v){
		if(vis[v]&&vis[fa[v]])set.insert(std::make_pair(v,fa[v])),set.insert(std::make_pair(fa[v],v));
		v=fa[v];
	}
	for(int i=1;i<=n;i++)cnt+=vis[i];
	for(int i=1;i<=n;i++)memset(vis,0,sizeof vis),rt=i,dfs(i,0,0,1);
	printf("%.10Lf",ans+(long double)n);
}