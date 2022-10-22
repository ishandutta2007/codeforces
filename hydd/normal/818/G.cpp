#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n,k,s,t,ss,tt,ans,maxflow,a[21000];
int cnt,num[21000],h[21000],vis[21000],dis[21000],lst[21000]; 
int edgenum=1,F[210000],V[210000],Next[210000],W[210000],Head[21000],cur[21000];
void addedge(int u,int v,int f,int w){
	V[++edgenum]=v; W[edgenum]=w; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f,int w){
	if (w<0){
		num[u]-=f; num[v]+=f;
		addedge(v,u,f,-w);
		addedge(u,v,0,w); ans+=w*f;
	} else{
		addedge(u,v,f,w);
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
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	s=0; ss=n+n+n+n+1; tt=ss+1; t=tt+1;
	for (int i=1;i<=n;i++){
		Add(ss,i+n,INF,0); Add(i+n+n,i+n,INF,0); Add(i+n+n+n,i+n,INF,0);
		Add(i+n,i,1,-1); Add(i,tt,INF,0);
		
		for (int j=i+1;j<=n;j++)
			if (a[j]==a[i]+1){ Add(i,j+n+n+n,INF,0); break;}
		for (int j=i+1;j<=n;j++)
			if (a[j]==a[i]-1){ Add(i,j+n+n+n,INF,0); break;}
		for (int j=i+1;j<=n;j++)
			if (a[j]%7==a[i]%7){ Add(i,j+n+n,INF,0); break;}
		
		for (int j=i+1;j<=n;j++)
			if (a[j]%7==a[i]%7){ Add(i+n+n,j+n+n,INF,0); break;}
		for (int j=i+1;j<=n;j++)
			if (a[j]==a[i]){ Add(i+n+n+n,j+n+n+n,INF,0); break;}		
	}
//	Add(ss,tt,INF,0);
	num[ss]+=4; num[tt]-=4;
	for (int i=1;i<=n+n+n+n+2;i++){
		if (num[i]>0) Add(s,i,num[i],0);
		if (num[i]<0) Add(i,t,-num[i],0);
	}
	mincostmaxflow(); printf("%d\n",-ans);
	return 0;
}