#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 200005
#define inf 1e18
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,a,b,c,ecnt,last[N];ll dist[N][5];
struct node
{
	int x,y;ll v;
	friend bool operator<(node t1,node t2) {return t1.v>t2.v;}
}top;
std::priority_queue<node>H;
struct road{int to,v,nex;}e[N<<1];
void adde(int u,int v,int w) {e[++ecnt]=(road){v,w,last[u]},last[u]=ecnt;}
void Dijkstra(int S)
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<4;j++) dist[i][j]=inf;
	H.push({1,0,dist[1][0]=0});
	for(int x,y;!H.empty();)
	{
		top=H.top(),H.pop(),x=top.x,y=top.y;
		if(dist[x][y]^top.v) continue;
		// dbg1(x),dbg1(y),dbg2(top.v);
		for(int k=last[x];k;k=e[k].nex)
		{
			if(dist[e[k].to][y]>top.v+e[k].v)
				H.push({e[k].to,y,dist[e[k].to][y]=top.v+e[k].v});
			if(!(y&1)&&dist[e[k].to][y|1]>top.v)
				H.push({e[k].to,y|1,dist[e[k].to][y|1]=top.v});
			if(!(y&2)&&dist[e[k].to][y|2]>top.v+2*e[k].v)
				H.push({e[k].to,y|2,dist[e[k].to][y|2]=top.v+2*e[k].v});
		}
	}
	// for(int i=1;i<=n;i++,puts(""))
		// for(int j=0;j<4;j++) printf("%lld ",dist[i][j]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a,&b,&c),adde(a,b,c),adde(b,a,c);
	Dijkstra(1);
	for(int i=2;i<=n;i++) printf("%lld ",min(dist[i][0],dist[i][3]));
	return 0;
}