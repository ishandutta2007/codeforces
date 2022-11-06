#include<bits/stdc++.h>
#define ri int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() getchar()
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
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
const int N=40;
int n,m;
ll f[N][N],g[N][N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	g[0][0]=g[1][1]=f[0][0]=f[1][1]=g[1][0]=1;
	for(ri i=2;i<=n;++i){
		for(ri j=1;j<=i;++j)for(ri k=0;k<i;++k)
		f[i][j]+=f[k][j-1]*(g[i-k-1][0]-g[i-k-1][j])*2-f[k][j-1]*f[i-k-1][j-1];
		g[i][i]=f[i][i];
		for(ri j=i-1;~j;--j)g[i][j]=g[i][j+1]+f[i][j];
	}
	cout<<g[n][m];
	return 0;
}