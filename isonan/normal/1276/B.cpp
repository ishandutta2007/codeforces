#include <cstdio>
#include <cstring>

int t,head[200001],b[1000001],nxt[1000001],k,n,m,a,B;
int vis[200001],val[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int mrk){
	if(vis[x])return;
	vis[x]=1;
	val[x]+=mrk;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=a&&b[i]!=B)dfs(b[i],mrk);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d%d",&n,&m,&a,&B);
		for(int i=1;i<=n;i++)vis[i]=val[i]=0;
		memset(head,0,(n+1)<<2);
		k=0;
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&u,&v);
			push(u,v);
			push(v,u);
		}
		dfs(a,1);
		for(int i=1;i<=n;i++)vis[i]=0;
		dfs(B,2);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(i==a||i==B)continue;
			if(val[i]==1)++cnt1;
			else if(val[i]==2)++cnt2;
		}
		printf("%lld\n",1ll*cnt1*cnt2);
	}
}