#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int Maxn=200000;
int n,m;
int head[Maxn+5],arrive[Maxn<<1|5],val[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to,int w){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
	val[tot]=w;
}
ll dis[Maxn+5][2][2];
priority_queue<pair<ll,pair<int,int> >,vector<pair<ll,pair<int,int> > >,greater<pair<ll,pair<int,int> > > > q;
void dij(){
	memset(dis,0x3f,sizeof dis);
	dis[1][0][0]=0;
	q.push(make_pair(0,make_pair(1,0)));
	while(!q.empty()){
		pair<ll,pair<int,int> > x=q.top();
		q.pop();
		int u_x=x.second.first,m_1=x.second.second>>1,m_2=x.second.second&1;
		if(dis[u_x][m_1][m_2]!=x.first){
			continue;
		}
		for(int i=head[u_x];i;i=nxt[i]){
			int v=arrive[i];
			if(dis[u_x][m_1][m_2]+val[i]<dis[v][m_1][m_2]){
				dis[v][m_1][m_2]=dis[u_x][m_1][m_2]+val[i];
				q.push(make_pair(dis[v][m_1][m_2],make_pair(v,m_1<<1|m_2)));
			}
			if(m_1==0&&dis[u_x][m_1][m_2]<dis[v][m_1+1][m_2]){
				dis[v][m_1+1][m_2]=dis[u_x][m_1][m_2];
				q.push(make_pair(dis[v][m_1+1][m_2],make_pair(v,(m_1+1)<<1|m_2)));
			}
			if(m_2==0&&dis[u_x][m_1][m_2]+(val[i]<<1)<dis[v][m_1][m_2+1]){
				dis[v][m_1][m_2+1]=dis[u_x][m_1][m_2]+(val[i]<<1);
				q.push(make_pair(dis[v][m_1][m_2+1],make_pair(v,m_1<<1|(m_2+1))));
			}
			if(m_1==0&&m_2==0&&dis[u_x][m_1][m_2]+val[i]<dis[v][m_1+1][m_2+1]){
				dis[v][m_1+1][m_2+1]=dis[u_x][m_1][m_2]+val[i];
				q.push(make_pair(dis[v][m_1+1][m_2+1],make_pair(v,(m_1+1)<<1|(m_2+1))));
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dij();
	for(int i=2;i<=n;i++){
		printf("%lld ",dis[i][1][1]);
	}
	puts("");
	return 0;
}