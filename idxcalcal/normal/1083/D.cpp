#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
const int mod=1e9+7;
typedef long long ll;
typedef pair<int,int> pii;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=1e5+5;
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	int ss[N<<2],tga[N<<2],tgb[N<<2],sa[N<<2],sb[N<<2],len[N<<2];
	inline void pushup(int p){
		sa[p]=add(sa[lc],sa[rc]);
		sb[p]=add(sb[lc],sb[rc]);
		ss[p]=add(ss[lc],ss[rc]);
	}
	inline void pushnow(int p,int v1,int v2){
		Add(ss[p],mul(v1,sb[p]));
		Add(ss[p],mul(v2,sa[p]));
		Add(ss[p],mul(len[p],mul(v1,v2)));
		Add(sa[p],mul(v1,len[p])),Add(tga[p],v1);
		Add(sb[p],mul(v2,len[p])),Add(tgb[p],v2);
	}
	inline void pushdown(int p){if(tga[p]|tgb[p])pushnow(lc,tga[p],tgb[p]),pushnow(rc,tga[p],tgb[p]),tga[p]=tgb[p]=0;}
	inline void build(int p,int l,int r){
		len[p]=r-l+1;
		if(l==r){sa[p]=l-1;return;}
		build(lc,l,mid),build(rc,mid+1,r);
		pushup(p);
	}
	inline void update(int p,int l,int r,int ql,int qr,int v1,int v2){
		if(ql>qr)return;
		if(ql<=l&&r<=qr)return pushnow(p,v1,v2);
		pushdown(p);
		if(qr<=mid)update(lc,l,mid,ql,qr,v1,v2);
		else if(ql>mid)update(rc,mid+1,r,ql,qr,v1,v2);
		else update(lc,l,mid,ql,qr,v1,v2),update(rc,mid+1,r,ql,qr,v1,v2);
		pushup(p);
	}
	inline int query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return ss[p];
		pushdown(p);
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(ql>mid)return query(rc,mid+1,r,ql,qr);
		return add(query(lc,l,mid,ql,qr),query(rc,mid+1,r,ql,qr));
	}
	#undef lc
	#undef rc
	#undef mid
}
int n,m,pre[N],suf[N],a[N];
pii stk1[N],stk2[N];
int tp1=0,tp2=0;
map<int,int>vs;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i){
		a[i]=read();
		pre[i]=vs.count(a[i])?vs[a[i]]:0;
		vs[a[i]]=i;
	}
	vs.clear();
	for(ri i=n;i;--i){
		suf[i]=vs.count(a[i])?vs[a[i]]:n+1;
		vs[a[i]]=i;
	}
	int res=0,low=0;
	sgt::build(1,1,n);
	for(ri ps,i=1;i<=n;++i){
		low=max(low,pre[i]+1);
		ps=i;
		while(tp1&&stk1[tp1].se<pre[i])sgt::update(1,1,n,stk1[tp1].fi,ps-1,stk1[tp1].se,0),ps=stk1[tp1].fi,--tp1;
		sgt::update(1,1,n,ps,i,mod-pre[i],0);
		stk1[++tp1]=pii(ps,pre[i]);
		ps=i;
		while(tp2&&stk2[tp2].se>suf[i])sgt::update(1,1,n,stk2[tp2].fi,ps-1,0,mod-stk2[tp2].se),ps=stk2[tp2].fi,--tp2;
		sgt::update(1,1,n,ps,i,0,suf[i]);
		stk2[++tp2]=pii(ps,suf[i]);
		sgt::update(1,1,n,low,i,0,mod-i-1);
		Add(res,sgt::query(1,1,n,low,i));
		sgt::update(1,1,n,low,i,0,i+1);
	}
	cout<<res;
	return 0;
}