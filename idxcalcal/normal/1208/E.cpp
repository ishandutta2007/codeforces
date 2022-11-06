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
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
const int mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;} 
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=1e6+50;
int n,w,a[N];
ll ans[N],ad[N];
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	ll mx[N<<2];
	inline void build(int p,int l,int r){
		if(l==r){mx[p]=a[l];return;}
		build(lc,l,mid),build(rc,mid+1,r);
		mx[p]=max(mx[lc],mx[rc]);
	}
	inline int query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mx[p];
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(ql>mid)return query(rc,mid+1,r,ql,qr);
		return max(query(lc,l,mid,ql,qr),query(rc,mid+1,r,ql,qr));
	}
	#undef lc
	#undef rc
	#undef mid
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),w=read()+2;
	for(ri tt=1,m;tt<=n;++tt){
		m=read();
		for(ri i=2;i<=m+1;++i)a[i]=read();
		m+=2;
		a[1]=a[m]=0;
		sgt::build(1,1,m);
		if(w<=m*3-1)for(ri i=1;i<=w;++i)ans[i]+=sgt::query(1,1,m,max(1,i-w+m),min(i,m));
		else{
			for(ri i=1;i<m;++i)ans[i]+=sgt::query(1,1,m,1,i);
			for(ri i=w;i>w-m+1;--i)ans[i]+=sgt::query(1,1,m,m+i-w,m);
			ad[m]+=sgt::mx[1];
			ad[w-m+2]-=sgt::mx[1];
		}
	}
	for(ri i=1;i<=w;++i){
		ad[i]+=ad[i-1];
		ans[i]+=ad[i];
	}
	for(ri i=2;i<=w-1;++i)cout<<ans[i]<<' ';
	return 0;
}