#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
typedef pair<int,int> pii;
typedef long long ll;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline ll readl(){
	ll ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline int Read(char*s){
	int top=0;
	char ch=gc();
	while(!isalpha(ch))ch=gc();
	while(isalpha(ch))s[++top]=ch,ch=gc();
	return top;
}
const int N=2e5+5;
int S,n,m,w[N],dfn[N],low[N],tot=0,stk[N],top=0,siz[N],col[N],sig=0;
bool vs[N];
ll sum[N];
vector<int>e[N],E[N];
void tarjan(int p,int fa){
	dfn[p]=low[p]=++tot,stk[++top]=p;
	vs[p]=1;
	for(ri i=0,v;i<e[p].size();++i){
		if(dfn[v=e[p][i]]){
			if(v==fa||!vs[v])continue;
			low[p]=min(low[p],dfn[v]);
		}
		else tarjan(v,p),low[p]=min(low[p],low[v]);
	}
	if(low[p]==dfn[p]){
		int x;
		++sig;
		while(1){
			x=stk[top--];
			++siz[sig];
			col[x]=sig;
			vs[x]=0;
			sum[sig]+=w[x];
			if(x==p)break;
		}
	}
}
ll F[N][2];
bool ok[N];
void dfs(int p,int fa){
	ok[p]=siz[p]>1;
	F[p][0]=sum[p];
	for(ri i=0,v;i<E[p].size();++i){
		if((v=E[p][i])==fa)continue;
		dfs(v,p);
		if(ok[v])F[p][0]+=F[v][0],ok[p]=1;
	}
	F[p][1]=F[p][0];
	for(ri i=0,v;i<E[p].size();++i){
		if((v=E[p][i])==fa)continue;
		if(ok[v])F[p][0]-=F[v][0];
		F[p][1]=max(F[p][1],F[p][0]+F[v][1]);
		if(ok[v])F[p][0]+=F[v][0];
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	for(ri i=1;i<=n;++i)w[i]=read();
	for(ri u,v,i=1;i<=m;++i){
		u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	S=read();
	tarjan(S,0);
	for(ri u=1,v;u<=n;++u)for(ri i=0;i<e[u].size();++i){
		v=e[u][i];
		if(col[u]==col[v])continue;
		E[col[u]].pb(col[v]);
	}
	dfs(col[S],0);
	cout<<max(F[col[S]][0],F[col[S]][1]);
	return 0;
}