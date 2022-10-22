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
const int N=100010;
int n,m,x;
int sum[21][N<<3],rev[21][N<<3];
inline void pushdown(int k,int l,int r,int w){
	if(rev[w][k]){
		rev[w][k<<1]^=1,rev[w][k<<1|1]^=1;
		sum[w][k<<1]=mid-l+1-sum[w][k<<1];
		sum[w][k<<1|1]=r-mid-sum[w][k<<1|1];
		rev[w][k]=0;
	}
}
void upd(int k,int l,int r,int x,int y,int w){
	if(l>y||r<x)return;
	if(l>=x&&r<=y)return sum[w][k]=r-l+1-sum[w][k],void(rev[w][k]^=1);
	pushdown(k,l,r,w);
	upd(k<<1,l,mid,x,y,w),upd(k<<1|1,mid+1,r,x,y,w);
	sum[w][k]=sum[w][k<<1|1]+sum[w][k<<1];
}
ll qry(int k,int l,int r,int x,int y,int w){
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return sum[w][k];
	pushdown(k,l,r,w);
	return qry(k<<1,l,mid,x,y,w)+qry(k<<1|1,mid+1,r,x,y,w);
}
inline void mdf(int l,int r,int x){
	for(rgi i=20;~i;--i){
		if(x>>i&1)upd(1,1,n,l,r,i);
	}
}
inline ll query(int l,int r){
	ll res=0;
	for(rgi i=20;~i;--i)res+=(1ll<<i)*qry(1,1,n,l,r,i);
	return res;
}
int opt,l,r;
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i)read(x),mdf(i,i,x);
	read(m);
	while(m--){
		read(opt,l,r);
		if(opt==1)write(query(l,r),'\n');
		if(opt==2)read(x),mdf(l,r,x);
	}
	return 0;
}