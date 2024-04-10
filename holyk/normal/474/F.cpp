#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){char c;int w;
	while(!isdigit(c=getchar()));w=c&15;
	while(isdigit(c=getchar()))w=w*10+(c&15);return w;
}
inline char smax(int&x,const int&y){return x<y?x=y,1:0;}
inline char smin(int&x,const int&y){return x>y?x=y,1:0;}
const int N=1e5+5;
int n,g[N<<2],a[N];
#define ls o<<1
#define rs o<<1|1
inline void build(int o,int l,int r){
	if(l==r)return (void)(g[o]=a[l]);
	int mid=l+r>>1;
	build(ls,l,mid),build(rs,mid+1,r);
	g[o]=__gcd(g[ls],g[rs]);
}
inline int qg(int o,int l,int r,int x,int y){
	if(x<=l&&r<=y)return g[o];
	if(x>r||y<l)return 0;
	int mid=l+r>>1;
	return __gcd(qg(ls,l,mid,x,y),qg(rs,mid+1,r,x,y));
}
#undef ls
#undef rs
struct node{int ls,rs,w;}t[N*35];
int cnt,rt[N];
inline void ins(int&o,int l,int r,int x){
	t[++cnt]=t[o];++t[o=cnt].w;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)ins(t[o].ls,l,mid,x);else ins(t[o].rs,mid+1,r,x);
}
inline int ask(int x,int y,int l,int r,int k){
	if(k==l)return t[y].w-t[x].w;
	int mid=l+r>>1;
	if(k>mid)return ask(t[x].rs,t[y].rs,mid+1,r,k);
	return t[t[y].rs].w-t[t[x].rs].w+ask(t[x].ls,t[y].ls,l,mid,k);
}
#define all 0,1000000002
int main(){
	n=read();
	REP(i,1,n)ins(rt[i]=rt[i-1],all,a[i]=read());
	build(1,1,n);
	int q=read();
	while(q--){
		int l=read(),r=read();
		printf("%d\n",ask(rt[l-1],rt[r],all,qg(1,1,n,l,r)+1));
	}
	return 0;
}