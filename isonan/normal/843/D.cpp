#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

int n,m,q,head[100001],nxt[100001],b[100001],v[100001],add[100001],k;
long long f[100001];
std::vector<int>vec[100001];
std::priority_queue<std::pair<long long,int> >heap;
long long dis[100010];
bool vis[100010];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,a,b,c;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		push(a,b,c);
	}
	for(int i=2;i<=n;i++)dis[i]=1e18;
	heap.push(std::make_pair(0,1));
	dis[1]=0;
	for(;!heap.empty();){
		int now=heap.top().second;
		heap.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(int j=head[now];j;j=nxt[j])
			if(dis[b[j]]>dis[now]+v[j]){
				dis[b[j]]=dis[now]+v[j];
				heap.push(std::make_pair(-dis[b[j]],b[j]));
			}
	}
//	putchar('*');
//	for(int i=1;i<=n;i++)printf("%lld ",dis[i]);putchar('\n');
	for(int i=1,opt,t;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&t);
			if(dis[t]==1e18)puts("-1");
			else printf("%lld\n",dis[t]);
		}
		else{
			scanf("%d",&t);
			memset(add,0,sizeof add);
			for(int i=1,y;i<=t;i++)
				scanf("%d",&y),add[y]=1;
			memset(vis,0,sizeof vis);
			for(int i=1;i<=n;i++)f[i]=1e18;
			f[1]=0;
			for(int i=0;i<=t;i++)vec[i].clear();
			vec[0].push_back(1);
			for(int i=0;i<=t;i++){
				for(;!vec[i].empty();){
					int now=vec[i].back();
					vec[i].pop_back();
					if(vis[now])continue;
					vis[now]=1;
					for(int j=head[now];j;j=nxt[j])
						if(f[b[j]]>f[now]+v[j]+add[j]+dis[now]-dis[b[j]]){
							f[b[j]]=f[now]+v[j]+add[j]+dis[now]-dis[b[j]];
							if(f[b[j]]<=t)vec[f[b[j]]].push_back(b[j]);
						}
				}
			}
//			for(int i=1;i<=n;i++)printf("%lld ",f[i]);putchar('\n');
			for(int i=1;i<=n;i++)if(dis[i]!=1e18)dis[i]+=f[i];
			for(int i=1;i<=m;i++)v[i]+=add[i];
		}
	}
}