#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG(x) cerr<<#x" == "<<x<<endl
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=1e5+7,inf=0x3f3f3f3f;
int n,M;
struct node{int v,w;};
vector<node> g[N];
inline int fpow(int x,int k){
	int ans=1;
	while(k){if(k&1)ans=1ll*ans*x%M;x=1ll*x*x%M;k>>=1;}
	return ans;
}
int inv[N],cf[N],phi;
void init(){
	int t=phi=M;
	for(int i=2,r=sqrt(M);i<=r;++i){
		if(t%i==0){
			do t/=i;while(t%i==0);
			phi-=phi/i;
		}
	}
	if(t>sqrt(M)&&M%t==0)phi-=phi/t;
	int base=fpow(10,phi-1);
	cf[0]=inv[0]=1;
	REP(i,1,n)inv[i]=1ll*inv[i-1]*base%M,cf[i]=10ll*cf[i-1]%M;
}
int vis[N],sz,sum,siz[N],rt;
void dfs1(int x){
	siz[x]=vis[x]=1;int mx=0;
	for(auto e:g[x])if(!vis[e.v])
		dfs1(e.v),siz[x]+=siz[e.v],smax(mx,siz[e.v]);
	smax(mx,sum-siz[x]);
	if(smin(sz,mx))rt=x;
	vis[x]=0;
}
int up[N],down[N],dep[N],cnt,in[N],out[N],rid[N];
ll ans;
void dfs2(int x){
	vis[x]=1;in[x]=++cnt;rid[cnt]=x;
//	fprintf(stderr,"%d: up_%d down_%d dep_%d\n",x,up[x],down[x],dep[x]);
	for(auto e:g[x])if(!vis[e.v]){
		down[e.v]=(down[x]*10ll+e.w)%M,dep[e.v]=dep[x]+1;
		up[e.v]=1ll*cf[dep[x]]*e.w%M+up[x];if(up[e.v]>=M)up[e.v]-=M;
		dfs2(e.v);
		
	}	
	vis[x]=0;out[x]=cnt;
}
map<int,int> p;
void solve(int x){
	sz=inf;dfs1(x);x=rt;
	dep[x]=cnt=up[x]=down[x]=0;
	dfs2(x);vis[x]=1;
	p.clear();p[0]=1;
	for(auto e:g[x])if(!vis[e.v]){
		REP(i,in[e.v],out[e.v]){
			int &y=rid[i];
			int m=1ll*(M-down[y])*inv[dep[y]]%M;
			auto iter=p.find(m);
			if(iter!=p.end())ans+=iter->second;
		}
		REP(i,in[e.v],out[e.v])++p[up[rid[i]]];
	}
	p.clear();
	for(auto e=g[x].rbegin();e!=g[x].rend();++e)if(!vis[e->v]){
		REP(i,in[e->v],out[e->v]){
			int &y=rid[i];
			int m=1ll*(M-down[y])*inv[dep[y]]%M;
			auto iter=p.find(m);
			if(iter!=p.end())ans+=iter->second;
		}
		REP(i,in[e->v],out[e->v])++p[up[rid[i]]];
	}
	ans+=p[0];
	for(auto e:g[x])if(!vis[e.v])sum=siz[e.v],solve(e.v);
}
int main(){
//	freopen("in.txt","r",stdin);
	sum=n=read(),M=read();
	if(M==1){
		cout<<1ll*n*(n-1)<<endl;
		return 0;
	}
	REP(i,2,n){
		int x=read()+1,y=read()+1,z=read();
		g[x].push_back({y,z}),g[y].push_back({x,z});
	}
	init();solve(1);
	cout<<ans<<endl;
	return 0;
}