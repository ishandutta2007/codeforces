#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
const int mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
inline ll readl(){
	#define gc getchar
	ll ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;} 
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=2e5+5;
int n,w;
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	ll ss[N<<2];
	inline void build(int p,int l,int r){
		if(l==r){ss[p]=l;return;}
		build(lc,l,mid),build(rc,mid+1,r);
		ss[p]=ss[lc]+ss[rc];
	}
	inline void update(int p,int l,int r,int k){
		if(l==r){ss[p]=0;return;}
		if(k<=mid)update(lc,l,mid,k);
		else update(rc,mid+1,r,k);
		ss[p]=ss[lc]+ss[rc];
	}
	inline int query(int p,int l,int r,ll v){
		if(l==r)return l;
		if(ss[lc]>v)return query(lc,l,mid,v);
		return query(rc,mid+1,r,v-ss[lc]);
	}
	#undef lc
	#undef rc
	#undef mid
}
int a[N];
ll s[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
  	sgt::build(1,1,n);
  	for(ri i=1;i<=n;++i)s[i]=readl();
  	for(ri i=n;i;--i){
  		a[i]=sgt::query(1,1,n,s[i]);
  		sgt::update(1,1,n,a[i]);
	}
	for(ri i=1;i<=n;++i)cout<<a[i]<<' ';
	return 0;
}