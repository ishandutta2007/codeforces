#include<bits/stdc++.h>
#define ri register int
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
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
namespace modular{
	const int mod=998244353;
	inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
	inline void Add(int&a,int b){a=add(a,b);}
	inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
	inline void Dec(int&a,int b){a=dec(a,b);}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
}
using namespace modular;
template<typename T>inline void ckmin(T&a,T b){a>b?a=b:0;}
const int N=505;
int n,K,f[2][N][N],cur=0,g[N],ss[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),K=read();
	for(ri i=1;i<=n;++i)f[cur][i][1]=1;
	for(ri i=2;i<=n;++i){
		cur^=1;
		for(ri j=1;j<=n;++j)for(ri k=1;k<=i;++k)f[cur][j][k]=0;
		for(ri j=1;j<=n;++j)for(ri k=1;k<=i;++k)if(f[cur^1][j][k]){
			if(j>k)Add(f[cur][j][k+1],f[cur^1][j][k]);
			Add(f[cur][j][1],f[cur^1][j][k]);
		}
	}
	for(ri i=1;i<=n;++i)for(ri j=1;j<=i;++j)Add(g[i],dec(f[cur][i][j],f[cur][i-1][j]));
	int res=0;
	for(ri i=1;i<=n;++i)for(ri j=1;i*j<K&&j<=n;++j)Add(res,mul(g[i],g[j]));
	cout<<mul(res,2);
    return 0;
}