#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=200100;
int n,m,a[maxn],tr[2][maxn];
int dep[maxn],dfn[maxn],siz[maxn],tsp;
vector <int> e[maxn]; 
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void modify(int p,int x,bool o){
	while(p<=n)tr[o][p]+=x,p+=p&-p;
}
int query(int p,bool o){
	int res=0;
	while(p)res+=tr[o][p],p-=p&-p;
	return res;
}
void dfs(int p){
	dfn[p]=++tsp;
	siz[p]=1;
	for(register int i=0;i<e[p].size();++i)
		if(!siz[e[p][i]]){
			dep[e[p][i]]=dep[p]^1;
			dfs(e[p][i]);
			siz[p]+=siz[e[p][i]];
		}
}
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;++i)
		a[i]=read(); 
	for(register int i=1;i<n;++i){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	for(register int i=0,p,val;i<m;++i){
		if(read()&1){
			p=read();val=read();
			modify(dfn[p],val,dep[p]);modify(dfn[p]+siz[p],-val,dep[p]);
			modify(dfn[p],-val,dep[p]^1);modify(dfn[p]+siz[p],val,dep[p]^1);
		}
		else{
			p=read();
			printf("%d\n",query(dfn[p],dep[p])+a[p]);
		}
	}
	return 0;
}