#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1001000;
const int INF=1e9;
int n,L,U;
int head[maxn],nxt[maxn<<1],rdc[maxn<<1],w[maxn<<1],tnt;
int prt,rt,asiz;
int siz[maxn],mdep[maxn];
int fdep,gdep;
int f[maxn],g[maxn],fp[maxn],gp[maxn],dta;
int q[maxn],qt,qe;
int ansu,ansv;
vector <int> v[maxn],t[maxn];
bool vis[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
bool cmp(int x,int y){
	return mdep[rdc[x]]<mdep[rdc[y]];
}
void add(int x,int y,int z){
	nxt[++tnt]=head[x];
	head[x]=tnt;
	rdc[tnt]=y;
	w[tnt]=z;
}
void findrt(int p,int f){
	int res=0;
	siz[p]=1;
	for(register int i=head[p];i;i=nxt[i])
		if(rdc[i]!=f&&!vis[rdc[i]]){
			findrt(rdc[i],p);
			res=max(res,siz[rdc[i]]);
			siz[p]+=siz[rdc[i]];
		}
	res=max(res,asiz-siz[p]);
	if(res<=(asiz>>1))rt=p;
}
void builddfs(int p,int f){
	siz[p]=1;
	for(register int i=head[p];i;i=nxt[i])
		if(rdc[i]!=f&&!vis[rdc[i]]){
			mdep[rdc[i]]=mdep[p]+1;
			builddfs(rdc[i],p);
			siz[p]+=siz[rdc[i]];
		}
	for(register int i=head[p];i;i=nxt[i])
		if(rdc[i]!=f&&!vis[rdc[i]])
			mdep[p]=max(mdep[p],mdep[rdc[i]]);
}
void build(int p){
	vis[p]=true;
	mdep[p]=0;
	for(register int i=head[p];i;i=nxt[i]){
		if(vis[rdc[i]])continue;
		mdep[rdc[i]]=1;
		builddfs(rdc[i],p);
		mdep[p]=max(mdep[p],mdep[rdc[i]]);
		v[p].push_back(i);
	}
	sort(v[p].begin(),v[p].end(),cmp); 
	for(register int i=head[p];i;i=nxt[i]){
		if(vis[rdc[i]])continue;
		asiz=siz[rdc[i]];
		findrt(rdc[i],p);
		t[p].push_back(rt);
		build(rt);
	}
	vis[p]=false;
}
void dfs(int p,int f,int dep,int pv){
	if(g[dep]<pv){
		g[dep]=pv;
		gp[dep]=p;
	}
	for(register int i=head[p];i;i=nxt[i])
		if(rdc[i]!=f&&!vis[rdc[i]])
			dfs(rdc[i],p,dep+1,pv+(w[i]>=dta?1:-1));
	gdep=max(gdep,dep);
}
bool check(int p){
	if((mdep[p]<<1)<L)return false;
	bool flag=false;
	vis[p]=true;
	fp[0]=gp[0]=p;
	for(register int i=0;i<v[p].size()&&!flag;++i){
		dfs(rdc[v[p][i]],p,1,(w[v[p][i]]>=dta?1:-1));
		qt=1;qe=0;
		for(register int j=0,k=min(fdep,U);j<=gdep;++j){
			while(qt<=qe&&q[qt]+j>U)++qt;
			while(j+k>=L&&k>=0){
				while(qt<=qe&&f[q[qe]]<=f[k])--qe;
				q[++qe]=k;
				--k;
			}
			if(qt<=qe&&g[j]+f[q[qt]]>=0){
				flag=true;
				ansu=gp[j];ansv=fp[q[qt]];
				break;
			}
		}
		fdep=gdep;
		while(gdep){
			if(f[gdep]<g[gdep]){
				f[gdep]=g[gdep];
				fp[gdep]=gp[gdep];
			}
			g[gdep]=-INF;--gdep;
		}
	}
	while(fdep){
		f[fdep]=-INF;--fdep;
	}
	if(flag){
		vis[p]=false;return true;
	}
	for(register int i=0;i<t[p].size();++i)
		if(check(t[p][i])){
			vis[p]=false;return true;
		}
	vis[p]=false;
	return false;
}
int main(){
	n=read();L=read();U=read();
	for(int i=1,x,y,z;i<n;++i){
		x=read();y=read();z=read();
		add(x,y,z);
		add(y,x,z);
	}
	asiz=n;
	findrt(1,0);
	build(prt=rt);
	for(register int i=0;i<=n;++i)
		f[i]=g[i]=-INF;
	f[0]=g[0]=0;
	int l=-1,r=1e9;
	while(l<r){
		dta=(l+r+1)>>1;
		if(check(prt))l=dta;
		else r=dta-1;
	}
	dta=l;
	check(l);
	printf("%d %d\n",ansu,ansv);
	return 0;
}