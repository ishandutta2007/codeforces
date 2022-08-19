#include <cstdio>
#include <algorithm>
#include <cstring>

int t,n,m,A[1001],B[1001];
int head[1001],nxt[4001],b[4001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
bool vis[1001];
int pre[1001];
void Add(int x){
	if(vis[x])return;
	vis[x]=1;
	Add(pre[x]);
}
bool dfs(int x,int f,int v){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			if(pre[b[i]]){
				Add(b[i]);
				Add(x);
				return 1;
			}
			else if(vis[b[i]]){
				if(!vis[x]){
					Add(x);
					return 1;
				}
			}
			else{
				if(v<=A[b[i]])continue;
				pre[b[i]]=x;
				if(dfs(b[i],x,std::min(v+B[b[i]],1000000001)))return 1;
			}
		}
	return 0;
}
bool judge(int x){
	for(int i=1;i<=n;++i)vis[i]=0;
	vis[1]=1;
	for(int v;;){
		v=x;
		for(int i=1;i<=n;++i)if(vis[i])v=std::min(v+B[i],1000000001);
		bool add=0;
		memset(pre,0,sizeof pre);
		for(int i=1;i<=n;++i)
			if(vis[i]&&dfs(i,0,v)){add=1;break;}
		if(!add)break;
	}
	for(int i=1;i<=n;++i)if(!vis[i])return 0;
	return 1;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		for(int i=2;i<=n;++i)scanf("%d",A+i);
		for(int i=2;i<=n;++i)scanf("%d",B+i);
		for(int i=1;i<=n;++i)head[i]=0;
		k=0;
		for(int i=1,u,v;i<=m;++i)scanf("%d%d",&u,&v),push(u,v),push(v,u);
		int l=0,r=1000000001,mid,ans;
		while(l<=r){
			mid=(l+r)>>1;
			if(judge(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
}