#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int mm = 111111;
const int maxn = 999;
int node,src,dest,edge;
int ver[mm],flow[mm],cst[mm],nxt[mm];
int head[maxn],work[maxn],dis[maxn],q[maxn];
int tot_cost;
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; ++i)head[i]=-1;
    edge=0;
    tot_cost = 0;
}
void add_edge(int u,int v,int c,int cost)
{
    ver[edge]=v,flow[edge]=c,nxt[edge]=head[u],cst[edge]=cost,head[u]=edge++;
    ver[edge]=u,flow[edge]=0,nxt[edge]=head[v],cst[edge]=-cost,head[v]=edge++;
}

int ins[maxn];
int pre[maxn];
bool Dinic_spfa()
{
	memset(ins,0,sizeof(ins));
	memset(dis,-1,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	queue<int> Q;
    //int i,u,v,l,r=0;
    Q.push(src);
    dis[src] = 0,ins[src] = 1;
    pre[src] = -1;
    while(!Q.empty()){
    	int u = Q.front();Q.pop();
		ins[u] = 0;
		for(int e = head[u];e != -1;e = nxt[e]){
			int v = ver[e];
			if(!flow[e]) continue;
			if(dis[v] < 0 || dis[v] > dis[u] + cst[e]){
				dis[v] = dis[u] + cst[e];
				pre[v] = e;
				if(!ins[v]) ins[v] = 1,Q.push(v);
			}
		}    	
	}
    return dis[dest] != -1;
}
int Dinic_flow()
{
    int i,ret=0,delta=inf;
    while(Dinic_spfa())
    {
    	for(int i=pre[dest];i != -1;i = pre[ver[i^1]])
    		delta = min(delta,flow[i]);
		for(int i=pre[dest];i != -1;i = pre[ver[i^1]])
    		flow[i] -= delta,flow[i^1] += delta;
		ret+=delta;
		tot_cost += dis[dest]*delta;
    }
    return ret;
}
int getint() {  
    int x = 0, flag = 0; char ch = getchar();
    for(; !isdigit(ch); ch = getchar()) 
        if (ch == '-') flag = 1;
    for(; isdigit(ch); ch = getchar())
        x = x * 10 + ch - '0'; 
    return flag ? -x : x;
}
int n,m;
int mi[100],ma[100];
int main(){
	n = getint();
	m = getint();
	prepare(2*n+2,0,2*n+1);
	for(int i = 1;i <= n;++i){
		mi[i] = 1;
		ma[i] = n;
	}
	while(m--){
		int tp,l,r,v;
		tp = getint();
		l = getint();
		r = getint();
		v = getint();
		for(int i = l;i <= r;++i){
			if(tp == 1)
				mi[i] = max(mi[i],v);
			else
				ma[i] = min(ma[i],v);
			
			if(mi[i] > ma[i] || mi[i] < 1 || ma[i] > n) return 0*puts("-1");
		}
	} 
	for(int i = 1;i <= n;i++) add_edge(0,i,1,0);
	for(int i = 1;i <= n;i++) 
		for(int j = mi[i];j <= ma[i];++j)
			add_edge(i,j+n,1,0);
	for(int i = n+1;i <= 2*n;++i) 
		for(int j = 0;j < n;++j)
			add_edge(i,2*n+1,1,2*j+1);
	int f = Dinic_flow();
	cout<<tot_cost<<endl;
}