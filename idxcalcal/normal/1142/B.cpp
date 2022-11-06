#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:a-=mod;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=2e5+5;
int n,m,q,a[N],b[N],st[N][20],last[N],pre[N],pos[N];
inline int query(int x){
	for(ri t=n-1,i=19;~i;--i){
		if(!(t>>i&1))continue;
		x=st[x][i];
	}
	return x;
}
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	int mx[N<<2];
	inline void build(int p,int l,int r){
		if(l==r){mx[p]=pos[l];return;}
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
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read(),q=read();
	for(ri i=1;i<=n;++i)a[i]=read(),pre[a[i]]=a[i-1];
	pre[a[1]]=a[n];
	for(ri i=1;i<=m;++i){
		b[i]=read();
		last[b[i]]=i;
		st[i][0]=last[pre[b[i]]];
		for(ri j=1;j<20;++j)st[i][j]=st[st[i][j-1]][j-1];
	}
	for(ri i=1;i<=m;++i)pos[i]=query(i);
	sgt::build(1,1,m);
	for(ri l,r;q;--q){
		l=read(),r=read();
		putchar(sgt::query(1,1,m,l,r)>=l?'1':'0');
	}
	return 0;
}