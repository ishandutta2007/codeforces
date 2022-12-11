#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define nxt(x) ((x+1)%lap.size())
using namespace std; 
const int maxn=200010,INF=0x3f3f3f3f;
int n;
double ans;
int fa[maxn];
bool in[maxn];
int q[maxn<<1],qt,qe;
vector <int> v[maxn],lap;
vector <double> w[maxn],lapw;
double dlen[maxn];
double prea[maxn],preb[maxn];
double sufa[maxn],sufb[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
bool dfs(int p){
	in[p]=true;
	for(register int i=0;i<v[p].size();++i){
		if(v[p][i]==fa[p])continue;
		if(in[v[p][i]]){
			for(register int q=p;q!=v[p][i];q=fa[q]){
				lap.push_back(q);
				lapw.push_back(dlen[q]-dlen[fa[q]]);
			}
			lap.push_back(v[p][i]);
			lapw.push_back(w[p][i]);
			in[p]=false;
			return true;
		}
		fa[v[p][i]]=p;
		dlen[v[p][i]]=dlen[p]+w[p][i];
		if(dfs(v[p][i])){
			in[p]=false;
			return true;
		}
	}
	in[p]=false;
	return false;
}
void dfs2(int p){
	dlen[p]=0;
	for(register int i=0;i<v[p].size();++i){
		if(in[v[p][i]]||fa[p]==v[p][i])continue;
		fa[v[p][i]]=p;
		dfs2(v[p][i]);
		ans=max(ans,dlen[p]+w[p][i]+dlen[v[p][i]]);
		dlen[p]=max(dlen[p],w[p][i]+dlen[v[p][i]]);
	}
}
int main(){
	n=read();
	for(register int i=1,x,y,z;i<=n;++i){
		x=read();y=read();z=read();
		v[x].push_back(y);
		v[y].push_back(x);
		w[x].push_back(z);
		w[y].push_back(z);
	}
	dfs(1);
	for(register int i=0;i<lap.size();++i)
		in[lap[i]]=true;
	for(register int i=0;i<lap.size();++i){
		fa[lap[i]]=0;
		dfs2(lap[i]);
	}
	int sz=lap.size();
	double V,dsum=0;
	V=prea[0]=preb[0]=dlen[lap[0]];
	for(register int i=1;i<sz;++i){
		dsum+=lapw[i-1]; 
		prea[i]=max(prea[i-1],dlen[lap[i]]+dsum);
		preb[i]=max(preb[i-1],V+dlen[lap[i]]+dsum);
		V=max(V,dlen[lap[i]]-dsum);
	}
	dsum=0;
	V=sufa[sz-1]=sufb[sz-1]=dlen[lap[sz-1]];
	for(register int i=sz-2;~i;--i){
		dsum+=lapw[i]; 
		sufa[i]=max(sufa[i+1],dlen[lap[i]]+dsum);
		sufb[i]=max(sufb[i+1],V+dlen[lap[i]]+dsum);
		V=max(V,dlen[lap[i]]-dsum);
	}
	V=sufb[0];
	for(register int i=0;i<sz-1;++i)
		V=min(V,max(max(sufb[i+1],preb[i]),sufa[i+1]+prea[i]+lapw[sz-1]));
	ans=max(ans,V);
	printf("%.0lf",ans);
	return 0;
}