// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// wyyakioi
// Wyyakioi
// wyyakioi
// Wyyakioi
// wyyakioi
// Wyyakioi
// wyyakioi
// Wyyakioi
// wyyakioi
// Wyyakioi

#include<bits/stdc++.h>
using namespace std;
#define M 205
#define N 75
#define pb push_back
#define inf 1e9
bool can[N];
int Tot,f[N],i,j,k,x[M],dis[M],y[M],v[M],cnt,a,b,n,m,fm,dp[N][1<<17],lt[N],r[N],siz[N],is[N],tot,ce[N];
inline int find(int x){if(f[x]!=x)f[x]=find(f[x]);return f[x];}
void MIN(int &x,int y){if(y<x)x=y;}
vector<int>nd[N],tt[N];
int nxt[M<<2],to[M<<2],node[N],val[M<<2];
struct nde{
	int x,d;
	bool operator<(nde aa)const{return aa.d<d;}
}tmp;
priority_queue<nde>p;
void dij(){
	tmp.d=tmp.x=0;p.push(tmp);dis[0]=0;int x,i;
	while(p.size()){
		tmp=p.top();p.pop();x=tmp.x;
		if(dis[x]==tmp.d)
			for(i=node[x];i;i=nxt[i])
				if(dis[to[i]]>dis[x]+val[i])
					tmp.d=dis[to[i]]=dis[x]+val[i],tmp.x=to[i],p.push(tmp);
	}
}
inline void add(int x,int y,int v){
	to[++tot]=y;val[tot]=v;nxt[tot]=node[x];node[x]=tot;
}int xx,ans;
int main(){
	cin>>n>>m>>a>>b;
	for(i=1;i<=m;++i)cin>>x[i]>>y[i]>>v[i];
	for(i=1;i<=n;++i)f[i]=i;
	for(i=1;i<=m;++i)if(v[i]==a)f[find(x[i])]=find(y[i]);
	for(i=1;i<=m;++i){
		if(v[i]==b&&find(x[i])==find(y[i])){
			for(j=i;j<m;++j)x[j]=x[j+1],y[j]=y[j+1],v[j]=v[j+1];
			--m;
		}
	}
	for(i=1;i<=m;++i)if(v[i]==b)tt[x[i]].pb(y[i]),tt[y[i]].pb(x[i]);
	for(i=1;i<=n;++i)
		if(f[i]==i)lt[++cnt]=i,r[i]=cnt;
	for(i=1;i<=n;++i)++siz[r[i]=r[find(i)]],nd[r[find(i)]].pb(i);
	for(i=1;i<=cnt;++i)if(siz[i]>3)is[Tot]=i,ce[i]=Tot++;
	fm=find(1);memset(dp,0x3f,sizeof(dp));
	if(siz[r[fm]]>3)dp[1][1<<ce[r[fm]]]=0;else dp[1][0]=0;
	for(i=0;i<(1<<Tot);++i){
		tot=0;memset(node,0,sizeof(node));memset(can,0,sizeof(can));memset(dis,0x3f,sizeof(dis));
		for(j=1;j<=n;++j)add(0,j,dp[j][i]);
		for(k=1;k<=cnt;++k)
			if(siz[k]>3)can[k]=1;
		for(k=1;k<=m;++k){
			if(v[k]==a||!can[r[y[k]]])add(x[k],y[k],v[k]);
			if(v[k]==a||!can[r[x[k]]])add(y[k],x[k],v[k]);
		}dij();
		for(j=1;j<=n;++j)dp[j][i]=dis[j];
		for(j=1;j<=n;++j){
			if(dp[j][i]<inf){
				for(k=0;k<tt[j].size();++k){
					xx=tt[j][k];
					if(siz[r[xx]]>3&&!((i>>ce[r[xx]])&1)){
						MIN(dp[xx][i|(1<<ce[r[xx]])],dp[j][i]+b);
					}
				}
			}
		}
	}
	for(i=1;i<=n;cout<<ans<<" ",++i)
		for(ans=1e9,j=0;j<(1<<Tot);++j)
			ans=min(ans,dp[i][j]);
}