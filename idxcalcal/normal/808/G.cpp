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
const int N=1e5+5;
char s[N],t[N];
int n,m,f[N],g[N],nxt[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(ri i=1,j=0;i<m;++i){
		while(j&&t[i+1]!=t[j+1])j=nxt[j];
		nxt[i+1]=t[i+1]==t[j+1]?++j:0;
	}
	for(ri p,i=m;i<=n;++i){
		bool ff=1;
		for(ri j=i-m+1,k=1;j<=i;++j,++k)if(s[j]!='?'&&s[j]!=t[k]){
			ff=0;
			break;
		}
		if(ff){
			ckmax(g[i],f[i-m]+1);
			p=nxt[m];
			while(p){
				ckmax(g[i],g[i-m+p]+1);
				p=nxt[p];
			}
		}
		f[i]=max(f[i-1],g[i]);
	}
	cout<<f[n];
	return 0;
}