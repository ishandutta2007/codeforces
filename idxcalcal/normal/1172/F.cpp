#include<bits/stdc++.h>
#define ri register int
#define pb push_back
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
typedef long long ll;
const int N=1e6+5;
int n,m,mod,a[N];
ll ss[N];
const ll inf=1e18;
inline void ckmin(ll&a,ll b){a=a<b?a:b;}
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	vector<ll>f[N<<2];
	ll vl;
	inline void build(int p,int l,int r){
		if(l==r){f[p].pb(-inf),f[p].pb(mod-a[l]);return;}
		build(lc,l,mid),build(rc,mid+1,r);
		int n=f[lc].size(),m=f[rc].size();
		f[p].resize(n+m-1,inf);
		ll xl,xr,yl,yr,sl=ss[mid]-ss[l-1];
		for(ri i=0,j=0;i<n;++i){
			xl=f[lc][i],xr=i==n-1?inf:f[lc][i+1]-1;
			yl=xl+sl-(ll)mod*i,yr=xr==inf?inf:xr+sl-(ll)mod*i;
			while(j&&f[rc][j]>yl)--j;
			while(j!=m&&(j==0||f[rc][j]<=yl))++j;
			--j;
			while(j<m&&f[rc][j]<=yr)ckmin(f[p][i+j],max(f[rc][j]-(sl-(ll)mod*i),xl)),++j;
		}
		f[p][0]=-inf;
	}
	inline void query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr){
			vl=vl+ss[r]-ss[l-1]-(ll)mod*(upper_bound(f[p].begin(),f[p].end(),vl)-f[p].begin()-1);
			return;
		}
		if(qr<=mid)query(lc,l,mid,ql,qr);
		else if(ql>mid)query(rc,mid+1,r,ql,qr);
		else query(lc,l,mid,ql,qr),query(rc,mid+1,r,ql,qr);
	}
	#undef lc
	#undef rc
	#undef mid
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read(),mod=read();
	for(ri i=1;i<=n;++i)ss[i]=ss[i-1]+(a[i]=read());
	sgt::build(1,1,n);
	for(ri i=1,l,r;i<=m;++i){
		sgt::vl=0;
		l=read(),r=read();
		sgt::query(1,1,n,l,r);
		cout<<sgt::vl<<'\n';
	}
	return 0;
}