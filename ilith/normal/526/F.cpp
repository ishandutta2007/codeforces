#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define mid (l+r>>1)
#define lc k<<1
#define rc lc|1
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=300010,inf=998244353;
int n,a[N],x,y;
pii t[N<<2];
ll ans;
int add[N<<2];
pii merge(pii x,pii y){
	pii z=pii(min(x.fi,y.fi),0);
	if(z.fi==x.fi)z.se+=x.se;
	if(z.fi==y.fi)z.se+=y.se;
	return z;
}
void pup(int k){t[k]=merge(t[lc],t[rc]);}
void pdown(int k){
	t[lc].fi+=add[k],t[rc].fi+=add[k];
	add[lc]+=add[k],add[rc]+=add[k],add[k]=0;
}
void build(int k,int l,int r){
	if(l==r)return void(t[k]=pii(l,1));
	build(lc,l,mid),build(rc,mid+1,r),pup(k);
}
void upd(int x,int y,int v,int k=1,int l=1,int r=n){
	if(l>y||r<x)return;
	if(l>=x&&r<=y)return t[k].fi+=v,void(add[k]+=v);
	pdown(k),upd(x,y,v,lc,l,mid),upd(x,y,v,rc,mid+1,r),pup(k);
}
pii qry(int x,int y,int k=1,int l=1,int r=n){
	if(l>y||r<x)return pii(inf,0);
	if(l>=x&&r<=y)return t[k];
	pdown(k);
	return merge(qry(x,y,lc,l,mid),qry(x,y,rc,mid+1,r));
}
int mx[N],cx,mi[N],ci;
int main(){
	read(n),build(1,1,n);
	for(rgi i=1;i<=n;++i)read(x),read(a[x]);
	for(rgi i=1;i<=n;++i){
		while(cx&&a[mx[cx]]<a[i])upd(mx[cx-1]+1,mx[cx],-a[mx[cx]]),--cx;
		while(ci&&a[mi[ci]]>a[i])upd(mi[ci-1]+1,mi[ci],a[mi[ci]]),--ci;
		upd(mx[cx]+1,i,a[i]),upd(mi[ci]+1,i,-a[i]),mx[++cx]=mi[++ci]=i;
		pii res=qry(1,i);
		if(res.fi==i)ans+=res.se;
	}
	write(ans);
    return 0;
}