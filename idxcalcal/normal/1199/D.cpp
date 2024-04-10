#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
	#undef gc
}
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
inline int add(const int&a,const int&b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(const int&a,const int&b){return a>=b?a-b:a-b+mod;}
inline int mul(const int&a,const int&b){return (ll)a*b%mod;}
inline void Add(int&a,const int&b){a=a+b>=mod?a+b-mod:a+b;}
inline void Dec(int&a,const int&b){a=a>=b?a-b:a-b+mod;}
inline void Mul(int&a,const int&b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=2e5+5;
int n,a[N];
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	int mn[N<<2],tg[N<<2];
	inline void pushnow(int p,int v){
		tg[p]=max(tg[p],v);
		mn[p]=max(mn[p],v);
	}
	inline void pushdown(int p){
		if(tg[p])pushnow(lc,tg[p]),pushnow(rc,tg[p]),tg[p]=0;
	}
	inline void build(int p,int l,int r){
		tg[p]=0;
		if(l==r){mn[p]=a[l];return;}
		build(lc,l,mid),build(rc,mid+1,r);
	}
	inline void modify(int p,int l,int r,int k,int v){
		if(l==r){mn[p]=v;return;}
		pushdown(p);
		k<=mid?modify(lc,l,mid,k,v):modify(rc,mid+1,r,k,v);
	}
	inline void print(int p,int l,int r){
		if(l==r){cout<<mn[p]<<' ';return;}
		pushdown(p);
		print(lc,l,mid);
		print(rc,mid+1,r);
	}
	#undef lc
	#undef rc
	#undef mid
}
int main(){
	n=read();
	for(ri i=1;i<=n;++i)a[i]=read();
	sgt::build(1,1,n);
	for(ri op,p,x,tt=read();tt;--tt){
		op=read();
		if(op==1){
			p=read(),x=read();
			sgt::modify(1,1,n,p,x);
		}
		else{
			x=read();
			sgt::pushnow(1,x);
		}
	}
	sgt::print(1,1,n);
	return 0;
}