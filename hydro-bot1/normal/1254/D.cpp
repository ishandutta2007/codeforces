// Hydro submission #624a7852c7ec5adf0dbc325c@1649047691552
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

#define modPrepare() \
void Add(int &x,int y){(x+=y)>=Mod?x-=Mod:x;}\
void Del(int &x,int y){(x-=y)<0?x+=Mod:x;}\
int Pow(int a,int b){\
	int res=1;\
	while(b){\
		if(b&1) res=1ll*res*a%Mod;\
		a=1ll*a*a%Mod,b>>=1;\
	}\
	return res;\
}

#define facPrepare(_) \
const int len=_;\
int Fac[len+10],Iac[len+10]; \
void facInit(){\
	Fac[0]=Iac[0]=1;\
	for(int i=1;i<=len;++i) Fac[i]=1ll*Fac[i-1]*i%Mod;\
	Iac[len]=Pow(Fac[len],Mod-2);\
	for(int i=len-1;i;--i) Iac[i]=1ll*Iac[i+1]*(i+1)%Mod;\
}\
int Binom(int x,int y){return x<y?0:1ll*Fac[x]*Iac[y]%Mod*Iac[x-y]%Mod;}

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

void read(int& x){
    static char c;int f=0;
    while(!isdigit(c=getchar()))
        if(c=='-') f=1;
    x=c^48;
    while(isdigit(c=getchar())) x=(x*10)+(c^48);
    if(f) x=-x;
}
void read(ll& x){
    static char c;int f=0;
    while(!isdigit(c=getchar()))
    	if(c=='-') f=1;
    x=c^48;
    while(isdigit(c=getchar())) x=(x*10)+(c^48);
    if(f) x=-x;
}
void read(uint& x){
    static char c;
    while(!isdigit(c=getchar()));x=c^48;
    while(isdigit(c=getchar())) x=(x*10)+(c^48);
}
void read(ull& x){
    static char c;
    while(!isdigit(c=getchar()));x=c^48;
    while(isdigit(c=getchar())) x=(x*10)+(c^48);
}
void chkmax(int& x,int y){if(y>x)x=y;}
void chkmin(int& x,int y){if(y<x)x=y;}
void chkmax(ll& x,ll y){if(y>x)x=y;}
void chkmin(ll& x,ll y){if(y<x)x=y;}
void chkmax(uint& x,uint y){if(y>x)x=y;}
void chkmin(uint& x,uint y){if(y<x)x=y;}
void chkmax(ull& x,ull y){if(y>x)x=y;}
void chkmin(ull& x,ull y){if(y<x)x=y;}

const int Mod=998244353;
modPrepare()

const int N=2e5+10;

int n,q,inv;
vector<int> Edge[N];

int siz[N],dep[N],son[N],top[N],fat[N];
int dfn[N],tot;

void dfs1(int now,int fa){
	siz[now]=1,dep[now]=dep[fat[now]=fa]+1;
	dfn[now]=++tot;
	for(int v:Edge[now])
		if(v!=fa){
			dfs1(v,now),siz[now]+=siz[v];
			if(siz[v]>siz[son[now]]) son[now]=v;
		}
}
void dfs2(int now,int tp){
	top[now]=tp;
	if(son[now]) dfs2(son[now],tp);
	for(int v:Edge[now])
		if(v!=fat[now]&&v!=son[now]) dfs2(v,v);
}

int Glob;
int c[N];
int lb(int x){return x&-x;}
void add(int pos,int val){for(;pos<=n;pos+=lb(pos))Add(c[pos],val);}
int ask(int pos){int res(0);for(;pos;pos-=lb(pos))Add(res,c[pos]);return res;}

int tag[N];

int Query(int u){
	int res=0;
	do{
		u=top[u];
		if(fat[u]) Add(res,1ll*tag[fat[u]]*(n-siz[u])%Mod);
		u=fat[u];
	}while(u);
	return res;
}

void Work(){
	read(n),read(q),inv=Pow(n,Mod-2);
	for(int i=1,u,v;i<n;++i)
		read(u),read(v),Edge[u].pb(v),Edge[v].pb(u);
	dfs1(1,0),dfs2(1,1);
	for(int i=1;i<=q;++i){
		int op;
		read(op);
		if(op==1){
			int v,d;
			read(v),read(d);
			add(1,1ll*d*siz[v]%Mod),add(dfn[v],1ll*d*(Mod-siz[v])%Mod),add(dfn[v]+siz[v],1ll*d*siz[v]%Mod);
			if(son[v])
				add(dfn[son[v]],1ll*d*(n-siz[son[v]])%Mod),add(dfn[son[v]]+siz[son[v]],1ll*d*(Mod-n+siz[son[v]])%Mod);
			Add(tag[v],d);
		}
		else{
			int u;read(u);
			int res=ask(dfn[u]);
			Add(res,Query(u));
			Add(res,1ll*tag[u]*n%Mod);
			printf("%d\n",1ll*res*inv%Mod);
		}
	}
}

int main(){Work();}