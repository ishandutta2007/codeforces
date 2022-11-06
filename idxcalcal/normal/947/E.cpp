#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly; 
#define fi first
#define se second
#define pb push_back
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
namespace modular{
	const int mod=998244353;
	inline int add(int a,int b){return a+b<mod?a+b:a+b-mod;}
	inline int dec(int a,int b){return a<b?a-b+mod:a-b;}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Add(int&a,int b){a=a+b<mod?a+b:a+b-mod;}
	inline void Dec(int&a,int b){a=a<b?a-b+mod:a-b;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
}
using namespace modular;
const int N=1e5+5;
int n,invv[23],w[23],lim,tim;
vector<int>rev[N];
inline void init(const int&up){
	lim=1,tim=0;
	while(lim<up)lim<<=1,++tim;
	if(rev[tim].size())return;
	rev[tim].resize(lim);
	for(ri i=0;i<lim;++i)rev[tim][i]=(rev[tim][i>>1]>>1)|((i&1)<<(tim-1));
}
ll m;
inline void init_ntt(){
	w[22]=ksm(3,(mod-1)>>23);
	for(ri i=21;~i;--i)w[i]=mul(w[i+1],w[i+1]);
	invv[0]=1;
	for(ri i=1,iv=mod+1>>1;i<23;++i)invv[i]=mul(invv[i-1],iv);
}
inline void ntt(poly&a,int type){
	for(ri i=0;i<lim;++i)if(i<rev[tim][i])swap(a[i],a[rev[tim][i]]);
	for(ri i=1,t=0,a0,a1;i<lim;i<<=1,++t)for(ri j=0,len=i<<1;j<lim;j+=len)
	for(ri k=0,mt=1;k<i;++k,Mul(mt,w[t])){
		a0=a[j+k],a1=mul(a[j+k+i],mt);
		a[j+k]=add(a0,a1),a[j+k+i]=dec(a0,a1);
	}
	if(~type)return;
	reverse(++a.begin(),a.end());
	for(ri i=0;i<lim;++i)Mul(a[i],invv[tim]);
}
inline poly operator*(poly a,poly b){
	int n=a.size(),m=b.size(),t=n+m-1;
	if(t<=64){
		poly c(t);
		for(ri i=0;i<n;++i)for(ri j=0;j<m;++j)
		Add(c[i+j],mul(a[i],b[j]));
		return c;
	}
	init(t);
	a.resize(lim),ntt(a,1);
	b.resize(lim),ntt(b,1);
	for(ri i=0;i<lim;++i)Mul(a[i],b[i]);
	return ntt(a,-1),a.resize(t),a;
}
int fac[N],ifac[N],inv[N];
inline void init_fac(){
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
	for(ri i=2;i<=n+1;++i){
		fac[i]=mul(fac[i-1],i);
		inv[i]=mul(inv[mod-mod/i*i],mod-mod/i);
		ifac[i]=mul(ifac[i-1],inv[i]);
	}
}
poly a,f,g;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	m=readl();
	a.resize(n+1),f.resize(n+1),g.resize(n+1);
	for(ri i=0;i<=n;++i)a[i]=read();
	init_ntt(),init_fac();
	for(ri i=0;i<=n;++i)f[i]=mul(fac[i],a[i]),g[i]=ifac[i];
	reverse(f.begin(),f.end());
	a=f*g;
	a.resize(n+1);
	reverse(a.begin(),a.end());
	for(ri i=0;i<=n;++i)Mul(a[i],ifac[i]);
	for(ri i=0;i<=n;++i)Mul(a[i],ksm(inv[i+1],m%(mod-1)));
	for(ri i=0;i<=n;++i)f[i]=mul(fac[i],a[i]),g[i]=i&1?mod-ifac[i]:ifac[i];
	reverse(f.begin(),f.end());
	a=f*g;
	a.resize(n+1);
	reverse(a.begin(),a.end());
	for(ri i=0;i<=n;++i)Mul(a[i],ifac[i]);
	for(ri i=0;i<=n;++i)cout<<a[i]<<' ';
	return 0;
}