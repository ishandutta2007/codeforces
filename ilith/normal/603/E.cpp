#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
using namespace std;
const int N=600010;
int n,m,ct[N],T,ans[N],rr[N];
struct mem{int t,p,v;};
struct unf{
	int a[N],C=0;mem f[N];
	int& operator[](int x){return a[x];}
	void st(int x,int v){f[++C]={T,x,a[x]},a[x]=v;}
	void rbk(int t){for(;C&&f[C].t>=t;--C)a[f[C].p]=f[C].v;}
}fa,rk,sz;
int rbk(int t){return fa.rbk(t),rk.rbk(t),sz.rbk(t),T=t-1;}
int fd(int x){return fa[x]==x?x:fd(fa[x]);}
int merge(int x,int y){
	int u=fd(x),v=fd(y);
	if(u==v)return !ct[T];
	if(rk[u]<rk[v])swap(u,v);
	ct[T+1]=ct[T]-(sz[u]&sz[v])*2,++T;
	fa.st(v,u),sz.st(u,sz[u]^sz[v]);
	if(rk[u]==rk[v])rk.st(u,rk[u]+1);
	return !ct[T];
}
struct edge{
	int u,v,w,id;
	bool operator<(edge x)const{return w==x.w?id<x.id:w<x.w;}
	void inp(int d){scanf("%d%d%d",&u,&v,&w),id=d;}
	int add(int x){return id<=x?merge(u,v):0;}
}e[N],q[N];
void solve(int l,int r,int L,int R){
	if(L==R)FOR(i,l,r)ans[i]=L;
	if(l>r||L>=R)return;
	int mid=(l+r)/2,t=T+1,y,p=R;
	FOR(i,l,mid)if(rr[i]<L)q[i].add(N);
	y=T+1;
	FOR(i,L,R)if(e[i].add(mid)){p=i;break;}
	ans[mid]=p,rbk(y),solve(mid+1,r,L,p),rbk(t);
	FOR(i,L,p-1)e[i].add(l-1);
	solve(l,mid-1,p,R),rbk(t);
}
signed main(){
	scanf("%d%d",&n,&m),ct[0]=n,e[m+1]={0,0,-1,N};
	FOR(i,1,n)fa[i]=i,sz[i]=1;
	FOR(i,1,m)e[i].inp(i),q[i]=e[i];
	sort(e+1,e+m+1);
	FOR(i,1,m)rr[e[i].id]=i;
	solve(1,m,1,m+1);
	FOR(i,1,m)printf("%d\n",e[ans[i]].w);
	return 0;
}