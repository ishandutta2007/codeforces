#include<bits/stdc++.h>
#define cl(a,x) memset(a,x,sizeof a)
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const ll N=1e5+7,inf=1e15+7;
int n,m,q,hd[N],vs[N];
ll d[N],dt[N];
queue<int>p[N];
priority_queue<pli>Q;
struct edge{
	int v,w,nxt;
	void f(int x){if(d[x]+w<d[v])d[v]=d[x]+w,Q.push({-d[v],v});}
}e[N];
void dij(){
	cl(d,9),Q.push({d[1]=0,1}),cl(vs,0);
	while(!Q.empty()){
		int x=Q.top().second;Q.pop();
		if(vs[x])continue;vs[x]=1;
		for(int i=hd[x];i;i=e[i].nxt)e[i].f(x);
	}
}
signed main(){
	scanf("%d%d%d",&n,&m,&q);
	FOR(i,1,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w),e[i]={v,w,hd[u]},hd[u]=i;
	}
	for(dij();q--;){
		int o,x,y;
		scanf("%d%d",&o,&x);
		if(o==1)printf("%lld\n",d[x]>inf?-1:d[x]);
		else{
			FOR(i,1,x)scanf("%d",&y),++e[y].w;
			cl(dt,9),cl(vs,0),p[dt[1]=0].push(1);
			FOR(i,0,x)while(!p[i].empty()){
				int u=p[i].front();p[i].pop();
				if(vs[u])continue;vs[u]=1;
				for(int i=hd[u];i;i=e[i].nxt){
					int to=e[i].v;ll vl=d[u]+e[i].w-d[to];
					if(dt[to]>dt[u]+vl){
						dt[to]=dt[u]+vl;
						if(dt[to]<=n&&dt[to]<=x)p[dt[to]].push(to);
					}
				}
			}
			FOR(i,1,n)if(dt[i]<=n)d[i]+=dt[i];
		}
	}
	return 0;
}