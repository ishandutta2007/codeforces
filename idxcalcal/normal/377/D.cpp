#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<tr1/unordered_map>
#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define rsz resize
#define sz(x) (int)(x).size()
#define lb lower_bound
#define rb upper_bound
#define all(x) (x).begin() (x).end()
using namespace std;
using namespace __gnu_pbds;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline vector<char>Read(){
	char ch=gc();
	vector<char>res;
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))res.pb(ch),ch=gc();
	return res;
}
typedef long long ll;
inline ll readl(){
	ll ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;	
}
inline char gch(){
	char ch=gc();
	while(!isalpha(ch))ch=gc();
	return ch;
}
typedef pair<int,int> pii;
const int mod=10007;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (int)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int fix(const int&x){return (x%mod+mod)%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
inline int sgn(int x){return (x>0)-(x<0);}
const double pi=acos(-1.0),eps=1e-16;
inline double sgn(double x){return (x>eps)-(x<-eps);}
const int N=3e5+5;
int n,mnx,mxx,mny,mxy;
vector<pii>upd1[N],upd2[N];
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	pii mx[N<<2];
	int tg[N<<2];
	inline void pushup(int p){mx[p]=max(mx[lc],mx[rc]);}
	inline void pushnow(int p,int v){mx[p].fi+=v,tg[p]+=v;}
	inline void pushdown(int p){if(tg[p])pushnow(lc,tg[p]),pushnow(rc,tg[p]),tg[p]=0;}
	inline void build(int p,int l,int r){
		mx[p]=pii(0,r);
		if(l==r)return;
		build(lc,l,mid),build(rc,mid+1,r);
	}
	inline void update(int p,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr)return pushnow(p,v);
		pushdown(p);
		if(qr<=mid)update(lc,l,mid,ql,qr,v);
		else if(ql>mid)update(rc,mid+1,r,ql,qr,v);
		else update(lc,l,mid,ql,qr,v),update(rc,mid+1,r,ql,qr,v);
		pushup(p);
	}
	#undef lc
	#undef rc
	#undef mid
}
struct seg{int l,r,v;}a[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),mnx=mny=3e5+1,mxx=mxy=0;
	for(ri l,v,r,i=1;i<=n;++i){
		l=read(),v=read(),r=read();
		mnx=min(mnx,l),mxx=max(mxx,v);
		mny=min(mny,v),mxy=max(mxy,r);
		a[i]=(seg){l,r,v};
		upd1[l].pb(pii(v,r)),upd2[v].pb(pii(v,r));
	}
	int ans=0,px=0,py=0;
	sgt::build(1,mny,mxy);
	for(ri i=mnx;i<=mxx;++i){
		for(ri j=upd1[i].size()-1;~j;--j)sgt::update(1,mny,mxy,upd1[i][j].fi,upd1[i][j].se,1);
		if(sgt::mx[1].fi>ans){
			ans=sgt::mx[1].fi;
			px=i,py=sgt::mx[1].se;
		}
		for(ri j=upd2[i].size()-1;~j;--j)sgt::update(1,mny,mxy,upd2[i][j].fi,upd2[i][j].se,-1);
	}
	cout<<ans<<'\n';
	for(ri i=1;i<=n;++i)if(a[i].l<=px&&px<=a[i].v&&a[i].v<=py&&py<=a[i].r)cout<<i<<' ';
	return 0;
}