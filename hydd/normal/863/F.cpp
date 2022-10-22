#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n,q,s,t,ans,maxflow,L[5100],R[5100];
int cnt,num[5100],h[5100],vis[5100],dis[5100],lst[5100]; 
int edgenum=1,F[110000],V[110000],Next[110000],W[110000],Head[5100],cur[5100];
void addedge(int u,int v,int f,int w){
	V[++edgenum]=v; W[edgenum]=w; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f,int w){
//	cerr<<'#'<<' '<<u<<' '<<v<<' '<<f<<' '<<w<<endl;
	addedge(u,v,f,w);
	addedge(v,u,0,-w);
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
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) L[i]=1,R[i]=n;
	int op,l,r,x;
	for (int i=1;i<=q;i++){
		scanf("%d%d%d%d",&op,&l,&r,&x);
		for (int j=l;j<=r;j++)
			if (op==1) L[j]=max(L[j],x);
			else R[j]=min(R[j],x);
	}
	for (int i=1;i<=n;i++)
		if (L[i]>R[i]){
			puts("-1");
			return 0;
		}
	s=0; t=n<<1|1;
	for (int i=1;i<=n;i++) Add(s,i,1,0);
	for (int i=1;i<=n;i++)
		for (int j=L[i];j<=R[i];j++)
			Add(i,j+n,1,0);
//	puts("###");
	for (int i=1;i<=n;i++)
		for (int j=0;j<n;j++)
			Add(i+n,t,1,j<<1|1);
	mincostmaxflow(); printf("%d\n",ans);
	return 0;
}