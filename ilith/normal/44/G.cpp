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
const int N=100010;
int n,m,seq[N],ans[N],res;
struct node{
	int x,y,id;
	void init(int i){read(x,y),id=i;}
}p[N];
bool cmpx(node a,node b){return a.x<b.x;}
bool cmpy(node a,node b){return a.y<b.y;}
int cmp(int a,int b){return p[a].id<p[b].id?a:b;}
struct rect{
	int xl,xr,yl,yr,mi;
	void init(){read(xl,xr,yl,yr,mi);}
	bool in(rect a){return xl>=a.xl&&xr<=a.xr&&yl>=a.yl&&yr<=a.yr;}
	bool out(rect a){return xl>a.xr||xr<a.xl||yl>a.yr||yr<a.yl;}
}a[N<<2],q[N];
#define pup(s,f) a[k].s=f(a[lc].s,a[rc].s)
void build(int k,int l,int r,int w){
	if(l==r)return void(a[k]=rect{p[l].x,p[l].x,p[l].y,p[l].y,l});
	nth_element(p+l,p+mid,p+r+1,w?cmpx:cmpy),build(lc,l,mid,!w),build(rc,mid+1,r,!w);
	pup(mi,cmp),pup(xl,min),pup(xr,max),pup(yl,min),pup(yr,max);
}
void upd(int x,int k=1,int l=1,int r=m){
	if(l>x||r<x)return;
	if(l==r)return void(a[k].mi=0);
	upd(x,lc,l,mid),upd(x,rc,mid+1,r),pup(mi,cmp);
}
int qry(rect q,int k=1,int l=1,int r=m){
	if(a[k].out(q))return 0;
	if(a[k].in(q))return a[k].mi;
	return cmp(qry(q,lc,l,mid),qry(q,rc,mid+1,r));
}
signed main(){
	read(n),p[0].id=100001;
	for(rgi i=1;i<=n;++i)q[i].init(),seq[i]=i;
	sort(seq+1,seq+n+1,[&](int x,int y){return q[x].mi<q[y].mi;}),read(m);
	for(rgi i=1;i<=m;++i)p[i].init(i);
	build(1,1,m,0);
	for(rgi i=1;i<=n;++i)ans[p[res=qry(q[seq[i]])].id]=seq[i],upd(res);
	for(rgi i=1;i<=m;++i)write(ans[i],'\n');
	return 0;
}