#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define rgi register int
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
const int block=550,N=300010;
int n,m;
int a[N],s[N],bel[N],lim[N];
struct node{
	int l,r,id;
}q[N];
inline bool operator<(node x,node y){
	return bel[x.l]==bel[y.l]?x.r<y.r:x.l<y.l;
}
inline int count(int l,int r,int now){
	if(now<=(r-l+2)/2)return 1;
	return now-(r-l+1-now);
}
int st[N],res,nl,nr,ans[N],tmp;
int main(){
	read(n,m);
	for(rgi i=1;i<=n;++i)read(a[i]),s[i]=a[i],bel[i]=(i-1)/block+1,lim[bel[i]]=i;
	for(rgi i=1;i<=m;++i)read(q[i].l,q[i].r),q[i].id=i;
	sort(q+1,q+m+1),sort(s+1,s+n+1);
	for(rgi i=1;i<=n;++i)a[i]=lower_bound(s+1,s+n+1,a[i])-s;
	for(rgi i=1;i<=m;++i){
		int x=q[i].l,y=q[i].r;
		if(bel[x]!=bel[nl])memset(st,0,sizeof st),tmp=res,res=0,nl=lim[bel[x]],nr=nl-1;
		while(nr<y)++st[a[++nr]],res=max(res,st[a[nr]]);
		tmp=res;
		for(rgi j=x;j<nl&&j<=y;++j)++st[a[j]],res=max(res,st[a[j]]);
		ans[q[i].id]=res,res=tmp;
		for(rgi j=x;j<nl&&j<=y;++j)--st[a[j]];
	}
	sort(q+1,q+m+1,[&](node a,node b){return a.id<b.id;});
	for(rgi i=1;i<=m;++i)write(count(q[i].l,q[i].r,ans[i]),'\n');
	return 0;
}