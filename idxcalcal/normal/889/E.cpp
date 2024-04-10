#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
#define csi const int&
#define fi first
#define se second
#define pb push_back
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
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
	inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
	inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Add(int&a,int b){a=add(a,b);}
	inline void Dec(int&a,int b){a=dec(a,b);}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
	inline int Inv(int x){return ksm(x,mod-2);}
	inline void fix(int&x){x=(x%mod+mod)%mod;}
}
using namespace modular;
template<typename T>inline void ckmin(T&a,const T&b){a>b?a=b:0;}
template<typename T>inline void ckmax(T&a,const T&b){a<b?a=b:0;}
const int N=2e5+5;
map<ll,ll>f;
int n;
ll x,num,vl;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	f[readl()-1]=0;
	for(ri i=2;i<=n;++i){
		x=readl();
		while(f.size()){
			num=f.rbegin()->fi;
			vl=f.rbegin()->se;
			if(num<x)break;
			f.erase(num);
			ckmax(f[x-1],vl+(num-num%x-x)*(i-1));
			ckmax(f[num%x],vl+(num-num%x)*(i-1));
		}
	}
	ll res=0;
	for(map<ll,ll>::iterator it=f.begin();it!=f.end();++it)
	res=max(res,it->fi*n+it->se);
	cout<<res;
	return 0;
}