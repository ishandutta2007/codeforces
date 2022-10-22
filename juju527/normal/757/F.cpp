#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=2e5+5,maxm=3e5+5;
const ll inf=1e18;
int n,m,s;
struct Edge{int to,w,nxt;}e[2*maxm];
int cnt;
int head[maxn];
bool ban[2*maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w){
	e[cnt]=(Edge){v,w,head[u]};
	head[u]=cnt++;
	return ;
}
ll dis[maxn];
bool vis[maxn];
priority_queue<pair<ll,int>> q;
void dijkstra(){
	for(int i=1;i<=n;i++)dis[i]=inf;
	q.push(make_pair(0,s));dis[s]=0;
	while(q.size()){
		int k=q.top().se;
		q.pop();
		if(vis[k])continue;
		vis[k]=1;
		for(int i=head[k];i!=-1;i=e[i].nxt){
			int tmp=e[i].to,w=e[i].w;
			if(dis[tmp]<=dis[k]+w)continue;
			dis[tmp]=dis[k]+w;
			q.push(make_pair(-dis[tmp],tmp));
		}
	}
	return ;
}
vector<int> in[maxn];
int rd[maxn];
int dep[maxn],f[maxn][18],siz[maxn];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(int i=17;i>=0;i--)if(f[x][i]^f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
namespace topo_sort{
	queue<int> q;
	void topo(){
		for(int i=1;i<=n;i++)if(!rd[i])q.push(i);
		while(q.size()){
			int k=q.front();
			q.pop();
			int anc=0;
			if(in[k].size())anc=in[k][0];
			for(int i=1;i<in[k].size();i++)anc=lca(anc,in[k][i]);
			dep[k]=dep[anc]+1;
			f[k][0]=anc;
			for(int i=1;i<18;i++)f[k][i]=f[f[k][i-1]][i-1];
			for(int i=head[k];i!=-1;i=e[i].nxt){
				int tmp=e[i].to;
				if(ban[i])continue;
				rd[tmp]--;
				if(!rd[tmp])q.push(tmp);
			}
		}
		return ;
	}
};
void dfs(int x,int fa){
	siz[x]=1;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x);
		siz[x]+=siz[tmp];
	}
	return ;
}
int main(){
	n=read();m=read();s=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();v=read();w=read();
		add(u,v,w),add(v,u,w);
	}
	dijkstra();
	for(int i=0;i<cnt;i+=2){
		int u=e[i^1].to,v=e[i].to,w=e[i].w;
		if(dis[v]!=dis[u]+w)ban[i]=1;
		else rd[v]++,in[v].push_back(u);
		if(dis[u]!=dis[v]+w)ban[i^1]=1;
		else rd[u]++,in[u].push_back(v);
	}
	topo_sort::topo();
	cnt=0;memset(head,-1,sizeof(head));
//	for(int i=1;i<=n;i++)cout<<f[i][0]<<" "<<i<<endl;
    for(int i=1;i<=n;i++)add(f[i][0],i,0);
	dfs(s,0);
	int res=0;
    for(int i=1;i<=n;i++)if(i^s)res=max(res,siz[i]);
	printf("%d\n",res);
	return 0;
}