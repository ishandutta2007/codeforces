#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
const int Maxn=200000;
int n,m;
std::vector<int> g[Maxn+5];
int num[Maxn+5],deg[Maxn+5];
int dis[Maxn+5];
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::greater<std::pair<int,int> > > q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int v,u;
		scanf("%d%d",&v,&u);
		deg[v]++,g[u].push_back(v);
	}
	memset(dis,0x3f,sizeof dis);
	dis[n]=0,q.push(std::make_pair(0,n));
	while(!q.empty()){
		std::pair<int,int> cur_u=q.top();
		q.pop();
		int u=cur_u.second;
		if(cur_u.first!=dis[u]){
			continue;
		}
		for(int v:g[u]){
			num[v]++;
			int val=dis[u]+deg[v]-num[v]+1;
			if(val<dis[v]){
				dis[v]=val;
				q.push(std::make_pair(val,v));
			}
		}
	}
	printf("%d\n",dis[1]);
	return 0;
}