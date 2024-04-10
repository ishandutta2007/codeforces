#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int mod=1e9+7;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){a=add(a,b);}
inline void Dec(int&a,int b){a=dec(a,b);}
inline void Mul(int&a,int b){a=mul(a,b);}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
const int N=2e5+5;
vector<int>e[N],E[N];
int n,a[N],b[N],mu[N],phi[N],pri[N],inv[N],tot=0,F[N];
bool vs[N];
inline void init(){
	phi[1]=inv[1]=mu[1]=1;
	for(ri i=2;i<=n;++i){
		inv[i]=mul(inv[mod-mod/i*i],mod-mod/i);
		if(!vs[i])pri[++tot]=i,phi[i]=i-1,mu[i]=mod-1;
		for(ri j=1,up=n/i;j<=tot&&pri[j]<=up;++j){
			vs[i*pri[j]]=1;
			if(i==i/pri[j]*pri[j]){
				mu[i*pri[j]]=0;
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
			mu[i*pri[j]]=mu[i]?mod-mu[i]:0;
		}
	}
	for(ri i=1;i<=n;++i)for(ri j=i,t=1;j<=n;j+=i,++t)Add(F[j],mul(i,mul(inv[phi[i]],mu[t])));
}
int siz[N],top[N],dep[N],fa[N],hson[N],dfntot=0,dfn[N];
void dfs1(int p){
	siz[p]=1;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa[p])continue;
		fa[v]=p,dep[v]=dep[p]+1,dfs1(v),siz[p]+=siz[v];
		(siz[v]>siz[hson[p]])&&(hson[p]=v);
	}
}
void dfs2(int p,int tp){
	dfn[p]=++dfntot,top[p]=tp;
	if(!hson[p])return;
	dfs2(hson[p],tp);
	for(ri i=0,v;i<e[p].size();++i)((v=e[p][i])!=hson[p]&&v!=fa[p])&&(dfs2(v,v),1);
}
inline int lca(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
bool key[N];
int tp=0,stk[N];
inline void insert(int x){
	if(tp<2){stk[++tp]=x;return;}
	int t=lca(x,stk[tp]);
	if(t==stk[tp]){stk[++tp]=x;return;}
	while(dfn[stk[tp]]>dfn[t]){
		if(dfn[t]>=dfn[stk[tp-1]]){
			E[t].pb(stk[tp]),--tp;
			if(t^stk[tp])stk[++tp]=t;
			stk[++tp]=x;
			return;
		}
		E[stk[tp-1]].pb(stk[tp]),--tp;
	}
}
int res=0,ss,ss1[N],ss2[N];
void dfs(int p){
	ss1[p]=ss2[p]=0;
	for(ri i=0,v;i<E[p].size();++i){
		v=E[p][i];
		dfs(v);
		Add(ss2[p],ss2[v]);
		Add(ss1[p],ss1[v]);
	}
	if(key[p]){
		Add(ss,dec(mul(ss2[p],phi[a[p]]),mul(ss1[p],mul(phi[a[p]],dep[p]))));
		Add(ss2[p],mul(phi[a[p]],dep[p]));
		Add(ss1[p],phi[a[p]]);
	}
	for(ri i=0,v;i<E[p].size();++i){
		v=E[p][i];
		Dec(ss2[p],ss2[v]);
		Dec(ss1[p],ss1[v]);
		Add(ss,mul(ss1[v],ss2[p]));
		Add(ss,mul(ss1[p],ss2[v]));
		Dec(ss,mul(mul(2,dep[p]),mul(ss1[v],ss1[p])));
		Add(ss2[p],ss2[v]);
		Add(ss1[p],ss1[v]);
	}
}
void clear(int p){
	key[p]=0;
	for(ri i=0;i<E[p].size();++i)clear(E[p][i]);
	E[p].clear();
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	init();
	for(ri i=1;i<=n;++i)b[a[i]=read()]=i;
	for(ri i=1,u,v;i<n;++i){ 
		u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1),dfs2(1,1);
	vector<pii>t;
	for(ri d=1;d<=n;++d){
		t.clear();
		for(ri p=d;p<=n;p+=d)t.pb(pii(dfn[b[p]],b[p])),key[b[p]]=1;
		sort(t.begin(),t.end());
		tp=0;
		if(!key[1])insert(1);
		for(ri i=0;i<t.size();++i)insert(t[i].se);
		while(tp>1)E[stk[tp-1]].pb(stk[tp]),--tp;
		ss=0;
		dfs(1),clear(1);
		Add(res,mul(ss,F[d]));
	}
	cout<<mul(res,mul(inv[n],inv[n-1]));
	return 0;
}