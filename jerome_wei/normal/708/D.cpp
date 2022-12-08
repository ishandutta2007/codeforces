#include<bits/stdc++.h>
using namespace std;
const int N=1010,INF=0x3f3f3f3f,M=2000010;
int n,m;
namespace graph{
	int S,T,cnt=1,hed[N],to[M],nxt[M],cap[M],cost[M];
	inline void adde(int u,int v,int _fl,int _c){
		++cnt;to[cnt]=v,nxt[cnt]=hed[u],cap[cnt]=_fl,cost[cnt]=_c;hed[u]=cnt;
		++cnt;to[cnt]=u,nxt[cnt]=hed[v],cap[cnt]=0,cost[cnt]=-_c;hed[v]=cnt;
	}

	queue<int>Q;
	int d[N];bool vis[N];int incf[N];
	int pre[N];
	bool spfa(){
		for(int i=min(1,S);i<=max(n,T);i++)d[i]=INF;
		memset(vis,0,sizeof(vis));
		Q.push(S);d[S]=0;vis[S]=1;
		incf[S]=INF;
		while(!Q.empty()){
			int u=Q.front();vis[u]=false;Q.pop();
			for(int i=hed[u];i;i=nxt[i]){
				int v=to[i];
				if(!cap[i])continue;
				if(d[v]>d[u]+cost[i]){
					d[v]=d[u]+cost[i];
					incf[v]=min(incf[u],cap[i]);
					pre[v]=i;
					if(!vis[v])vis[v]=true,Q.push(v);
				}
			}
		}
		if(d[T]==INF)return false;
		return true;
	}
	int mincost,maxflow;
	void update(){
		int x=T;
		while(x!=S){
			int i=pre[x];
			cap[i]-=incf[T];
			cap[i^1]+=incf[T];
			x=to[i^1];
		}
		maxflow+=incf[T];
		mincost+=d[T]*incf[T];
	}

	int mincost_maxflow(){
		while(spfa())update();
		return mincost;
	}
}
using namespace graph;
int u[N],v[N],f[N],c[N];
int L[N],R[N];
int ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&u[i],&v[i],&c[i],&f[i]);
		L[v[i]]+=f[i];R[u[i]]+=f[i];
	}
	S=n+1,T=n+2;
	for(int i=1;i<=n;i++){
		if(R[i]-L[i]>0){
			adde(i,T,R[i]-L[i],0);
		}else{
			adde(S,i,L[i]-R[i],0);
		}
	}
	adde(n,1,INF,0);
	for(int i=1;i<=m;i++){
		if(f[i]<=c[i]){
			adde(u[i],v[i],c[i]-f[i],1);
			adde(u[i],v[i],INF,2);
			adde(v[i],u[i],f[i],1);
		}else{
			ans+=f[i]-c[i];
			adde(u[i],v[i],INF,2);
			adde(v[i],u[i],f[i]-c[i],0);
			adde(v[i],u[i],c[i],1);
		}
	}
	cout<<ans+mincost_maxflow()<<endl;
}