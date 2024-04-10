// Hydro submission #621f010123895d6595ab3f71@1646199042802
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> Int;
const int N=2e5+5;
int n,m,id[N][4],vis[N*4];
ll dis[N*4];
vector<Int> e[N*4];
priority_queue<Int,vector<Int>,greater<Int> > q;
void add(int x,int y,int z){
	e[id[x][0]].emplace_back(id[y][0],z);
	e[id[y][1]].emplace_back(id[x][1],z);
	e[id[y][2]].emplace_back(id[x][2],z);
	e[id[y][3]].emplace_back(id[x][3],z);
	e[id[x][0]].emplace_back(id[y][1],0);
	e[id[x][0]].emplace_back(id[y][2],2*z);
	e[id[x][0]].emplace_back(id[y][3],z);
	e[id[x][1]].emplace_back(id[y][3],2*z);
	e[id[x][2]].emplace_back(id[y][3],0);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)id[i][0]=i,id[i][1]=n+i,id[i][2]=2*n+i,id[i][3]=3*n+i;
	for(int i=1;i<=m;i++){
		int x,y;ll z;
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	memset(dis,63,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	priority_queue<Int,vector<Int>,greater<Int> > q;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto i:e[x]){
			int y=i.first,z=i.second;
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				q.push(make_pair(dis[y],y));
			}
		}
	}
	for(int i=2;i<=n;i++)printf("%lld ",dis[id[i][3]]);
}
/*
5 4
5 3 4
2 1 1
3 2 2
2 4 2
*/