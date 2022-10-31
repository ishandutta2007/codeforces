// Hydro submission #6119dacff27b04e1a2541e6a@1629084368073
#include<bits/stdc++.h>
#define ll long long
#define reg register
#define F(i,a,b) for(reg int i=(a);i<=(b);++i)
using namespace std;
bool beginning;
inline int read();
const int N=1e5+5,E=N<<1;
int n,m,a[N];
int ver[E],net[E],head[N],tot;
inline void add(int x,int y){
	ver[++tot]=y,net[tot]=head[x],head[x]=tot;
}
struct P{
	int k,id;
};
vector<P>q[N];
bool vis[N];
int sz[N],son[N];
void dfs(int x,int fa){
	sz[x]=1;
	int mx=-1;
	for(reg int i=head[x];i;i=net[i]){
		int &y=ver[i];
		if(y==fa)continue;
		dfs(y,x);
		sz[x]+=sz[y];
		if(sz[y]>mx)mx=sz[y],son[x]=y;
	}
}
int d[N],cnt[N],ans[N];
inline void sol(int x,int fa,int c){
	if(c==-1)d[cnt[a[x]]]+=c;
	cnt[a[x]]+=c;
	if(c==1)d[cnt[a[x]]]+=c;
	for(reg int i=head[x];i;i=net[i]){
		int &y=ver[i];
		if(y==fa or vis[y])continue;
		sol(y,x,c);
	}
}
void dfs(int x,int fa,int c){
	for(reg int i=head[x];i;i=net[i]){
		int &y=ver[i];
		if(y==fa or y==son[x])continue;
		dfs(y,x,1);
	}
	if(son[x])dfs(son[x],x,0),vis[son[x]]=1;
	sol(x,fa,1);
	
	for(reg int i=0;i<q[x].size();++i)ans[q[x][i].id]=d[q[x][i].k];
	
	if(son[x])vis[son[x]]=0;
	if(c)sol(x,fa,-1);
}
bool ending;
int main(){
// 	printf("%.2lfMB\n",1.0*(&beginning-&ending)/1024/1024);
	n=read(),m=read();
	F(i,1,n)a[i]=read();
	int x,y;
	F(i,2,n){
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	F(i,1,m){
		x=read(),y=read();
		q[x].push_back({y,i});
	}
	dfs(1,0);
	dfs(1,0,1);
	F(i,1,m)printf("%d\n",ans[i]);
	return 0;
}
inline int read(){
	reg int x=0;
	reg char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}