#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rgi register int
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
const int N=200010,B=2510;
int n,m,a[N],b[N],s[N],v;
pii mdf[N];
int pos[N];
struct node{
	int opt,l,r,t;
	inline void init(int x){
		read(opt,l,r),t=x;
		if(opt==2)s[++v]=r;
	}
	inline void upd(){
		if(opt==2){
			r=lower_bound(s+1,s+v+1,r)-s;
			mdf[t]=pii(b[pos[t]=l],r),b[l]=r;
		}
	}
}q[N];
int w[N],c[N],ans[N];
int l=1,r,t;
inline void upd(int x,int v){--w[c[x]],++w[c[x]+=v];}
inline void add(int k,int v){
	int x=mdf[k].fi,y=mdf[k].se;
	if(pos[k]>=l&&pos[k]<=r)upd(x,-v),upd(y,v);
	a[pos[k]]=(~v?y:x);
}
inline int qmex(){for(rgi i=1;;++i)if(!w[i])return i;}
signed main(){
	read(n,m),v=n;
	for(rgi i=1;i<=n;++i)read(a[i]),s[i]=a[i];
	for(rgi i=1;i<=m;++i)q[i].init(i);
	sort(s+1,s+v+1),v=unique(s+1,s+v+1)-s-1;
	for(rgi i=1;i<=n;++i)b[i]=a[i]=lower_bound(s+1,s+v+1,a[i])-s;
	for(rgi i=1;i<=m;++i)q[i].upd();
	sort(q+1,q+m+1,[&](node x,node y){return x.l/B==y.l/B?(x.r/B==y.r/B?x.t<y.t:x.r<y.r):x.l<y.l;});
	for(rgi i=1;i<=m;++i){
		if(q[i].opt==2)continue;
		while(l>q[i].l)upd(a[--l],1);
		while(r<q[i].r)upd(a[++r],1);
		while(l<q[i].l)upd(a[l++],-1);
		while(r>q[i].r)upd(a[r--],-1);
		while(t>q[i].t)add(t--,-1);
		while(t<q[i].t)add(++t,1);
		ans[q[i].t]=qmex();
	}
	for(rgi i=1;i<=m;++i)if(ans[i])write(ans[i],'\n');
	return 0;
}
/*
50 16
36 88 67 7 34 83 30 18 55 9 99 42 41 47 1 76 88 24 91 72 59 64 8 35 84 61 37 94 91 8 74 49 22 78 89 28 52 65 10 81 85 62 46 80 76 2 39 46 49 58
2 7 84
2 15 80
2 4 41
1 13 16
2 26 26
2 29 80
2 21 92
1 4 33
2 43 44
2 37 91
2 38 78
2 19 49
2 41 26
2 17 52
2 11 69
1 26 29

*/