#include<bits/stdc++.h>
namespace imzzy{
	#define endl '\n'
	#define rgi register int
	typedef long long ll;
	class fastin{private:int _ch,_f;
	public:inline fastin&operator>>(char&c){c=getchar();return*this;}
	template<typename _Tp>inline fastin&operator>>(_Tp&_x){
	_x=0;while(!isdigit(_ch))_f|=(_ch==45),_ch=getchar();
	while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
	_f&&(_x=-_x,_f=0);return*this;}fastin(){_ch=_f=0;}
	}fin;class fastout{private:int _num[32],_head;
	public:inline fastout&operator<<(char c){putchar(c);return*this;}
	template<typename _Tp> inline fastout&operator<<(_Tp _x){
	_Tp _k;if(_x==0){putchar('0');return *this;}if(_x<0)putchar('-'),_x=-_x;
	while(_x>0)_k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
	while(_head>0)putchar(_num[_head]),--_head;return*this;}fastout(){_head=0;}
	}fout;inline void P_INIT(){
	#ifdef D_STDOUT_UNBUFFERED
	setbuf(stdout,NULL);
	#endif
}}using namespace imzzy;
// ----------------------------
// #define int ll
// using namespace std;
const int mod=998244353,inf=1201201201;
const int maxn=300004;

inline ll powmod(ll a,ll b) {
	ll res=1;
	while(b>0) {
		if(b&1) (res*=a)%=mod;
		(a*=a)%=mod,b>>=1;
	} return res;
}
ll fact[maxn],invfact[maxn];
inline ll C(int n,int m) {return fact[n]*invfact[m]%mod*invfact[n-m]%mod;}

int n,a[maxn],val[maxn],cntv;
ll sum[maxn],cnt[maxn];
signed main()
{P_INIT();
	fact[0]=invfact[0]=1; for(rgi i=1;i<maxn;++i) fact[i]=fact[i-1]*i%mod,invfact[i]=powmod(fact[i],mod-2);
	fin>>n;
	for(rgi i=1;i<=n*2;++i) fin>>a[i],val[++cntv]=a[i];
	std::sort(a+1,a+1+n*2);
	for(rgi i=1;i<=n*2;++i) sum[i]=(sum[i-1]+a[i])%mod;
	fout<<(sum[n*2]+mod-sum[n]*2%mod)*C(n*2,n)%mod;
	// // std::sort(val+1,val+1+n*2),cntv=std::unique(val+1,val+1+n*2)-val;
	// ll ans=0;
	// for(rgi i=2;i<=n*2;++i) {
	// 	(ans+=(sum[n*2]+mod-sum[i-1]+mod-sum[n*2-i+1])%mod*C((2*n-i),(2*n-i)/2))%=mod;
	// 	// fout<<i<<' '<<(sum[n*2]+mod-sum[i-1]+mod-sum[n*2-i+1])%mod<<' '<<ans<<endl;
	// } //small up
	// for(rgi i=2;i<=n*2;++i) {
	// 	(ans+=(sum[n*2]+mod-sum[i-1]+mod-sum[n*2-i+1])*C((2*n-i),(2*n-i)/2))%=mod;
	// } //big up
	// fout<<ans;
	return 0;
}
// ----------------------------
// by imzzy