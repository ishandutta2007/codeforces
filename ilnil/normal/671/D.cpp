#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define pb push_back
#define ll long long
#define cmin(a,b)(b<a?a=b:0)
using namespace std;
const int N=3e5+5;
int n,m,x,y,ts,js,h;
int u,v[N],c[N],w[N],fa[N],rt[N],de[N];
ll g[N],ans;
int la[N],ne[N*2],to[N*2];
int la1[N],ne1[N];
struct tr{ll ad,mi;int l,r;}t[N*20];
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void dfs(int x){
	de[x]=de[fa[x]]+1;h=max(h,de[x]);int y;
	ff(i,x)if((y=to[i])!=fa[x])fa[y]=x,dfs(y);
}
#define add(v,x)(v?t[v].ad+=x,t[v].mi+=x:0)
#define dw(v)(add(t[v].l,t[v].ad),add(t[v].r,t[v].ad),t[v].ad=0)
void mer(int &v,int v1,int l,int r){
	if(!v||!v1){v^=v1;return;}
	cmin(t[v].mi,t[v1].mi);
	if(l==r)return;
	if(t[v].ad)dw(v);
	if(t[v1].ad)dw(v1);
	int m=l+r>>1;
	mer(t[v].l,t[v1].l,l,m);
	mer(t[v].r,t[v1].r,m+1,r);
}
void ch(int &v,int l,int r,int x,ll y){
	if(!v)v=++ts,t[v].mi=1e18;
	if(t[v].ad)dw(v);
	cmin(t[v].mi,y);
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m)ch(t[v].l,l,m,x,y);else ch(t[v].r,m+1,r,x,y);
}
ll qu(int v,int l,int r,int x){
	if(r<=x||!v)return t[v].mi;
	if(t[v].ad)dw(v);
	int m=l+r>>1;
	if(x<=m)return qu(t[v].l,l,m,x);
	return min(qu(t[v].r,m+1,r,x),t[t[v].l].mi);
}
bool dfs2(int x){
	ll su=0;int y;
	ff(i,x)if((y=to[i])!=fa[x]){
		if(dfs2(y))return 1;
		su+=g[y];
	}
	ff(i,x)if((y=to[i])!=fa[x]){
		add(rt[y],su-g[y]);
		mer(rt[x],rt[y],1,h);
	}
	if(x==1)ans=qu(rt[x],1,h,1);
	for(int i=la1[x];i;i=ne1[i])ch(rt[x],1,h,de[v[i]],su+c[i]);
	if(x>1){
		g[x]=qu(rt[x],1,h,de[x]-1);
		if(g[x]>=1e18)return 1;
	}
	return 0;
}
int main(){
	R(n);R(m);
	if(n==1){
		printf("0\n");return 0;
	}
	fo(i,2,n)R(x),R(y),link(x,y),link(y,x);
	fo(i,1,m)R(u),R(v[i]),R(c[i]),ne1[i]=la1[u],la1[u]=i;
	dfs(1);
	t[0].mi=1e18;
	cout<<(dfs2(1)?-1:ans);
}