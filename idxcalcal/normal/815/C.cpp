#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef unsigned long long Ull;
typedef unsigned int uii;
typedef set<int>::iterator It;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline int Read(char*s){
	int top=0;
	char ch=gc();
	while(!isalpha(ch))ch=gc();
	while(isalpha(ch))s[++top]=ch,ch=gc();
	return top;
}
namespace modular{
	const int mod=1e9+7;
	inline int add(int a,int b){return a+b<mod?a+b:a+b-mod;}
	inline int dec(int a,int b){return a<b?a-b+mod:a-b;}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Add(int&a,int b){a=a+b<mod?a+b:a+b-mod;}
	inline void Dec(int&a,int b){a=a<b?a-b+mod:a-b;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
	inline int Inv(int a){return ksm(a,mod-2);}
	inline void fix(int&a){a=(a%mod+mod)%mod;}
}
using namespace modular;
template<typename T>inline void ckmin(T&a,T b){a>b?a=b:0;}
template<typename T>inline void ckmax(T&a,T b){a<b?a=b:0;}
const int N=5005;
const ll inf=1e18;
int n,lm,fa[N],siz[N],a[N],b[N];
ll f[N][N][2],tmp[N];
vector<int>e[N];
void dfs(int p){
	siz[p]=1;
	for(ri i=0;i<=n;++i)f[p][i][0]=f[p][i][1]=inf;
	f[p][0][0]=0,f[p][1][0]=a[p],f[p][1][1]=a[p]-b[p];
	for(ri i=0,v;i<e[p].size();++i){
		dfs(v=e[p][i]);
		for(ri j=0;j<=siz[p]+siz[v];++j)tmp[j]=f[p][j][1];
		for(ri j=0;j<=siz[p];++j)if(f[p][j][1]!=inf)
		for(ri k=0;k<=siz[v];++k)if(min(f[v][k][1],f[v][k][0])!=inf)
		ckmin(tmp[j+k],f[p][j][1]+min(f[v][k][1],f[v][k][0]));
		for(ri j=0;j<=siz[p]+siz[v];++j)f[p][j][1]=tmp[j],tmp[j]=f[p][j][0];
		for(ri j=0;j<=siz[p];++j)if(f[p][j][0]!=inf)
		for(ri k=0;k<=siz[v];++k)if(f[v][k][0]!=inf)
		ckmin(tmp[j+k],f[p][j][0]+f[v][k][0]);
		for(ri j=0;j<=siz[p]+siz[v];++j)f[p][j][0]=tmp[j];
		siz[p]+=siz[v];
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),lm=read();
	for(ri i=1;i<=n;++i){
		a[i]=read(),b[i]=read();
		if(i^1)e[read()].pb(i);
	}
	dfs(1);
	for(ri i=n;~i;--i){
		if(min(f[1][i][0],f[1][i][1])<=lm){
			cout<<i;
			break;
		}
	}
	return 0;
}