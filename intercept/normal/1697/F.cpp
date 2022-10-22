#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=3e4+9;
int n,m,k,num;
int a[M];
vector<int>g[M*22],h[M*22];
int id[M][11][2];
vector<int>p;
bool vis[M*22];
int in[M*22];
void add(int x,int y){
	g[x].eb(y);
	h[y].eb(x);
}
void dfs1(int u){
	vis[u]=1;
	for(auto v:g[u]){
		if(!vis[v]){
			dfs1(v);
		}
	}
	p.eb(u);
}
void dfs2(int u,int k){
	vis[u]=0;
	in[u]=k;
	for(auto v:h[u]){
		if(vis[v])dfs2(v,k);
	}
}
void work(){
	num=0;
	p.clear();
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=k+1;++j){
			for(int o=0;o<2;++o){
				id[i][j][o]=++num;
				g[num].clear();
				h[num].clear();
			}
		}
	}
	for(int i=1;i<=n;++i){
		add(id[i][k+1][1],id[i][k+1][0]);
		add(id[i][1][0],id[i][1][1]);
		for(int j=1;j<=k;++j){
			if(j>1)add(id[i][j][1],id[i][j-1][1]);
			if(j<k)add(id[i][j][0],id[i][j+1][0]);
		}
		if(i<n){
			for(int j=1;j<=k;++j){
				add(id[i][j][1],id[i+1][j][1]);
				add(id[i+1][j][0],id[i][j][0]);
			}
		}
	}
	for(int i=1;i<=m;++i){
		int o,x,y,z;
		scanf("%d",&o);
		if(o==1){
			scanf("%d%d",&x,&z);
			add(id[x][z][1],id[x][z+1][1]);
			add(id[x][z+1][0],id[x][z][0]);
		}
		if(o==2){
			scanf("%d%d%d",&x,&y,&z);
			z++;
			for(int i=max(z-k-1,1);i<=min(k+1,z-1);++i){
				add(id[x][i][1],id[y][z-i][0]);
				add(id[y][i][1],id[x][z-i][0]);
			}
		}
		if(o==3){
			scanf("%d%d%d",&x,&y,&z);
			z++;
			for(int i=max(z-k-1,1);i<=min(k+1,z-1);++i){
				add(id[x][i][0],id[y][z-i][1]);
				add(id[y][i][0],id[x][z-i][1]);
			}
		}
	}
	for(int i=1;i<=num;++i)vis[i]=in[i]=0;
	for(int i=1;i<=num;++i){
		if(!vis[i]){
			dfs1(i);
		}
	}
	int block=0;
	reverse(p.begin(),p.end());
	for(auto o:p){
		if(vis[o])dfs2(o,++block);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			if(in[id[i][j][1]]>in[id[i][j][0]])a[i]=j;
			if(in[id[i][j][0]]==in[id[i][j][1]]){
				puts("-1");
				return;
			}
		}
	}
	for(int i=1;i<=n;++i)printf("%d%c",a[i]," \n"[i==n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
2
2 0 3

2 1 2

2 1 2 4




*/