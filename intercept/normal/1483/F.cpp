#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=1000009;
int n,sz,ans,id;
int f[M],last[M],las[M],b[M],siz[M],dfn[M],ed[M],c[M][31];
char s[M];
vector<int>t[M],g[M];
void build(int x){
	scanf("%s",s+1);
	int m=strlen(s+1),u=0;
	t[x].resize(m+1);
	for(int i=1;i<=m;++i){
		int v=s[i]-'a'+1;
		t[x][i]=v;
		if(!c[u][v])c[u][v]=++sz;
		u=c[u][v];
		if(i==m)ed[u]=x,las[x]=u;
	}
}
void dfs(int u){
	dfn[u]=++id;siz[u]=1;
	for(auto v:g[u])dfs(v),siz[u]+=siz[v];
} 
void getfail(){
	queue<int>q;
	for(int i=1;i<=26;++i)if(c[0][i])q.push(c[0][i]);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=26;++i){
			int v=c[u][i],x=f[u];
			if(v)f[v]=c[x][i],q.push(v);
			else c[u][i]=c[x][i];
		}
		ed[u]=ed[u]?ed[u]:ed[f[u]];
	}
	for(int i=1;i<=sz;++i)g[f[i]].eb(i);
	dfs(0);
}
void add(int i,int v){for(;i<M;i+=i&-i)b[i]+=v;}
int sum(int i,int rex=0){for(;i;i-=i&-i)rex+=b[i];return rex;}
void find(int x){
	int m=t[x].size()-1,u=0,pre=m;
	vector<int>p;p.eb(0);
	map<int,int>cnt;
	for(int i=1;i<=m;++i)p.eb(u=c[u][t[x][i]]);
	for(int i=m;i>=1;--i){
		int l=i==m?ed[f[p[i]]]:ed[p[i]];
		add(dfn[p[i]],1);
		if(!l)continue;
		if(i-t[l].size()+1<pre){
			pre=i-t[l].size()+1;
			cnt[l]++;
		}
	}
	for(auto o:cnt){
		int u=las[o.first];
		if(o.second==sum(dfn[u]+siz[u]-1)-sum(dfn[u]-1))ans++;
	}
	for(int i=1;i<=m;++i)add(dfn[p[i]],-1);
	
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)build(i);
	getfail();
	for(int i=1;i<=n;++i)find(i);
	printf("%d\n",ans);
	return 0;
}
/* 
5
hidan
dan
hanabi
bi
nabi



*/