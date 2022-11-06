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
typedef vector<int> poly;
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
const int N=255*255;
int n,K,fac[N],ifac[N],pw1[N],pw2[N];
inline void init(){
	fac[0]=fac[1]=ifac[0]=ifac[1]=1,pw1[0]=pw2[0]=1,pw1[1]=K,pw2[1]=K-1;
	for(ri i=2;i<=n*n;++i){
		fac[i]=mul(fac[i-1],i);
		ifac[i]=mul(ifac[mod-mod/i*i],mod-mod/i);
		pw1[i]=mul(pw1[i-1],K);
		pw2[i]=mul(pw2[i-1],K-1);
	}
	for(ri i=2;i<=n*n;++i)Mul(ifac[i],ifac[i-1]);
}
inline int C(int n,int m){return mul(fac[n],mul(ifac[m],ifac[n-m]));} 
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),K=read();
	init();
	int res=0;
	for(ri t,x,i=0;i<=n;++i)for(ri j=0;j<=n;++j){
		t=mul(pw1[(n-i)*(n-j)],pw2[n*n-(n-i)*(n-j)]);
		Mul(t,mul(C(n,i),C(n,j)));
		(i+j)&1?Dec(res,t):Add(res,t);
	}
	cout<<res<<'\n';
	return 0;
}