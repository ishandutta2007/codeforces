#include<bits/stdc++.h>
using namespace std;
const int N = 2.5e5+5;
typedef pair<int,int> pi;

int par[N];
inline int find(int x){
	return par[x]==x?par[x]:find(par[x]);
}
inline void merge(int u,int v){
	u=find(u),v=find(v);
	par[u]=v;
}
bool iscon(int a,int b){
	return find(a)==find(b);
}

namespace Tree1{
	vector<int> g[N];
	inline void adde(int u,int v){
		g[u].push_back(v);
	}
	inline void read(int n){
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			adde(u,v),adde(v,u);
		}
	}
	int anc[N][20];
	int dep[N];
	inline void dfs(int x,int pre){
		// cout << x << ":" << pre << endl;
		dep[x] = dep[pre]+1;
		anc[x][0]=pre;for(int i=1;i<20;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
		for(size_t i=0;i<g[x].size();i++){
			int v=g[x][i];if(v==pre)continue;
			dfs(v,x);
		}
	}
	inline int Lca(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		for(int i=19;~i;i--)if(dep[anc[a][i]]>=dep[b])a=anc[a][i];
		if(a==b)return a;
		for(int i=19;~i;i--)if(anc[a][i]!=anc[b][i])a=anc[a][i],b=anc[b][i];
		return anc[a][0];
	}
}

pi consider[N];int num;
namespace Tree2{
	vector<pi> g[N];
	pi e[N];
	inline void adde(int u,int v,int id){
		g[u].push_back(pi(v,id));
	}
	inline void read(int n){
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			adde(u,v,i),adde(v,u,i);
		}
	}
	int fa[N];
	inline void dfs(int x,int pre){
		for(size_t i=0;i<g[x].size();i++){
			if(g[x][i].first!=pre)
				dfs(g[x][i].first,x);
		}
		if(pre)consider[++num]=pi(x,pre);
	}
}

int n;

int main()
{
	cin >> n;
	Tree1::read(n),Tree2::read(n);
	Tree1::dfs(1,0),Tree2::dfs(1,0);
	using namespace Tree1;
	for(int i=1;i<=n;i++)par[i]=i;
	cout << n-1 << endl;
	for(int T=1;T<=num;T++){
		int u=consider[T].first,v=consider[T].second;
		int lca = Lca(u,v);
		int Temp = find(u);
		if(iscon(lca,u)){
			Temp=v;
			for(int j=19;~j;j--)if(dep[anc[Temp][j]]>=dep[lca]){
				if(!iscon(anc[Temp][j],lca))Temp=anc[Temp][j];
			}
		}
		printf("%d %d %d %d\n",Temp,anc[Temp][0],u,v);
		merge(Temp,anc[Temp][0]);
	}
	
}