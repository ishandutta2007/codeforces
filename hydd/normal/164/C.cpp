#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n,k,s,t,ans,maxflow,u[5100],v[5100],c[5100];
int cnt,num[5100],h[5100],vis[5100],dis[5100],lst[5100]; 
int edgenum=1,F[110000],V[110000],Next[110000],W[110000],Head[5100],cur[5100];
void addedge(int u,int v,int f,int w){
	V[++edgenum]=v; W[edgenum]=w; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f,int w){
	if (w<0){
		num[u]-=f; num[v]+=f;
		addedge(v,u,f,-w);
//		cerr<<"#"<<v<<' '<<u<<' '<<f<<' '<<-w<<endl;
		addedge(u,v,0,w); ans+=w*f;
	} else{
		addedge(u,v,f,w);
//		cerr<<"#"<<u<<' '<<v<<' '<<f<<' '<<w<<endl;
		addedge(v,u,0,-w);
	}
}
bool dijkstra(){
    for (int i=s;i<=t;i++) vis[i]=false,dis[i]=INF;
    dis[s]=0;
	priority_queue<pii> que; que.push(pii(0,s));
    while (!que.empty()){
        int u=que.top().second; que.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int e=Head[u];e;e=Next[e]){
            int v=V[e];
            if (dis[v]>dis[u]+W[e]+h[u]-h[v]&&F[e]){
                dis[v]=dis[u]+W[e]+h[u]-h[v]; lst[v]=e;
                que.push(pii(-dis[v],v));
            }
        }
    }
    return dis[t]!=INF;
}
int mincostmaxflow(){
    while (dijkstra()){
        int tmp=INF;
        for (int i=t;i!=s;i=V[lst[i]^1]) tmp=min(tmp,F[lst[i]]);
        for (int i=t;i!=s;i=V[lst[i]^1]) F[lst[i]]-=tmp,F[lst[i]^1]+=tmp;
        ans+=(h[t]-h[s]+dis[t])*tmp; maxflow+=tmp;
    	for (int i=s;i<=t;i++) h[i]+=dis[i]; 
    }
    return maxflow;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&u[i],&v[i],&c[i]); v[i]+=u[i];
		num[++cnt]=u[i]; num[++cnt]=v[i];
	}
	sort(num+1,num+cnt+1); cnt=unique(num+1,num+cnt+1)-num-1;
	s=0; t=cnt+1;
	for (int i=1;i<=n;i++){
		u[i]=lower_bound(num+1,num+cnt+1,u[i])-num;
		v[i]=lower_bound(num+1,num+cnt+1,v[i])-num;
	}
	for (int i=1;i<=cnt;i++) num[i]=0;
	num[1]+=k; num[cnt]-=k;
	for (int i=1;i<=n;i++) Add(u[i],v[i],1,-c[i]);
	for (int i=1;i<=cnt;i++){
		if (num[i]>0) Add(s,i,num[i],0);
		if (num[i]<0) Add(i,t,-num[i],0);
	}
	for (int i=1;i<cnt;i++) Add(i,i+1,k,0);
	mincostmaxflow();
//	printf("%d\n",-ans);
	for (int i=1;i<=n;i++)
		printf("%d ",F[i<<1]);
	return 0;
}