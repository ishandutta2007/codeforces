#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=101000,maxm=201000;
const ll INF=1ll<<55;
int n,m;
int head[maxn],nxt[maxm],rdc[maxm],len[maxm],tnt;
int ord[44],mem[maxn],no;
int dep[maxn],f[19][maxn];
ll g[19][maxn],dis[44][44],stodis[44][maxn];
bool spe[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v,int w){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
	len[tnt]=w;
}
void dfs(int p){
	for(register int i=1;f[i-1][p];++i){
		f[i][p]=f[i-1][f[i-1][p]];
		g[i][p]=g[i-1][p]+g[i-1][f[i-1][p]];
	}
	for(register int i=head[p];i;i=nxt[i])
		if(!dep[rdc[i]]){
			dep[rdc[i]]=dep[p]+1;
			f[0][rdc[i]]=p;
			g[0][rdc[i]]=len[i];
			dfs(rdc[i]);
		}
		else if(rdc[i]!=f[0][p]){
			if(!mem[p]){
				mem[p]=++no;
				ord[no]=p;
			}
			spe[i]=true;
		}
}
ll getlen(int u,int v){
	if(dep[v]>dep[u])swap(u,v);
	ll res=0;
	for(register int i=18;~i;--i)
		if((dep[u]-dep[v])>>i)
			res+=g[i][u],u=f[i][u];
	if(u==v)return res;
	for(register int i=18;~i;--i)
		if(f[i][u]!=f[i][v]){
			res+=g[i][u]+g[i][v];
			u=f[i][u];v=f[i][v];
		}
	return res+g[0][u]+g[0][v];
}
void reset(){
	for(register int i=1;i<=no;++i)
		for(register int j=1;j<=no;++j)
			dis[i][j]= i^j?INF:0;
	for(register int i=1,u,v;i<=tnt;i+=2)
		if(spe[i]){
			u=mem[rdc[i]];v=mem[rdc[i+1]];
			dis[u][v]=dis[v][u]=len[i];
		}
	for(register int i=1;i<=no;++i)
		for(register int j=1;j<=no;++j)
			dis[i][j]=min(dis[i][j],getlen(ord[i],ord[j]));
	for(register int i=1;i<=no;++i)
		for(register int j=1;j<=no;++j)
			for(register int k=1;k<=no;++k)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	for(register int i=1;i<=no;++i)
		for(register int j=1;j<=n;++j)
			stodis[i][j]=getlen(ord[i],j);
}
int main(){
	n=read();m=read();
	for(register int i=0,u,v,w;i<m;++i){
		u=read();v=read();w=read();
		add(u,v,w);add(v,u,w);
	}
	dep[1]=1;dfs(1);
	reset();
	for(register int Q=read(),u,v;Q;--Q){
		u=read();v=read();
		ll ans=getlen(u,v);
		for(register int i=1;i<=no;++i)
			for(register int j=1;j<=no;++j)
				ans=min(ans,stodis[i][u]+dis[i][j]+stodis[j][v]);
		printf("%lld\n",ans);
	}
	return 0;
}