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
typedef pair<int,int> pii;
typedef long long ll;
const int mod=1e9+7;
inline int add(const int&a,const int&b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(const int&a,const int&b){return a>=b?a-b:a-b+mod;}
inline int mul(const int&a,const int&b){return (ll)a*b%mod;}
inline void Add(int&a,const int&b){a=a+b>=mod?a+b-mod:a+b;}
inline void Dec(int&a,const int&b){a=a>=b?a-b:a-b+mod;}
inline void Mul(int&a,const int&b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=2e5+5,M=4e5+5;
int n,mp[M],sig=0;
pii a[N];
struct Node{
	int a,b;
	friend inline Node operator+(const Node&a,const Node&b){
		if(a.a<b.a)return a;
		if(a.a>b.a)return b;
		return (Node){a.a,add(a.b,b.b)};
	}
};
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	Node T[M<<2];
	inline void build(int p,int l,int r){
		T[p]=(Node){0x3f3f3f3f,0};
		if(l==r)return;
		build(lc,l,mid),build(rc,mid+1,r);
	}
	inline void update(int p,int l,int r,int k,Node v){
		if(l==r){T[p]=T[p]+v;return;}
		k<=mid?update(lc,l,mid,k,v):update(rc,mid+1,r,k,v);
		T[p]=T[lc]+T[rc];
	}
	inline Node query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return T[p];
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(ql>mid)return query(rc,mid+1,r,ql,qr);
		return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
	}
	#undef lc
	#undef rc
}
int main(){
	n=read();
	for(ri i=1;i<=n;++i){
		a[i].se=read();
		a[i].fi=read();
		mp[++sig]=a[i].fi;
		mp[++sig]=a[i].se;
	}
	sort(mp+1,mp+sig+1);
	sort(a+1,a+n+1);
	sig=unique(mp+1,mp+sig+1)-mp-1;
	sgt::build(1,1,sig);
	int mx=mp[lower_bound(mp+1,mp+sig+1,a[n].fi)-mp];
	for(ri p1,p2,i=1;i<=n;++i){
		if(a[i].se>mx)continue;
		p1=lower_bound(mp+1,mp+sig+1,a[i].fi)-mp;
		p2=lower_bound(mp+1,mp+sig+1,a[i].se)-mp;
		Node t=sgt::query(1,1,sig,1,p1);
		if(t.a==0x3f3f3f3f)sgt::update(1,1,sig,p2,(Node){a[i].fi-a[i].se,1});
		else sgt::update(1,1,sig,p2,(Node){t.a+a[i].fi-a[i].se,t.b});
	}
	Node ans=(Node){0x3f3f3f3f,0};
	for(ri p1,p2,i=1;i<=n;++i){
		if(a[i].se<=mx)continue;
		p1=lower_bound(mp+1,mp+sig+1,a[i].fi)-mp;
		p2=lower_bound(mp+1,mp+sig+1,a[i].se)-mp;
		Node t=sgt::query(1,1,sig,1,p1);
		if(t.a==0x3f3f3f3f)ans=ans+(Node){t.a,1};
		else ans=ans+(Node){t.a+a[i].fi,t.b};
	}
	cout<<ans.b;
	return 0;
}