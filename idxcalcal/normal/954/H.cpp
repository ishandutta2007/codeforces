#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef unsigned long long Ull;
typedef unsigned int uii;
typedef set<int>::iterator It;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline int Read(char*s){
	int top=0;
	char ch=gc();
	while(!isalpha(ch))ch=gc();
	while(isalpha(ch))s[++top]=ch,ch=gc();
	return top;
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
template<typename T>inline void ckmin(T&a,T b){a>b?a=b:0;}
template<typename T>inline void ckmax(T&a,T b){a<b?a=b:0;}
const int N=5005;
int n,a[N],b[N],f[N][N<<1],cur=0,ans[N<<1];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	b[1]=1;
	for(ri i=1;i<n;++i)a[i]=read(),b[i+1]=mul(b[i],a[i]);
	f[n][0]=1;
	for(ri i=n-1;i;--i){
		f[i][0]=1;
		for(ri j=0,up=n-i;j<up;++j){
			f[i][j+1]=mul(f[i+1][j],a[i]);
			Add(ans[j+1],mul(f[i][j+1],b[i]));
		}
	}
	for(ri i=1;i<=n;++i){
		for(ri j=n+i-2;j;--j){
			f[i][j]=f[i-1][j-1];
			if(j>1&&i!=1)Add(f[i][j],mul(a[i-1]-1,f[i][j-2]));
			Add(ans[j],mul(f[i][j],b[i]));
		}
	}
	for(ri iv=mod+1>>1,i=1;i<=n*2-2;++i)cout<<mul(ans[i],iv)<<' ';
	return 0;
}