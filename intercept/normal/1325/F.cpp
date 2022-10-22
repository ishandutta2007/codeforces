#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,m,block,top;
int ms[M],dep[M],s[M];
bool vis[M];
vector<int>g[M],d[M];
void dfs(int u){
	vis[u]=1;
	s[++top]=u;
	vector<int>b; 
	for(auto v:g[u])b.eb(ms[v]);
	int bm=0;
	sort(b.begin(),b.end());
	for(auto o:b)if(o==bm+1)bm++;
	ms[u]=bm+1;
	d[ms[u]].eb(u);
	for(auto v:g[u]){
		if(!vis[v])dep[v]=dep[u]+1,dfs(v);
		else if(dep[u]-dep[v]+1>=block){
			printf("2\n");
			printf("%d\n",dep[u]-dep[v]+1);
			while(u!=v){
				printf("%d ",u);
				u=s[--top];
			}
			printf("%d\n",v);
			exit(0);
		}
	}
	top--;
}
int main(){
	scanf("%d%d",&n,&m);
	int z=sqrt(n);
	block=z+(n>z*z);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	for(int i=1;i<=n;++i)if(!vis[i])dfs(i);
	for(int i=1;i<=n;++i){
		if(d[i].size()>=block){
			printf("1\n");
			for(int j=0;j<block;++j)printf("%d ",d[i][j]);
			return 0;
		}
	}
	return 0;
}