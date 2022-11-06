#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef unsigned long long Ull;
typedef unsigned int uii;
typedef double db;
typedef long double ld;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
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
char xxx;
const int N=1e5+5;
vector<pii>e[N];
int n,sig=0,rt[N];
ll f[N],_f[N],g[N],vl[N],a[N];
inline int find(ll x){return lower_bound(vl+1,vl+sig+1,x)-vl;}
void dfs1(int p,int ft){
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i].fi)==ft)continue;
		dfs1(v,p);
		if(f[v]+e[p][i].se>=f[p]){
			_f[p]=f[p];
			f[p]=f[v]+e[p][i].se;
		}
		else ckmax(_f[p],f[v]+e[p][i].se);
	}
}
void dfs2(int p,int ft){
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i].fi)==ft)continue;
		g[v]=max(g[p],f[v]+e[p][i].se==f[p]?_f[p]:f[p])+e[p][i].se;
		dfs2(v,p);
	}
}
int in[N],out[N],pred[N],tot=0,ps[N];
void dfs(int p,int ft){
	pred[in[p]=++tot]=p;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i].fi)==ft)continue;
		dfs(v,p);
	}
	out[p]=tot;
}
namespace sgt{
	#define lc (son[p][0])
	#define rc (son[p][1])
	#define mid (l+r>>1)
	int siz[N*100],son[N*100][2],cnt=0;
	inline void update(int&p,int o,int l,int r,int k){
		p=++cnt;
		siz[p]=siz[o]+1,lc=son[o][0],rc=son[o][1];
		if(l==r)return;
		k<=mid?update(lc,lc,l,mid,k):update(rc,rc,mid+1,r,k);
	}
	inline int query(int a,int b,int l,int r,int ql,int qr){
		if(siz[a]==siz[b])return 0;
		if(ql<=l&&r<=qr)return siz[b]-siz[a];
		if(qr<=mid)return query(son[a][0],son[b][0],l,mid,ql,qr);
		if(ql>mid)return query(son[a][1],son[b][1],mid+1,r,ql,qr);
		return query(son[a][0],son[b][0],l,mid,ql,qr)+query(son[a][1],son[b][1],mid+1,r,ql,qr);
	}
	#undef lc
	#undef rc
	#undef mid
}
char yyy;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	cerr<<(&yyy-&xxx)/1024/1024<<"ldxcaicai\n";
	#endif
	n=read();
	for(ri i=1,u,v,w;i<n;++i){
		u=read(),v=read(),w=read();
		e[u].pb(pii(v,w));
		e[v].pb(pii(u,w));
	}
	dfs1(1,0);
	dfs2(1,0);
	for(ri i=1;i<=n;++i)vl[i]=a[i]=max(f[i],g[i]);
	sort(vl+1,vl+n+1),sig=unique(vl+1,vl+n+1)-vl-1;
	for(ri i=1;i<=n;++i)a[i]=find(a[i]);
	int _rt=1;
	for(ri i=2;i<=n;++i)if(a[i]<a[_rt])_rt=i;
	dfs(_rt,0);
	for(ri i=1;i<=n;++i)sgt::update(rt[i],rt[i-1],1,sig,a[pred[i]]);
	for(ri tt=read();tt;--tt){
		ll x=readl();
		for(ri l=1,r=0;l<=sig;++l){
			while(r<sig&&vl[r+1]-vl[l]<=x)++r;
			ps[l]=r;
		}
		int res=0;
		for(ri L,R,i=1;i<=n;++i){
			ckmax(res,sgt::query(rt[in[i]-1],rt[out[i]],1,sig,a[i],ps[a[i]]));
		}
		cout<<res<<'\n';
	}
	return 0;
}