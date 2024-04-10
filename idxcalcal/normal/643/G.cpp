#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef pair<int,int> pii;
const int N=150005;
int lim=0;
struct F{
	pii a[7];
	int siz;
	inline void clear(){for(ri i=1;i<=siz;++i)a[i]=pii(0,0),siz=0;}
	inline int size()const{return siz;}
	inline void push_back(pii t){a[++siz]=t;}
	inline void pop_back(){a[siz--]=pii(0,0);}
	inline pii back(){return a[siz];}
	inline void fix(){
		int tp=0;
		for(ri i=1;i<=siz;++i)if(a[i].se>0)a[++tp]=a[i];
		for(ri i=siz;i>tp;--i)a[i]=pii(0,0);
		siz=tp;
	}
};
inline F operator+(F a,F b){
	a.fix(),b.fix();
	for(ri i=1;i<=b.siz;++i){
		bool ff=0;
		for(ri j=1;j<=a.siz;++j)if(a.a[j].fi==b.a[i].fi){
			ff=1;
			a.a[j].se+=b.a[i].se;
			break;
		}
		if(ff)continue;
		a.push_back(b.a[i]);
		if(a.siz<=lim)continue;
		sort(a.a+1,a.a+a.siz+1,[](pii a,pii b){return a.se>b.se;});
		for(ri i=a.size();i^lim;--i){
			for(ri j=1;j<i;++j)a.a[j].se-=a.a[i].se;
			a.pop_back();
		}
		a.fix();
	}
	return a;
}
int a[N];
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	F vl[N<<2];
	int tg[N<<2];
	bool cov[N<<2];
	inline void pushup(int p){vl[p]=vl[lc]+vl[rc];}
	inline void pushnow(int p,int l,int r,int v){
		cov[p]=1,tg[p]=v;
		vl[p].clear();
		vl[p].push_back(pii(v,r-l+1));
	}
	inline void pushdown(int p,int l,int r){
		if(cov[p]){
			cov[p]=0;
			pushnow(lc,l,mid,tg[p]);
			pushnow(rc,mid+1,r,tg[p]);
		}
	}
	inline void build(int p,int l,int r){
		if(l==r){
			vl[p].clear();
			vl[p].push_back(pii(a[l],1));
			return;
		}
		build(lc,l,mid),build(rc,mid+1,r);
		pushup(p);
	}
	inline void update(int p,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr)return pushnow(p,l,r,v);
		pushdown(p,l,r);
		if(qr<=mid)update(lc,l,mid,ql,qr,v);
		else if(ql>mid)update(rc,mid+1,r,ql,qr,v);
		else update(lc,l,mid,ql,qr,v),update(rc,mid+1,r,ql,qr,v);
		pushup(p);
	}
	inline F query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return vl[p];
		pushdown(p,l,r);
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(ql>mid)return query(rc,mid+1,r,ql,qr);
		return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
	}
	#undef lc
	#undef rc
	#undef mid
}
inline void print(F a){
	cout<<a.size()<<' ';
	for(ri i=1;i<=a.size();++i)cout<<a.a[i].fi<<' ';
	puts("");
}
int n,m;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read(),lim=100/read();
	for(ri i=1;i<=n;++i)a[i]=read();
	sgt::build(1,1,n);
	for(ri op,l,r;m;--m){
		op=read(),l=read(),r=read();
		if(op==1)sgt::update(1,1,n,l,r,read());
		else print(sgt::query(1,1,n,l,r));
	}
	return 0;
}