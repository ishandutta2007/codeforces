#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=301000;
int n,m,q,rt;
int fa[maxn],pre[maxn],dep[maxn];
vector <int> e[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int getfa(int x){
	return fa[x]==x?x:(fa[x]=getfa(fa[x]));
}
void dfs(int p){
	for(register int i=0;i<e[p].size();++i)
		if(pre[p]!=e[p][i]){
			pre[e[p][i]]=p;
			fa[e[p][i]]=fa[p];
			dep[e[p][i]]=dep[p]+1;
			dfs(e[p][i]);
		}
	if(dep[p]>dep[rt])rt=p;
}
int main()
{
	n=read();m=read();q=read();
	for(register int i=0,u,v;i<m;++i){
		u=read();v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(register int i=1,u;i<=n;++i)
		if(!fa[i]){
			dep[i]=0;rt=i;dfs(i);
			u=rt;
			fa[u]=u;dep[u]=pre[u]=0;
			dfs(u);
			dep[u]=dep[rt];
		}
	for(register int i=0,u,v;i<q;++i){
		if(read()&1)
			printf("%d\n",dep[getfa(read())]);
		else{
			u=getfa(read());v=getfa(read());
			if(u==v)continue;
			if(dep[u]>dep[v])swap(u,v);
			dep[v]=max(dep[v],((dep[v]+1)>>1)+((dep[u]+1)>>1)+1);
			fa[u]=v;
		}
	}
	return 0;
}