#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
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
	int mod=998244353;
	inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
	inline void Add(int&a,int b){a=add(a,b);}
	inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
	inline void Dec(int&a,int b){a=dec(a,b);}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}	
};
using namespace modular;
const int N=2e5+5;
int n,a[N],ok[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1,x;i<=n;++i){
		a[i]=read()^a[i-1];
		x=a[i];
		for(ri j=31;~j;--j){
			if(x>>j&1){
				if(ok[j])x^=ok[j];
				else{
					ok[j]=x;
					break;
				}
				if(!x)break;
			}
		}
	}
	if(!a[n])return puts("-1"),0;
	int res=0;
	for(ri i=31;~i;--i)if(ok[i])++res;
	cout<<res;
	return 0;
}