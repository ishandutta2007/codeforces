#include <cstdio>
#include <vector>
#include <algorithm>

int T,n,m,u[250001],v[250001],w[250001];
int head[100001],nxt[500001],b[500001],k;
int dis1[100001],disn[100001];
int edis[100001];
int c1[100001],cn[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int q[100001],h,t;
void getdis(int *dis,int *c,int x){
	for(int i=1;i<=n;++i)dis[i]=0x7f7f7f7f;
	dis[x]=0;
	h=t=0;
	q[++t]=x;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(dis[b[i]]==0x7f7f7f7f){
				dis[b[i]]=dis[q[h]]+1;
				q[++t]=b[i];
			}
	}
	for(int i=1;i<=n;++i){
		c[i]=0;
		for(int j=head[i];j;j=nxt[j])
			if(dis[b[j]]==dis[i]-1){
				if(!c[i]||c[i]==b[j])c[i]=b[j];
				else c[i]=-1;
			}
	}
}
bool vis[501];
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)head[i]=0;
		k=0;
		for(int i=1;i<=m;++i)scanf("%d%d%d",u+i,v+i,w+i),push(u[i],v[i]),push(v[i],u[i]);
		getdis(dis1,c1,1);
		getdis(disn,cn,n);
		for(int i=1;i<=n;++i)edis[i]=dis1[i]+disn[i],vis[i]=0;
		for(int i=1;i<=n;++i){
			int p=0;
			for(int j=1;j<=n;++j)
				if((!p&&!vis[j])||(edis[p]>edis[j]&&!vis[j]))p=j;
			vis[p]=1;
			// printf("%d\n",p);
			for(int j=head[p];j;j=nxt[j])
				edis[b[j]]=std::min(edis[b[j]],edis[p]+1);
		}
		long long ans=1e18;
		// for(int i=1;i<=n;++i)printf("%d ",dis1[i]);putchar('\n');
		// for(int i=1;i<=n;++i)printf("%d ",disn[i]);putchar('\n');
		// for(int i=1;i<=n;++i)printf("%d ",edis[i]);putchar('\n');
		for(int i=1;i<=m;++i)ans=std::min(ans,1ll*w[i]*(dis1[u[i]]+disn[v[i]]+1));
		for(int i=1;i<=m;++i)ans=std::min(ans,1ll*w[i]*(dis1[v[i]]+disn[u[i]]+1));
		for(int i=1;i<=m;++i)ans=std::min(ans,1ll*w[i]*(edis[u[i]]+2));
		for(int i=1;i<=m;++i)ans=std::min(ans,1ll*w[i]*(edis[v[i]]+2));
		printf("%lld\n",ans);
	}
}