#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=401000,maxm=602000;
int n,m,q;
int head[maxn],rdc[maxm],nxt[maxm],tnt=1;
int dfn[maxn],low[maxn],con[maxn],bel[maxn],tsp;
int dcc,dep[maxn],f[19][maxn];
int dsum[maxn],usum[maxn];
bool bridge[maxm];
vector<int> e[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
}
void tarjan(int p,int fr){
	dfn[p]=low[p]=++tsp;
	for(register int i=head[p];i;i=nxt[i]){
		if(fr==i)continue;
		if(!dfn[rdc[i]]){
			con[rdc[i]]=con[p];// 
			tarjan(rdc[i],i^1);
			low[p]=min(low[p],low[rdc[i]]);
			if(low[rdc[i]]>dfn[p])
				bridge[i]=bridge[i^1]=true;
		}
		else
			low[p]=min(low[p],dfn[rdc[i]]);
	}
}
void color(int p){
	bel[p]=dcc;
	for(register int i=head[p];i;i=nxt[i])
		if(!bridge[i]){
			if(!bel[rdc[i]])
				color(rdc[i]);
		}
		else if(bel[rdc[i]]){
			e[dcc].push_back(bel[rdc[i]]);
			e[bel[rdc[i]]].push_back(dcc);
		}
}
void dfs(int p){
	for(register int i=1;f[i-1][p];++i)
		f[i][p]=f[i-1][f[i-1][p]];
	for(register int i=0;i<e[p].size();++i)
		if(f[0][p]!=e[p][i]){
			f[0][e[p][i]]=p;
			dep[e[p][i]]=dep[p]+1;
			dfs(e[p][i]);
		}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(register int i=18;~i;--i)
		if((dep[x]-dep[y])>>i)x=f[i][x];
	if(x==y)return x;
	for(register int i=18;~i;--i)
		if(f[i][x]!=f[i][y])
			x=f[i][x],y=f[i][y];
	return f[0][x];
}
bool check(int p){
	for(register int i=0;i<e[p].size();++i)
		if(f[0][p]!=e[p][i]){
			if(!check(e[p][i]))return false;
			dsum[p]+=dsum[e[p][i]];
			usum[p]+=usum[e[p][i]];
		}
	return !(dsum[p]&&usum[p]);
}
void output(bool fg){
	puts(fg?"Yes":"No");
}
int main(){
	n=read();m=read();q=read();
	for(register int i=1,u,v;i<=m;++i){
		u=read();v=read();
		add(u,v);add(v,u);
	}
	for(register int i=1;i<=n;++i)
		if(!dfn[i]){
			con[i]=i;
			tarjan(i,0);
		}
	for(register int i=1;i<=n;++i)
		if(!bel[i]){
			++dcc;
			color(i);
		}
	for(register int i=1;i<=dcc;++i)
		if(!f[0][i])
			dfs(i);
	for(register int i=1,s,t,l;i<=q;++i){
		s=read();t=read();
		if(con[s]!=con[t]){
			output(0);return 0;
		}
		s=bel[s];t=bel[t];
		l=lca(s,t);
		usum[s]++;dsum[t]++;
		usum[l]--;dsum[l]--;
	}
	for(register int i=1;i<=dcc;++i)
		if(!f[0][i]&&!check(i)){
			output(0);return 0;
		}
	output(1);
	return 0;
}