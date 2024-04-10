#include <cstdio>
#include <vector>
#include <algorithm>

int n;
bool have[500001];
struct tree{
	int head[500001],nxt[1000001],b[1000001],k,fa[500001];
	void push(int s,int t){
		nxt[++k]=head[s];
		head[s]=k;
		b[k]=t;
	}
	void dfs(int x,int f){
		fa[x]=f;
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=f){
				dfs(b[i],x);
			}
	}
}t1,t2;
int f[500001];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
void solve(int x,int f){
	for(int i=t1.head[x];i;i=t1.nxt[i])
		if(t1.b[i]!=f)solve(t1.b[i],x);
	if(f&&!have[x]){
		int u=find(x);
		printf("%d %d %d %d\n",x,f,u,t2.fa[u]);
		::f[u]=t2.fa[u];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),t1.push(u,v),t1.push(v,u);
	t1.dfs(1,0);
	int ans=n-1;
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v),t2.push(u,v),t2.push(v,u);
		if(t1.fa[u]==v)--ans,have[u]=1;
		if(t1.fa[v]==u)--ans,have[v]=1;
	}
	t2.dfs(1,0);
	for(int i=1;i<=n;i++)
		if(have[i]){
			int u=i,v=t1.fa[i];
			if(t2.fa[u]==v)f[u]=v;
			else f[v]=u;
		}
	printf("%d\n",ans);
	solve(1,0);
}