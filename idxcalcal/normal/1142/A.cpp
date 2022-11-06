#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:a-=mod;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=1e5+5;
int a,b,n,k;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),k=read();
	a=read(),b=read();
	ll g,mn=1e18,mx=-1e18,y=b-a,all=(ll)n*k;
	for(ri x=1;x<=n;++x){
		g=__gcd((ll)x*k+y,all);
		mn=min(mn,g);
		mx=max(mx,g);
	}
	y=b+a;
	for(ri x=1;x<=n;++x){
		g=__gcd((ll)x*k+y,all);
		mn=min(mn,g);
		mx=max(mx,g);
	}
	cout<<all/mx<<' '<<all/mn;
	return 0;
}