// Hydro submission #6286fe6c06fd33b2ec2200f4@1653014124858
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

const int N=4e5+10;

int n,k,r,q;
vector<int> Edge[N];
void add(int u,int v){Edge[u].pb(v),Edge[v].pb(u);}

int vis[N],fat[N];
int getf(int now){return now==fat[now]?now:fat[now]=getf(fat[now]);}

int dep[N],fa[N][21];
void dfs(int now,int _fa){
	fa[now][0]=_fa,dep[now]=dep[_fa]+1;
	for(int B=1;B<=19;++B) fa[now][B]=fa[fa[now][B-1]][B-1];
	for(int v:Edge[now])
		if(v!=_fa) dfs(v,now);
}
int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int B=19;~B;--B)
		if(dep[fa[u][B]]>dep[v]) u=fa[u][B];
	u=fa[u][0];
	if(u==v) return u;
	for(int B=19;~B;--B)
		if(fa[u][B]!=fa[v][B]) u=fa[u][B],v=fa[v][B];
	return fa[u][0];
}
int jump(int u,int d){
	for(int i=0;i<=19;++i)
		if((d>>i)&1) u=fa[u][i];
	return u;
}

void Work(){
	read(n),read(k),read(r);
	for(int i=1;i<n;++i){
		int u,v;read(u),read(v);
		add(u,n+i),add(n+i,v);
	}
	dfs(1,0);
	iota(fat,fat+2*n,0);
	memset(vis,-1,sizeof vis);
	queue<int> Q;
	for(int i=1;i<=r;++i){int u;read(u);Q.push(u),vis[u]=0;}
	while(Q.size()){
		int now=Q.front();Q.pop();
		if(vis[now]==k) continue;
		for(int v:Edge[now]){
			fat[getf(v)]=getf(now);
			if(vis[v]==-1) vis[v]=vis[now]+1,Q.push(v);
		}
	}
	read(q);
	for(int i=1;i<=q;++i){
		int u,v;read(u),read(v);
		int lca=LCA(u,v),l=dep[u]+dep[v]-2*dep[lca];
		if(l<=2*k){puts("YES");continue;}
		int _u=(k<=dep[u]-dep[lca])?getf(jump(u,k)):getf(jump(v,l-k));
		int _v=(k<=dep[v]-dep[lca])?getf(jump(v,k)):getf(jump(u,l-k));
		if(_u==_v) puts("YES");
		else puts("NO");
	}
}

int main(){Work();}