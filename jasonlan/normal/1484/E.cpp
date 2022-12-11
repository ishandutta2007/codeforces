#include<iostream>
#include<cstdio>
#include<algorithm>
#define mid ((l+r)>>1)
#define ls (p<<1)
#define rs ((p<<1)|1)
using namespace std;
typedef long long ll;
const int maxn=601100;
int n,m;
int h[maxn],b[maxn];
ll f[maxn];
ll tag[maxn<<1],fmx[maxn<<1],tmx[maxn<<1];
bool itag[maxn<<1];
int s[maxn],st;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void update(int p){
	fmx[p]=max(fmx[p<<1],fmx[p<<1|1]);
	tmx[p]=max(tmx[p<<1],tmx[p<<1|1]);
}
void pushtag(int p,ll x){
	tag[p]=x;
	tmx[p]=fmx[p]+x;
	itag[p]=true;
}
void pushdown(int p){
	if(itag[p]){
		pushtag(ls,tag[p]);
		pushtag(rs,tag[p]);
		itag[p]=0;
	}
}
void build(int p,int l,int r){
	fmx[p]=tmx[p]=-(1ll<<50);
	if(l==r)return;
	pushdown(p);
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void modify(int p,int lr,int rr,ll x,int l,int r){
	if(lr<=l&&r<=rr){
		pushtag(p,x);
		return;
	}
	if(lr>r||l>rr)return;
	pushdown(p);
	modify(ls,lr,rr,x,l,mid);
	modify(rs,lr,rr,x,mid+1,r);
	update(p);
}
void insert(int p,int x,int l,int r){
	if(l==r){
		fmx[p]=f[x];
		return;
	}
	pushdown(p);
	if(x<=mid)insert(ls,x,l,mid);
	else insert(rs,x,mid+1,r);
	update(p);
}
void process(){
	n=read();
	for(int i=1;i<=n;++i)
		h[i]=read();
	for(int i=1;i<=n;++i)
		b[i]=read();
	build(1,0,n);
	insert(1,0,0,n);
	for(int i=1;i<=n;++i){
		while(st&&h[i]<h[s[st]])--st;
		if(!st)modify(1,0,i-1,b[i],0,n);
		else modify(1,s[st],i-1,b[i],0,n);
		s[++st]=i;
		f[i]=tmx[1];
		insert(1,i,0,n);
	}
	printf("%lld\n",f[n]);
}
int main(){
	int T=1;
	while(T--)process();
	return 0;
}