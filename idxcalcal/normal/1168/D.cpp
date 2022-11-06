#include<bits/stdc++.h>
#define ri register int
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
inline int gcr(){
	char ch=gc();
	while(!isalpha(ch)&&ch!='?')ch=gc();
	return ch=='?'?26:ch-'a';
}
const int N=150005;
int n,m,fa[N],f[N],dep[N],cnt[N][27],ss[N],mx[N][27],all[N],vl[N],mxdep,du[N],ban=0;
vector<int>e[N];
inline int find(const int&x){return x^f[x]?f[x]=find(f[x]):x;}
void dfs(int p){
	for(ri i=0,v;i<e[p].size();++i){
		dfs(v=e[p][i]);
		for(ri j=0;j<26;++j)mx[p][j]=max(mx[p][j],mx[v][j]+cnt[v][j]);
	}
	for(ri i=0;i<26;++i)ss[p]+=mx[p][i];
	ban+=ss[p]>(mxdep-dep[p]);
}
inline void update(int p,int V,int type){
	cnt[p][V]+=type;
	for(ri i=fa[p];i;i=fa[i]){
		ban-=ss[i]>mxdep-dep[i];
		ss[i]-=mx[i][V];
		mx[i][V]=0;
		for(ri j=0,v;j<e[i].size();++j){
			v=e[i][j];
			mx[i][V]=max(mx[i][V],mx[v][V]+cnt[v][V]);
		}
		ss[i]+=mx[i][V];
		ban+=ss[i]>mxdep-dep[i];
	}
}
inline void query(){
	if(ban){
		puts("Fou");
		return;
	}
	int res=0;
	for(ri i=0;i<26;++i)res+=(i+1)*(mxdep-ss[1]+mx[1][i]);
	cout<<"Shi "<<res<<'\n';
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	for(ri i=2;i<=n;++i)fa[i]=read(),vl[i]=gcr(),dep[i]=dep[fa[i]]+1,++du[fa[i]];
	for(ri i=1;i<=n;++i){
		if(du[i])continue;
		if(!mxdep)mxdep=dep[i];
		if(mxdep^dep[i]){
			while(m--)puts("Fou");
			return 0;
		}
	}
	for(ri i=1;i<=n;++i){
		f[i]=i;
		if(fa[i]>1&&du[fa[i]]<2){
			f[fa[i]]=i;
			fa[i]=fa[fa[i]];
		}
	}
	for(ri i=2;i<=n;++i){
		f[i]=find(i);
		if(f[i]==i)e[fa[i]].push_back(i);
		if(vl[i]<26)++cnt[f[i]][vl[i]];
	}
	dfs(1);
	for(ri i=1,x;i<=m;++i){
		x=read();
		if(vl[x]^26)update(f[x],vl[x],-1);
		vl[x]=gcr();
		if(vl[x]^26)update(f[x],vl[x],1);
		query();
	}
	return 0;
}