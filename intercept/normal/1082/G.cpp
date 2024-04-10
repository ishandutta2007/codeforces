#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const ll INF=1e14;
const ll M=10009;
ll n,m,s=M-3,t=M-4,num=1,ans=0;
ll head[M],cur[M],dis[M];
queue<ll>q;
bool vis[M];
struct P{
	ll to,ne,cap,flow;
}e[M<<1];
ll read(){
	ll rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
bool bfs(){
	memset(vis,0,sizeof(vis));
	vis[t]=1;q.push(t);
	while(!q.empty()){
		ll u=q.front();q.pop();
		for(ll i=head[u];i;i=e[i].ne){
			ll v=e[i].to;
			if(!vis[v]&&e[i^1].cap>e[i^1].flow){
				vis[v]=1;dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return vis[s];
}
ll dfs(ll u,ll a){
	if(u==t||a==0)return a;
	ll flow=0,f;
	for(ll i=head[u];i;i=e[i].ne){
		ll v=e[i].to;
		if(dis[v]==dis[u]-1){
			f=dfs(v,min(a,e[i].cap-e[i].flow));
			flow+=f;
			a-=f;
			e[i].flow+=f;
			e[i^1].flow-=f;
			if(a==0)break;
		}
	}
	return flow;
}
void add(ll u,ll v,ll cap){
	e[++num]=(P){v,head[u],cap,0};head[u]=num;
	e[++num]=(P){u,head[v],0,0};head[v]=num;
}
int main(){
	n=read(),m=read();
	for(ll i=1;i<=n;++i){
		ll x=read();
		add(s,i,x);
	}
	for(ll i=1,u,v,w;i<=m;++i){
		u=read(),v=read(),w=read();
		add(u,i+n,INF);
		add(v,i+n,INF);
		add(i+n,t,w);
		ans+=w;
	}
	while(bfs()){
		memcpy(cur,head,sizeof(cur));
		ans-=dfs(s,INF);
	}
	printf("%lld\n",ans);
	return 0;
}