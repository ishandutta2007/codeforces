#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:a-=mod;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=1e5+5;
ll n,m,a,b,g;
inline ll query(ll x,ll y){
	if(x==1){
		return (y-1)/a+1;
	}
	else{
		return (y-1)/b+1;
	}
}
signed main(){
	n=readl(),m=readl();
	g=__gcd(n,m),a=n/g,b=m/g;
	ll y1,y2;
	for(ri x1,x2,tt=read();tt;--tt){
		x1=read(),y1=readl();
		x2=read(),y2=readl();
		puts(query(x1,y1)==query(x2,y2)?"YES":"NO");
	}
	return 0;
}