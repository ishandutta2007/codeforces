#include<bits/stdc++.h>
#define int ll
#define bg begin()
#define ed end()
#define rgi register int
#define pbk push_back
#define lc k<<1
#define rc lc|1
#define lson lc,l,mid
#define rson rc,mid+1,r
#define mid (l+r>>1)
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
const int N=1000010;
const ll inf=1e17;
ll n,m,P,l,r,sum[N<<2],a[N];
vector<ll>c[N<<2];
void pup(int k,int l,int r){
	c[k].resize(r-l+3,inf),sum[k]=sum[lc]+sum[rc];
	for(rgi i=0,p=0;i<=mid-l+1;++i){
		p=max(p-2,0ll);
		while(p+1<c[rc].size()&&c[lc][i]+sum[lc]-i*P>c[rc][p+1])++p;
		while(p<c[rc].size()&&c[lc][i+1]-1ll+sum[lc]-i*P>=c[rc][p])c[k][i+p]=min(c[k][i+p],max(c[lc][i],c[rc][p]-sum[lc]+i*P)),++p;
	}
}
void build(int k,int l,int r){
	if(l==r)sum[k]=a[l],c[k].pbk(-inf),c[k].pbk(P-a[l]),c[k].pbk(inf);
	else build(lson),build(rson),pup(k,l,r);
}
ll qry(int k,int l,int r,int x,int y,ll v=0){
	if(l>y||r<x)return v;
	if(l>=x&&r<=y)return v+sum[k]-P*(upper_bound(c[k].bg,c[k].ed,v)-c[k].bg-1);
	return qry(rson,x,y,qry(lson,x,y,v));
}
signed main(){
	read(n,m,P);
	for(rgi i=1;i<=n;++i)read(a[i]);
	build(1,1,n);
	while(m--)read(l,r),write(qry(1,1,n,l,r),'\n');
	return 0;
}