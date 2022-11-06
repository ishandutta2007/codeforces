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
const int N=4e5+5;
int a[N],n,b[N],dep[N];
namespace sgt1{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	int mx[N<<2],dt[N<<2];
	inline void pushup(int p){mx[p]=max(mx[lc],mx[rc]);}
	inline void pushnow(int p,int v){
		mx[p]+=v;
		dt[p]+=v;
	}
	inline void pushdown(int p){
		if(dt[p]){
			pushnow(lc,dt[p]);
			pushnow(rc,dt[p]);
			dt[p]=0;
		}
	}
	inline void build(int p,int l,int r){
		if(l==r){mx[p]=dep[a[l]];return;}
		build(lc,l,mid),build(rc,mid+1,r);
		pushup(p);
	}
	inline void modify(int p,int l,int r,int k,int v){
		if(l==r){mx[p]=v;return;}
		pushdown(p);
		k<=mid?modify(lc,l,mid,k,v):modify(rc,mid+1,r,k,v);
		pushup(p);
	}
	inline void update(int p,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr)return pushnow(p,v);
		pushdown(p);
		if(qr<=mid)update(lc,l,mid,ql,qr,v);
		else if(ql>mid)update(rc,mid+1,r,ql,qr,v);
		else update(lc,l,mid,ql,qr,v),update(rc,mid+1,r,ql,qr,v);
		pushup(p);
	}
	inline int query(int p,int l,int r,int k){
		if(l==r)return mx[p];
		pushdown(p);
		return k<=mid?query(lc,l,mid,k):query(rc,mid+1,r,k);
	}
}
namespace sgt2{
	int mn[N<<2];
	inline void pushup(int p){mn[p]=min(mn[lc],mn[rc]);}
	inline void build(int p,int l,int r){
		if(l==r){mn[p]=a[l];return;}
		build(lc,l,mid),build(rc,mid+1,r);
		pushup(p);
	}
	inline int Ql(int p,int l,int r,int v){
		if(mn[p]>=v)return -1;
		if(l==r)return l;
		if(mn[lc]<v)return Ql(lc,l,mid,v);
		return Ql(rc,mid+1,r,v);
	}
	inline int Ql(int p,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr)return Ql(p,l,r,v);
		if(qr<=mid)return Ql(lc,l,mid,ql,qr,v);
		if(ql>mid)return Ql(rc,mid+1,r,ql,qr,v);
		int res=Ql(lc,l,mid,ql,qr,v);
		if(~res)return res;
		return Ql(rc,mid+1,r,ql,qr,v);
	}
	inline int Qr(int p,int l,int r,int v){
		if(mn[p]>=v)return -1;
		if(l==r)return l;
		if(mn[rc]<v)return Qr(rc,mid+1,r,v);
		return Qr(lc,l,mid,v);
	}
	inline int Qr(int p,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr)return Qr(p,l,r,v);
		if(qr<=mid)return Qr(lc,l,mid,ql,qr,v);
		if(ql>mid)return Qr(rc,mid+1,r,ql,qr,v);
		int res=Qr(rc,mid+1,r,ql,qr,v);
		if(~res)return res;
		return Qr(lc,l,mid,ql,qr,v);
	}
	#undef lc
	#undef rc
	#undef mid
}
int stk[N],top=0,son[N][2];
void dfs(int p){
	if(son[p][0])dep[son[p][0]]=dep[p]+1,dfs(son[p][0]);
	if(son[p][1])dep[son[p][1]]=dep[p]+1,dfs(son[p][1]);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i)a[i]=a[i+n]=read(),b[a[i]]=i;
	sgt2::build(1,1,n<<1);
	stk[top=1]=a[1];
	for(ri i=2;i<=n;++i){
		int x=0;
		while(top&&stk[top]>a[i])x=stk[top--];
		son[a[i]][0]=x;
		top&&(son[stk[top]][1]=a[i]);
		stk[++top]=a[i];
	}
	dep[1]=1;
	dfs(1);
	sgt1::build(1,1,n);
	int ans=n+1,res=-1;
	for(ri l=1,dt=0,r=n;l<=n;++l,++r,++dt){
		if(ans>sgt1::mx[1])ans=sgt1::mx[1],res=dt;
		int ps1=sgt2::Ql(1,1,n<<1,l,r,a[l]);
		if(~ps1){
			if(ps1<=n+1)sgt1::update(1,1,n,l,ps1-1,-1);
			else sgt1::update(1,1,n,l,n,-1),sgt1::update(1,1,n,1,ps1-1-n,-1);
		}
		else sgt1::pushnow(1,-1);
		int ps2=sgt2::Qr(1,1,n<<1,l+1,r+1,a[l]);
		if(~ps2){
			if(ps2<n)sgt1::update(1,1,n,ps2+1,n,1),sgt1::update(1,1,n,1,r+1-n,1);
			else sgt1::update(1,1,n,ps2+1-n,r+1-n,1);
		}
		else sgt1::pushnow(1,1);
		sgt1::modify(1,1,n,l,~ps2?sgt1::query(1,1,n,ps2<=n?ps2:ps2-n)+1:1);
	}
	cout<<ans<<' '<<res;
	return 0;
}