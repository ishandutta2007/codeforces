#include <cstdio>
#include <queue>

int n,m,K,head[10001],nxt[100001],b[100001],v1[100001],v2[100001],k,s1,s2,f;
long long dis1[10001],dis2[10001],fin1[10001],fin2[10001];
bool vis[10001];
std::priority_queue<std::pair<long long,int> >heap;
void push(int s,int t,int v1,int v2=-1){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	::v1[k]=v1;
	::v2[k]=v2;
}
void getdis(long long *dis,int s){
	for(int i=1;i<=n;i++)dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	heap.push(std::make_pair(dis[s],s));
	for(;!heap.empty();){
		int now=heap.top().second;
		heap.pop();
		if(vis[now])continue;
		for(int i=head[now];i;i=nxt[i])
			if(dis[b[i]]>dis[now]+v1[i])
				heap.push(std::make_pair(-(dis[b[i]]=dis[now]+v1[i]),b[i]));
	}
}
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&K,&s1,&s2,&f);
	for(int i=1,u,v,val;i<=m;i++)scanf("%d%d%d",&u,&v,&val),push(u,v,val);
	for(int i=1,u,v,v1,v2;i<=K;i++)scanf("%d%d%d%d",&u,&v,&v1,&v2),push(u,v,v2,v1);
	getdis(dis1,s1);
	getdis(dis2,s2);
	for(;;){
		bool cando=0;
		for(int i=1;i<=n;i++)
			if(dis1[i]<dis2[i])
				for(int j=head[i];j;j=nxt[j])
					if(~v2[j]&&v2[j]<v1[j])std::swap(v1[j],v2[j]),cando=1;
		getdis(dis1,s1);
		getdis(dis2,s2);
		if(dis1[f]<dis2[f]){puts("WIN");for(int i=1;i<=k;i++)if(~v2[i])printf("%d ",v1[i]);return 0;}
		if(!cando)break;
	}
	for(;;){
		bool cando=0;
		for(int i=1;i<=n;i++)
			if(dis1[i]<=dis2[i])
				for(int j=head[i];j;j=nxt[j])
					if(~v2[j]&&v2[j]<v1[j])std::swap(v1[j],v2[j]),cando=1;
		getdis(dis1,s1);
		getdis(dis2,s2);
		if(dis1[f]<=dis2[f]){puts("DRAW");for(int i=1;i<=k;i++)if(~v2[i])printf("%d ",v1[i]);return 0;}
		if(!cando)break;
	}
	puts("LOSE");
}