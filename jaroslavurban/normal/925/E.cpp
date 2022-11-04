#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// solving tree path queries in n^2
// tu[u] maps vertices to new value 0,1,... which is equivalent to the index of all
// needed values of that vertex (k[u],b[u],comp[u],tin[u],tout[u],p[u])
// if two vertices are part of the same comp, the path between them is just u,u+1,u+2,..,v

const int N=100100;
vector<int>g[N];
int sz[N],tu[N],tim,cnu=-1;
int p[N],comp[N];
int tmpt[N],t[N],here[N];

int dfsz(int u,int par){
	sz[u]=1;
	for(int v:g[u])sz[u]+=dfsz(v,u);
	sort(g[u].begin(),g[u].end(),[&](int a,int b){
		return sz[a]>sz[b];
	});
	return sz[u];
}

void dfs(int u,int par){
	int &nu=tu[u]=++cnu;
	p[nu]=par;
	t[nu]=tmpt[u];
	here[nu]=true;
	for(int i=0;i<g[u].size();++i)
		if(i)dfs(g[u][i],nu);
		else{
			comp[cnu+1]=comp[nu];
			dfs(g[u][i],par);
		}
}


int walk(int u,int df){
	int chngs=0;
	while(~u){
		for(int i=comp[u];i<=u;++i){
			t[i]+=df;
			chngs+=here[i]&&t[i]<0!=t[i]-df<0;
		}
		u=p[u];
	}
	return chngs;
}

void ProGamerMove(){
	int n,q;cin>>n>>q;
	for(int i=1;i<n;++i){
		int u;cin>>u;--u;g[u].push_back(i);
	}
	for(int i=0;i<n;++i)cin>>tmpt[i];
	iota(comp,comp+n,0);
	dfsz(0,0);
	dfs(0,-1);
	int tot=0,u,df;
	while(q--){
		cin>>u;
		df=2*(u<0)-1; // -1 => leaves
		u=tu[abs(u)-1];
		tot-=df*walk(u,df);
		if(df==-1&&t[u]<0)--tot;
		if(df==+1&&t[u]<0)++tot;
		here[u]=df==+1;
		cout<<tot<<" ";
	}
	cout<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	//cin>>tc;
	while(tc--)ProGamerMove();
}