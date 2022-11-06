#include<bits/stdc++.h>
#define int long long
#define ri register int
#define pb push_back
#define fi first
#define se second
#define double long double
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() getchar()
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
	int mod;
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
const int N=205;
int C[N][N],n,K,f[N][N],s[N];
inline void init(){
	for(ri i=0;i<=n;++i){
		C[i][0]=1;
		for(ri j=1;j<=i;++j)C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
}
signed main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),K=read(),mod=read();
	init();
	s[1]=f[1][0]=1;
	for(ri i=2;i<=n;++i){
		for(ri j=1;j<=K;++j){
			for(ri k=1;k<i;++k)Add(f[i][j],mul(mul(f[i-k][j-1],s[k]),C[i-2][k-1]));
			if(j<K)Add(s[i],f[i][j]);
		}
	}
	int res=0;
	for(ri i=1;i<=n;++i)for(ri j=0;j<=K;++j)for(ri k=0;j+k<=K;k?++k:k+=2)Add(res,mul(f[i][j],f[n-i+1][k]));
	cout<<mul(mul(res,2),mul(n,n-1));
	return 0;
}