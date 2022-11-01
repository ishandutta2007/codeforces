#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<iomanip>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define ll unsigned long long
#define db long double
#define vl t[v].l
#define vr t[v].r
using namespace std;
const int N=5e4+5,mo=1e9+7;
int n,m,q,cc,f[N],p[N],la[N],ne[N];
int ld[N],hv[N],ds,w[N],d[N],rt[N];
int op,x,W,L,R,ts;
ll C,c[N],ss[N],s[N];
struct no{
	int l,r;
	ll v,x;
}t[N*100];
void dfs(int x){
	ld[x]=1;d[x]=d[p[x]]+1;
	ff(i,x)dfs(i),ld[x]+=ld[i],(ld[hv[x]]<ld[i]?hv[x]=i:0);
}
void df2(int x,int st){
	ld[x]=st;w[x]=++ds;
	if(!hv[x])return;
	df2(hv[x],st);
	ff(i,x)if(i!=hv[x])df2(i,i);
}
void fill(int v,int l,int r,ll x){
	t[v].x+=x;t[v].v+=x*(r-l+1);
}
void aa(int v,int l,int m,int r){
	if(t[v].x){
		!vr?vr=++ts:0;!vl?vl=++ts:0;
		fill(vr,m+1,r,t[v].x);fill(vl,l,m,t[v].x);
		t[v].x=0;
	}
}
void chh(int &v,int l,int r,ll x){
	if(!v)v=++ts;
	if(L<=l&&r<=R){fill(v,l,r,x);return;}
	int m=l+r>>1;
	aa(v,l,m,r);
	if(L<=m)chh(vl,l,m,x);
	if(m<R)chh(vr,m+1,r,x);
	t[v].v=t[vl].v+t[vr].v;
}
ll gett(int v,int l,int r){
	if(L<=l&&r<=R)return t[v].v;
	int m=l+r>>1;
	aa(v,l,m,r);
	return (L<=m?gett(vl,l,m):0)+(m<R?gett(vr,m+1,r):0);
}
ll get(int a,int x){
	ll t=0;
	for(;x;x=p[ld[x]])L=w[ld[x]],R=w[x],t+=gett(rt[a],1,n);
	return t;
}
void add(int a,int x,ll va){
	for(;x;x=p[ld[x]])L=w[ld[x]],R=w[x],chh(rt[a],1,n,va);
}
void ch(int a,int x,ll va){
	s[a]+=va*d[x];
	if(va==-1)ss[a]-=get(a,x)*2-d[x];
	add(a,x,va);
	if(va==1)ss[a]+=get(a,x)*2-d[x];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&q,&cc);C=cc;
	fo(i,1,n)scanf("%d",&f[i]);
	fo(i,2,n)scanf("%d",&p[i]),ne[i]=la[p[i]],la[p[i]]=i;
	fo(i,1,m)scanf("%d",&cc),c[i]=cc;
	dfs(1);df2(1,1);
	fo(i,1,n)ch(f[i],i,1);
	fo(t,1,q){
		scanf("%d%d",&op,&x);
		if(op==1){
			scanf("%d",&W);
			ch(f[x],x,-1);ch(f[x]=W,x,1);
		}else
			cout<<setprecision(20)<<(db)(ss[x]*c[x]*c[x]-2*C*s[x]*c[x]+C*C*n)/(db)n<<endl;
	}
}