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
typedef pair<int,int> pii;
const int N=120005;
int n,a[N],m,stk1[N],stk2[N],tp1=0,tp2=0;
vector<pii>qry[N];
typedef long long ll;
ll ans[N];
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	int mn[N<<2],tg[N<<2],ad[N<<2];
	ll cnt[N<<2],ss[N<<2];
	inline void pushup(int p){
		mn[p]=min(mn[lc],mn[rc]);
		cnt[p]=0;
		if(mn[p]==mn[lc])cnt[p]+=cnt[lc];
		if(mn[p]==mn[rc])cnt[p]+=cnt[rc];
		ss[p]=ss[lc]+ss[rc];
	}
	inline void pushadd(int p,int v){mn[p]+=v,tg[p]+=v;}
	inline void pushhis(int p,int v){ss[p]+=cnt[p]*v,ad[p]+=v;}
	inline void pushdown(int p){
		if(tg[p])pushadd(lc,tg[p]),pushadd(rc,tg[p]),tg[p]=0;
		if(ad[p]){
			if(mn[lc]==mn[p])pushhis(lc,ad[p]);
			if(mn[rc]==mn[p])pushhis(rc,ad[p]);
			ad[p]=0;
		}
	}
	inline void build(int p,int l,int r){
		if(l==r){mn[p]=l,cnt[p]=1;return;}
		build(lc,l,mid),build(rc,mid+1,r);
		pushup(p);
	}
	inline void update(int p,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr)return pushadd(p,v);
		pushdown(p);
		if(qr<=mid)update(lc,l,mid,ql,qr,v);
		else if(ql>mid)update(rc,mid+1,r,ql,qr,v);
		else update(lc,l,mid,ql,qr,v),update(rc,mid+1,r,ql,qr,v);
		pushup(p);
	}
	inline ll query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return ss[p];
		pushdown(p);
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(ql>mid)return query(rc,mid+1,r,ql,qr);
		return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
	}
	#undef lc
	#undef rc
	#undef mid
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i)a[i]=read();
	m=read();
	for(ri i=1,l,r;i<=m;++i)l=read(),r=read(),qry[r].pb(pii(l,i));
	sgt::build(1,1,n);
	for(ri i=1;i<=n;++i){
		sgt::pushadd(1,-1);
		while(tp1&&a[stk1[tp1]]<a[i])sgt::update(1,1,n,stk1[tp1-1]+1,stk1[tp1],a[i]-a[stk1[tp1]]),--tp1;
		stk1[++tp1]=i;
		while(tp2&&a[stk2[tp2]]>a[i])sgt::update(1,1,n,stk2[tp2-1]+1,stk2[tp2],a[stk2[tp2]]-a[i]),--tp2;
		stk2[++tp2]=i;
		sgt::pushhis(1,1);
		for(ri j=qry[i].size()-1;~j;--j)ans[qry[i][j].se]=sgt::query(1,1,n,qry[i][j].fi,i);
	}
	for(ri i=1;i<=m;++i)cout<<ans[i]<<'\n';
	return 0;
}