#include<bits/stdc++.h>
#define rgi register int
#define mid (l+r>>1)
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
const int N=100010,S=1000010;
int n,m,l,r,v;
struct node{ll k,b;}s[N];
ll val(int a,int x){return s[a].k*x+s[a].b;}
int t[N<<7],ls[N<<7],rs[N<<7],rt[N<<5],C;
int M(int a,int b,int x){return (val(a,x)>val(b,x)?a:b);}
void upd(int x,int& k,int l=0,int r=S){
	if(!k)k=++C;
	if(val(t[k],mid)<val(x,mid))swap(x,t[k]);
	if(val(t[k],l)<val(x,l))upd(x,ls[k],l,mid);
	if(val(t[k],r)<val(x,r))upd(x,rs[k],mid+1,r);
}
int qmin(int x,int k,int l=0,int r=S){
	if(!k||l>x||r<x)return 0;
	if(l==r)return t[k];
	return M(M(qmin(x,ls[k],l,mid),qmin(x,rs[k],mid+1,r),x),t[k],x);
}
void build(int k,int l,int r){
	for(rgi i=l;i<=r;++i)upd(i,rt[k]);
	if(l==r)return;
	build(k<<1,l,mid),build(k<<1|1,mid+1,r);
}
int qry(int x,int y,int v,int k,int l,int r){
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return qmin(v,rt[k]);
	return M(qry(x,y,v,k<<1,l,mid),qry(x,y,v,k<<1|1,mid+1,r),v);
}
signed main(){
	read(n,m);
	for(rgi i=1;i<=n;++i)read(s[i].b,s[i].k);
	build(1,1,n);
	while(m--)read(l,r,v),write(qry(l,r,v,1,1,n),'\n');
	return 0;
}