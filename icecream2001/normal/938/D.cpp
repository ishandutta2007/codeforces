#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
#define N 300050
#define pa pair<LL,int>
using namespace std;
int n,m,cnt=0;
int hed[N];
LL dis[N];
bool vis[N];
struct edge{
	int r,nxt;
	LL v;
}e[500000];
priority_queue<pa,vector< pa >,greater< pa > >Q;
void dijkstra(){
    int now;LL G;
    while(!Q.empty()){
        now=Q.top().second;G=Q.top().first;Q.pop();
        if(vis[now]) continue;
        else vis[now]=1;
        for(int i=hed[now];i;i=e[i].nxt){
            if(G+e[i].v+e[i].v<dis[e[i].r]){
                dis[e[i].r]=G+e[i].v+e[i].v;
                Q.push(make_pair(dis[e[i].r],e[i].r));
            }
        }
    }
    return;
}
void insert(int u,int v,LL w){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;e[cnt].v=w;
}
int main(){
	int u,v;LL w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%I64d",&u,&v,&w);
		insert(u,v,w);insert(v,u,w);
	}
	for(int i=1;i<=n;i++){
		scanf("%I64d",&dis[i]);
		Q.push(make_pair(dis[i],i));
	}
	dijkstra();
	for(int i=1;i<n;i++){
		printf("%I64d ",dis[i]);
	}
	printf("%I64d ",dis[n]);
	return 0;
}