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
typedef map<int,int>::iterator It;
typedef vector<int> poly;
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
const int N=305;
int n,all=0,fac[N],ifac[N];
vector<int>vl[N];
poly f,g;
inline void init(){
	fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for(ri i=2;i<=n;++i){
		fac[i]=mul(fac[i-1],i);
		ifac[i]=mul(ifac[mod-mod/i*i],mod-mod/i);
	}
	for(ri i=2;i<=n;++i)Mul(ifac[i],ifac[i-1]);
}
inline int C(int n,int m){return n<m||m<0?0:mul(fac[n],mul(ifac[m],ifac[n-m]));}
inline bool check(int a,int b){
	int c=sqrt((ll)a*b);
	return (ll)c*c==(ll)a*b;
}
inline poly operator*(poly a,poly b){
	int n=a.size(),m=b.size(),t=n+m-1;
	poly c(t);
	for(ri i=0;i<n;++i)for(ri j=0;j<m;++j)
	Add(c[i+j],mul(a[i],b[j]));
	return c;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	init();
	for(ri x,i=1;i<=n;++i){
		x=read();
		bool ff=1;
		for(ri j=1;j<=all;++j)if(check(vl[j].back(),x)){
			ff=0;
			vl[j].pb(x);
			break;
		}
		if(ff)vl[++all].pb(x);
	}
	f=poly(1,1);
	int mt=1,res=0;
	for(ri pre=0,i=1;i<=all;++i){
		g.resize(vl[i].size()+1);
		g[0]=0;
		for(ri j=1,up=vl[i].size();j<=up;++j)g[j]=(up-j)&1?mod-C(up-1,j-1):C(up-1,j-1);
		for(ri j=0;j<=vl[i].size();++j)Mul(g[j],ifac[j]);
		f=f*g;
		pre+=vl[i].size();
		Mul(mt,fac[vl[i].size()]);
	}
	for(ri i=0;i<f.size();++i)Add(res,mul(f[i],fac[i]));
	cout<<mul(mt,res);
	return 0;
}