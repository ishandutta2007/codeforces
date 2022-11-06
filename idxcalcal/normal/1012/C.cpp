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
const int N=5005;
int n,a[N],f[N][N][2];
inline int getl(int i){return max(0,a[i-1]-a[i]+1);}
inline int getr(int i){return max(0,a[i+1]-a[i]+1);}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i)a[i]=read();
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=0;
	f[1][0][0]=0,f[1][1][1]=getr(1);
	for(ri i=2;i<=n;++i)for(ri j=0,lim=(i+1)/2;j<=lim;++j){
		if(j)f[i][j][1]=getr(i)+min(f[i-2][j-1][0]+getl(i),f[i-2][j-1][1]+max(0,min(a[i-2]-1,a[i-1])-a[i]+1));
		f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]);
	}
	for(ri i=1,up=n+1>>1;i<=up;++i)cout<<min(f[n][i][0],f[n][i][1])<<' ';
	return 0;
}