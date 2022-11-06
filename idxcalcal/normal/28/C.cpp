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
const int N=55;
double C[N][N],f[2][N][N];
int n,m,cur=0;
inline void init(){
	for(ri i=0;i<=n;++i){
		C[i][0]=1;
		for(ri j=1;j<=i;++j)C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	init();
	f[0][0][0]=1;
	double trans,s;
	for(ri i=1,x;i<=m;++i){
		cur^=1;
		x=read();
		memset(f[cur],0,sizeof(f[cur]));
		for(ri j=0;j<=n;++j)for(ri k=0;k<=j;++k)if(f[cur^1][j][k]>0){
			trans=f[cur^1][j][k],s=1;
			for(ri l=n-j;l;--l)s/=m-i+1;
			for(ri l=n-j,tt;~l;--l){
				tt=max(k,l%x?l/x+1:l/x);
				f[cur][j+l][tt]+=trans*C[n-j][l]*s;
				if(i==m)break;
				s*=m-i;
			}
		}
	}
	double res=0;
	for(ri i=0;i<=n;++i)res+=f[cur][n][i]*i;
	printf("%.15lf",res);
	return 0;
}