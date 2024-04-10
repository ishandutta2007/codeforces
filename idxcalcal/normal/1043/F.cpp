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
namespace modular{
	const int mod=1e9+7;
	inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
	inline void Add(int&a,int b){a=add(a,b);}
	inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
	inline void Dec(int&a,int b){a=dec(a,b);}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
}
using namespace modular;
const int N=3e5+5;
int fac[N],ifac[N],n,a[N],f[20][N],cnt[N],L=0,g=0;
bool vs[N];
inline int gcd(int a,int b){int t;while(b)t=a,a=b,b=t-t/a*a;return a;}
inline void init(){
	fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for(ri i=2;i<=n;++i){
		fac[i]=mul(fac[i-1],i);
		ifac[i]=mul(ifac[mod-mod/i*i],mod-mod/i);
	}
	for(ri i=2;i<=n;++i)Mul(ifac[i],ifac[i-1]);
}
inline int C(int n,int m){return n<m||m<0?0:mul(fac[n],mul(ifac[m],ifac[n-m]));}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	init();
	for(ri i=1;i<=n;++i){
		vs[a[i]=read()]=1;
		L=max(L,a[i]);
		g=gcd(a[i],g);
	}
	if(g^1)return puts("-1"),0;
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(ri i=1;i<=L;++i)for(ri j=i;j<=L;j+=i)(vs[j])&&(++cnt[i]);
	for(ri i=1;i<=min(n,10);++i){
		for(ri j=L;j;--j){
			f[i][j]=C(cnt[j],i);
			for(ri k=j<<1;k<=L;k+=j)Dec(f[i][j],f[i][k]);
		}
		if(f[i][1])return cout<<i,0;
	}
	return 0;
}