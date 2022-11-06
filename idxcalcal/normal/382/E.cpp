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
	const int mod=1e9+7,inv2=5e8+4;
	inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
	inline void Add(int&a,int b){a=add(a,b);}
	inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
	inline void Dec(int&a,int b){a=dec(a,b);}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
}
using namespace modular;
const int N=55;
int n,K,f[N][N][2],C[N][N];
inline void init(){
	for(ri i=0;i<=n;++i){
		C[i][0]=1;
		for(ri j=1;j<=i;++j)C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),K=read();
	f[0][0][1]=f[1][0][0]=1;
	init();
	for(ri i=2,t;i<=n;++i)for(ri j=0;j<=K&&j+j<=i;++j){
		for(ri k=0;k+k+1<=i;++k){
			t=mul(mul(k+k+1==i?inv2:1,C[i-1][k]),mul(max(k,1),i-k-1));
			for(ri p=0;p<=j&&p+p<=k;++p){
				Add(f[i][j][0],mul(t,mul(f[k][p][1],f[i-k-1][j-p][1])));
				if(j==p)continue;
				Add(f[i][j][1],mul(t,mul(f[k][p][0],f[i-k-1][j-p-1][0])));
				Add(f[i][j][1],mul(t,mul(f[k][p][1],f[i-k-1][j-p-1][0])));
				Add(f[i][j][1],mul(t,mul(f[k][p][0],f[i-k-1][j-p-1][1])));
			}
		}
	}
	cout<<add(f[n][K][0],f[n][K][1]);
	return 0;
}