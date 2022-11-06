#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
const int N=1e5+5;
int n,m;
struct F{int lim,spd,edtm,s;}a[25][N];
ll ss1[25][N],ss2[25][N];
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	int upd[N<<2];
	inline void pushup(int p){upd[p]=upd[lc]==upd[rc]?upd[lc]:-1;}
	inline void pushdown(int p){if(upd[p]>=0)upd[lc]=upd[rc]=upd[p];}
	inline void build(int p,int l,int r,int dep){
		upd[p]=-2;
		if(l==r){
			ss1[dep][l]=ss1[dep][l-1]+a[dep][l].lim;
			ss2[dep][l]=ss2[dep][l-1]+a[dep][l].spd;
			return;
		}
		for(ri i=l;i<=r;++i)a[dep+1][i]=a[dep][i];
		build(lc,l,mid,dep+1),build(rc,mid+1,r,dep+1);
		sort(a[dep]+l,a[dep]+r+1,[](F a,F b){return a.edtm<b.edtm;});
		for(ri i=l;i<=r;++i)ss1[dep][i]=ss1[dep][i-1]+a[dep][i].lim;
		for(ri i=l;i<=r;++i)ss2[dep][i]=ss2[dep][i-1]+a[dep][i].spd;
	}
	inline ll query(int p,int l,int r,int ql,int qr,int dep,int tim){
		if(ql<=l&&r<=qr&&~upd[p]){
			ll res=0;
			if(upd[p]==-2)for(ri i=l;i<=r;++i)res+=min((ll)a[dep][i].lim,(ll)a[dep][i].spd*tim+a[dep][i].s);
			else{
				int L=l,R=r,ress=L-1;
				while(L<=R){
					int md=L+R>>1;
					if(upd[p]+a[dep][md].edtm<=tim)L=md+1,ress=md;
					else R=md-1;
				}
				res=ss1[dep][ress]-ss1[dep][l-1]+(ss2[dep][r]-ss2[dep][ress])*(tim-upd[p]);
			}
			return upd[p]=tim,res;
		}
		pushdown(p);
		ll res;
		if(qr<=mid)res=query(lc,l,mid,ql,qr,dep+1,tim);
		else if(ql>mid)res=query(rc,mid+1,r,ql,qr,dep+1,tim);
		else res=query(lc,l,mid,ql,qr,dep+1,tim)+query(rc,mid+1,r,ql,qr,dep+1,tim);
		return pushup(p),res;
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
	for(ri i=1;i<=n;++i){
		a[0][i].s=read();
		a[0][i].lim=read();
		a[0][i].spd=read();
		a[0][i].edtm=a[0][i].spd?(a[0][i].lim/a[0][i].spd+(a[0][i].lim%a[0][i].spd!=0)):0x3f3f3f3f;
	}
	sgt::build(1,1,n,0);
	m=read();
	for(ri tim,l,r,i=1;i<=m;++i){
		tim=read(),l=read(),r=read();
		cout<<sgt::query(1,1,n,l,r,0,tim)<<'\n';
	}
	return 0;
}