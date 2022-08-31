#include <cstdio>

int t,n;
int head[200001],nxt[400001],b[400001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int g[200001],ans;
void dfs(int x,int f){
	g[x]=1;
	int cnt=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			if(g[b[i]]){
				g[x]=0;
				++cnt;
			}
		}
	if(x>1){
		if(g[x])++ans;
		else --ans;
	}
	else if(g[x])++ans;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)head[i]=0;
		k=0;
		for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),push(u,v),push(v,u);
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
}