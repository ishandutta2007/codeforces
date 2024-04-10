#include<bits/stdc++.h>
#define int ll
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const ll N=100010,mod=1000000007;
ll n,m;
ll x[2],y[2];
ll ans;
inline ll qpow(ll a,ll b,ll mod){
	ll ans=1;a%=mod;
	while(b){
		if(b&1)ans=ans*a%mod;
		b>>=1,a=a*a%mod;
	}
	return ans%mod;
}
#define f(x) for(rgi x=0;x<=1;++x)
signed main(){
	read(n,m),++n,++m;
	x[0]=(n>>1),x[1]=n-x[0],y[0]=(m>>1),y[1]=m-y[0];
	//cout<<x[0]<<' '<<x[1]<<' '<<y[0]<<' '<<y[1];
	f(x0)f(x1)f(x2)f(y0)f(y1)f(y2){
		if((x1*y2+x2*y0+x0*y1-x1*y0-x2*y1-x0*y2)%2==0){
			ans+=x[x1]*x[x2]%mod*x[x0]%mod*y[y1]*y[y2]%mod*y[y0];
			ans%=mod;
		}
	}
	for(rgi a=0;a<n;++a){
		for(rgi b=0;b<m;++b){
			if(!a&&!b)continue;
			if(!a)(ans-=(b-1)*(n-a)*(m-b)*6ll%mod)%=mod;
			else if(!b)(ans-=(a-1)*(n-a)*(m-b)*6ll%mod)%=mod;
			else (ans-=(__gcd(a,b)-1ll)*(n-a)*(m-b)*12ll)%=mod;
		}
	}
	ll s=n*m;
	(ans-=s)%=mod;
	(ans-=s*(s-1)*3ll)%=mod;
	write((ans+mod)%mod);
	return 0;
}