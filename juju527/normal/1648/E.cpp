#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2e5+5,maxm=2e5+5;
struct edge{
	int id,u,v,w;
	bool operator <(edge i)const{return w<i.w;}
}ed[maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct Edge{int to,w,nxt;}g[2*maxn];
int cnt,head[maxn];
void add(int u,int v,int w){
	g[cnt]=(Edge){v,w,head[u]};
	head[u]=cnt++;
	return ;
}
int f[maxn],F[maxn];
set<int> e[maxn];
vector<int> a[maxn],b[maxn];
inline int find1(int x){return (x==f[x])?x:f[x]=find1(f[x]);}
inline int find2(int x){return (x==F[x])?x:F[x]=find2(F[x]);}
bool vis[maxn];
void merge(int u,int v,int w){
	u=find2(u),v=find2(v);
	add(u,v,w);add(v,u,w);
	if(b[u].size()>b[v].size())swap(u,v);
	F[u]=v;
	for(int i=0;i<b[u].size();i++)b[v].eb(b[u][i]);
	b[u].clear();
	return ;
}
int link[maxn];
void Merge(int u,int v,int w){
	if(a[u].size()>a[v].size())swap(u,v);
	for(int i=0;i<a[u].size();i++){
		int x=find2(a[u][i]),pos=-1;
		for(int j=0;j<a[v].size();j++){
			int y=find2(a[v][j]);
			for(int p=0;p<b[x].size();p++){
				int s=b[x][p];
				for(int q=0;q<b[y].size();q++){
					int t=b[y][q];
					if(e[s].find(t)!=e[s].end())continue;
					vis[j]=1;
					if(pos==-1)pos=j;else if(b[a[v][pos]].size()<b[y].size())pos=j;
					break;
				}
				if(vis[j])break;
			}
		}
		link[i]=-1;
		if(pos==-1)continue;
		swap(a[v][0],a[v][pos]),swap(vis[0],vis[pos]);vis[0]=0;
		for(int j=a[v].size()-1;j>=1;j--){
			if(!vis[j])continue;
			vis[j]=0;
			merge(a[v][0],a[v][j],w);
			swap(a[v][j],a[v][a[v].size()-1]);
			a[v].pop_back();
		}
		link[i]=a[v][0];
	}
	f[u]=v;
	for(int i=0;i<a[u].size();i++){
		int x=a[u][i];
		if(link[i]>0)merge(x,link[i],w);
		else a[v].eb(x);
	}
	a[u].clear();
	return ;
}
int dep[maxn];
int p[maxn][18],mx[maxn][18];
void dfs(int x,int fa,int w){
	dep[x]=dep[fa]+1;p[x][0]=fa;mx[x][0]=w;
	for(int i=1;i<18;i++){
		p[x][i]=p[p[x][i-1]][i-1];
		mx[x][i]=max(mx[x][i-1],mx[p[x][i-1]][i-1]);
	}
	for(int i=head[x];i!=-1;i=g[i].nxt){
		int tmp=g[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x,g[i].w);
	}
	return ;
}
inline int calc(int x,int y){
	int res=0;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)if(dep[p[x][i]]>=dep[y])res=max(res,mx[x][i]),x=p[x][i];
	if(x==y)return res;
	for(int i=17;i>=0;i--)if(p[x][i]^p[y][i])res=max(res,max(mx[x][i],mx[y][i])),x=p[x][i],y=p[y][i];
	return max(res,max(mx[x][0],mx[y][0]));
}
int res[maxn];
int main(){
    int T;
	T=read();
	while(T--){
		int n,m;
		n=read();m=read();
		cnt=0;for(int i=1;i<=n;i++)head[i]=-1;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=m;i++){
			int u,v,w;
			u=read();v=read();w=read();
			ed[i]=(edge){i,u,v,w};
			e[u].insert(v);e[v].insert(u);
		}
		sort(ed+1,ed+m+1);
		for(int i=1;i<=n;i++){
			a[i].resize(1),a[i][0]=i;
			b[i].resize(1);b[i][0]=i;
			f[i]=F[i]=i;
		}
		for(int i=1;i<=m;i++){
			int u=ed[i].u,v=ed[i].v,w=ed[i].w;
			u=find1(u),v=find1(v);
			if(u==v)continue;
			Merge(u,v,w);
		}
		dfs(1,0,0);
		for(int i=1;i<=m;i++){
			int u=ed[i].u,v=ed[i].v;
			res[ed[i].id]=calc(u,v);
		}
		for(int i=1;i<=m;i++)printf("%d ",res[i]);
		puts("");
	}
    return 0;
}