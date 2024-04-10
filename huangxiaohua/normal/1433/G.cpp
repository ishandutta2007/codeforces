#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define INF 0x3FFFFFFF
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
typedef pair<int,int>PII;
typedef vector<PII>VII;
 
const int MAXN = 1005;
vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].PB(MP(v,d));
}
void init(int n){
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}

int vis[MAXN];
int dis[MAXN],ds; 
void dijkstra(int s,int n){
    for(int i=1;i<=n;i++)vis[i] = 0;
    for(int i=1;i<=n;i++)dis[i] = (i == s ? 0 : INF);
    priority_queue<PII,VII,greater<PII> >q;
	q.push(MP(dis[s],s));
    while(!q.empty()){
        PII p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(!vis[y]&&dis[x] + d < dis[y]){
                dis[y] = dis[x] + d;
                q.push(MP(dis[y],y));
            }
        }
    }
}

int i,j,n,m,k,a[1005][2],x,y,d[1005][1005],res[1005],w,r=1145141919;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		a[i][0]=x;a[i][1]=y;
		add_edge(x,y,w);add_edge(y,x,w);
	}
	
	for(i=1;i<=n;i++){
		dijkstra(i,n);
		for(j=1;j<=n;j++){
			//printf("%d %d %d\n",i,j,dis[j]);
			d[i][j]=dis[j];
		}
	}
	
	for(i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		if(x==y){continue;}
		for(j=1;j<=m;j++){
			//printf("%d %d %d %d %d\n",x,y,a[j][0],a[j][1],min(d[x][a[j][0]]+d[y][a[j][1]],d[x][a[j][1]]+d[y][a[j][0]]));
			res[j]+=min(min(d[x][a[j][0]]+d[y][a[j][1]],d[x][a[j][1]]+d[y][a[j][0]]),d[x][y]);
		}
	}
	
	for(i=1;i<=m;i++){
		r=min(r,res[i]);
	}
	
	printf("%d\n",r);
}