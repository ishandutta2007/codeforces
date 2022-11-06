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
typedef vector<int> poly;
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
int x;
ll n;
vector<int>divv;
inline void divid(int x){
	for(ri i=2,lm=sqrt(x);i<=lm&&x!=1;++i){
		if(x!=x/i*i)continue;
		divv.pb(i);
		while(x==x/i*i)x/=i;
	}
	if(x^1)divv.pb(x);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	x=read();
	n=readl();
	divid(x);
	int res=1;
	for(ri i=divv.size()-1;~i;--i){
		ll mt=divv[i];
		while(1){
			int tot=(n/mt-n/mt/divv[i])%(mod-1);
			Mul(res,ksm((ll)mt%mod,tot));
			if(!(n/mt/divv[i]))break;
			mt*=divv[i];
		}
	}
	cout<<res;
	return 0;
}