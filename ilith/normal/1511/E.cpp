#include<bits/stdc++.h>
#define rgi register int
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
const int N=300010;
const ll mod=998244353;
inline ll qpow(ll a,ll b,ll mod){
	ll ans=1;a%=mod;
	while(b){
		if(b&1)ans=ans*a%mod;
		b>>=1,a=a*a%mod;
	}
	return ans%mod;
}
ll n,m,p[N],cnt,res;
string s[N];
signed main(){
	read(n,m),p[1]=0,p[2]=1;
	for(rgi i=1;i<=n;++i){
		cin>>s[i];
		for(rgi j=0;j<m;++j)if(s[i][j]=='o')++cnt;
	}
	for(rgi i=3;i<=cnt;++i)p[i]=(p[i-1]+p[i-2]*2ll+qpow(2,i-2,mod))%mod;
	for(rgi i=1;i<=cnt;++i){
		(p[i]*=qpow(2,cnt-i,mod))%mod;
	}
	for(rgi i=1;i<=n;++i){
		int cmb=0;
		for(rgi j=0;j<m;++j){
			if(s[i][j]=='o')++cmb;
			else (res+=p[cmb])%=mod,cmb=0;
		}
		(res+=p[cmb])%=mod;
	}
	for(rgi i=0;i<m;++i){
		int cmb=0;
		for(rgi j=1;j<=n;++j){
			if(s[j][i]=='o')++cmb;
			else (res+=p[cmb])%=mod,cmb=0;
		}
		(res+=p[cmb])%=mod;
	}
	write(res);
	return 0;
}