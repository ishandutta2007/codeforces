#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=2e5+5;
int n,k,fa[N],mxdep[N],dep[N],col[N];
vector<int>e[N];
bool in[N];
void dfs1(int p){
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa[p])continue;
		fa[v]=p,dep[v]=dep[p]+1,dfs1(v);
	}
}
void dfs2(int p){
	mxdep[p]=dep[p];
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa[p])continue;
		fa[v]=p,dep[v]=dep[p]+1,dfs2(v);
		mxdep[p]=max(mxdep[p],mxdep[v]);
	}
}
void dfs(int p,int ftcol,int det){
	if(det==1)col[p]=ftcol==k?1:ftcol+1;
	else col[p]=ftcol==1?k:ftcol-1;
	if(!in[p])for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa[p])continue;
		dfs(v,col[p],det);
	}
	else for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa[p])continue;
		if(in[v]){dfs(v,col[p],det);continue;}
		int cnt=0;
		if(mxdep[v]>=k)++cnt;
		if(mxdep[p]+mxdep[v]-dep[p]*2+1>=k)++cnt;
		if(cnt==2){
			puts("No");
			exit(0);
		}
		if(mxdep[v]>=k)dfs(v,col[p],1);
		else dfs(v,col[p],-1);
	}
}
inline void solve_2(int p,int cl){
	col[p]=cl;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa[p])continue;
		fa[v]=p,solve_2(v,3-cl);
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),k=read();
	for(ri i=1,u,v;i<n;++i){
		u=read(),v=read();
		e[u].pb(v);
		e[v].pb(u);
	}
	if(k==2){
		puts("Yes");
		solve_2(1,1);
		for(ri i=1;i<=n;++i)cout<<col[i]<<' ';
		exit(0);
	}
	dep[1]=1,dfs1(1);
	int top=0,bot=0;
	for(ri i=1;i<=n;++i)if(dep[i]>dep[top])top=i;
	for(ri i=1;i<=n;++i)fa[i]=dep[i]=0;
	dep[top]=1,dfs2(top);
	for(ri i=1;i<=n;++i)if(dep[i]>dep[bot])bot=i;
	while(bot){
		in[bot]=1;
		bot=fa[bot];
	}
	dfs(top,k,1);
	puts("Yes");
	for(ri i=1;i<=n;++i)cout<<col[i]<<' ';
	return 0;
}