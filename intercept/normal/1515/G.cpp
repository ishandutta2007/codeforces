#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int M=2e5+9;
int n,m,q,id,tot;
int dfn[M],low[M],s[M];
ll p[M],c[M];
vector<pii>g[M];
bool in[M];
void dfs(int u){
	int x=dfn[u]=low[u]=++id;
	in[u]=1;
	s[++tot]=u;
	for(auto o:g[u]){
		int v=o.first,w=o.second;
		if(!dfn[v])p[v]=p[u]+w,dfs(v);
		if(in[v]){
			low[u]=min(low[u],low[v]);
			c[u]=__gcd(c[u],p[u]-p[v]+w);
			c[u]=__gcd(c[u],c[v]);
		}
	}
	if(dfn[u]==low[u]){
		int v=0;
		while(u!=v){
			v=s[tot--];
			c[v]=c[u];
			in[v]=0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		g[u].emplace_back(v,w);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])dfs(i);
	}
	scanf("%d",&q);
	for(int i=1,u,v,w;i<=q;++i){
		scanf("%d%d%d",&u,&v,&w);
		w=__gcd(c[u],1ll*w);
		puts(v%w==0?"YES":"NO");
	}
	return 0;
}