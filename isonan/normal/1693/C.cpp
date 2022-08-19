#include <cstdio>
#include <queue>

std::priority_queue<std::pair<int,int> >heap;
int n,m;
int head[2000001],nxt[2000001],b[2000001],k;
int dis[2000001],d[2000001];
bool vis[2000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)scanf("%d%d",&u,&v),push(v,u),++d[u];
	for(int i=1;i<=n;++i)dis[i]=n+m+100;
	dis[n]=0;
	heap.push(std::make_pair(0,n));
	for(;!heap.empty();){
		auto now=heap.top();
		heap.pop();
		if(vis[now.second])continue;
		vis[now.second]=1;
		// printf("%d\n",now.second);
		for(int j=head[now.second];j;j=nxt[j]){
			--d[b[j]];
			// printf("%d %d %d %d\n",b[j],d[b[j]]+dis[now.second]+1);
			if(dis[b[j]]>d[b[j]]+dis[now.second]+1){
				dis[b[j]]=d[b[j]]+dis[now.second]+1;
				// printf("%d\n",d[b[j]]+dis[now.second]+1);
				heap.push(std::make_pair(-dis[b[j]],b[j]));
			}
		}
	}
	printf("%d\n",dis[1]);
}