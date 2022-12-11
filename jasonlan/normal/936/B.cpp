#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=200010;
int n,m,rt;
int dfn[maxn],low[maxn],tsp;
int s[maxn],st;
bool vis[2][maxn],out[maxn];
vector <int> v[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
bool dfs(bool wk,int p){
	if(vis[wk][p])return false;
	s[++st]=p;
	if(!v[p].size()){
		if(!wk)--st;
		return wk;
	}
	vis[wk][p]=true;
	for(register int i=0;i<v[p].size();++i)
		if(dfs(wk^1,v[p][i]))return true;
	--st;
	return false;
}
bool dfs2(int p){
	s[++st]=p;
	dfn[p]=low[p]=++tsp;
	for(register int i=0;i<v[p].size();++i)
		if(!dfn[v[p][i]]){
			if(dfs2(v[p][i]))return true;
			low[p]=min(low[p],low[v[p][i]]);
		}
		else if(!out[v[p][i]])
			low[p]=min(low[p],dfn[v[p][i]]);
	if(dfn[p]==low[p]){
		if(s[st]==p)--st;
		else return true;
	}
	out[p]=true;
	return false;
}
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;++i)
		for(register int j=read();j;--j)
			v[i].push_back(read());
	rt=read();
	if(dfs(0,rt)){
		puts("Win");
		for(register int i=1;i<=st;++i)
			printf("%d ",s[i]);
	}
	else if(dfs2(rt))puts("Draw");
	else puts("Lose");
    return 0;
}