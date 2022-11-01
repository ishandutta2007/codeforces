#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define link2(x,y)(ne2[++js]=la2[x],la2[x]=js,to2[js]=y)
#define link3(x,y)(ne3[++js]=la3[x],la3[x]=js,to3[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define ff2(i,x)for(int i=la2[x];i;i=ne2[i])
#define ff3(i,x)for(int i=la3[x];i;i=ne3[i])
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define ll long long
#define ui unsigned int 
#define get(x)(x>n?x-n:x)
const int N=1e5+5,mo=998244353;
int n,m,h,u[N],x,y;
int la[N*2],ne[N*4],to[N*4],df[N*2],lo[N*2],js;
int la2[N*2],ne2[N*4],to2[N*4],d[N*2];
int la3[N*2],ne3[N*4],to3[N*4];
int z[N*2],zs,be[N*2],bs,du[N*2],t,w,g[N*2];
int wz,gg;
int k,an[N],bb[N*2];
bool zz[N*2],bz[N*2];
int ts,rt[N*2];
struct no{
	int l,r;
	ui v;
}tt[N*100];
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
void dfs(int x,int ff){
	df[x]=lo[x]=++y;z[++zs]=x;zz[x]=1;
	ff(i,x)if(df[to[i]]){
		if(zz[to[i]])lo[x]=min(lo[x],df[to[i]]);
	}else
		dfs(to[i],x),lo[x]=min(lo[x],lo[to[i]]);
	if(lo[x]==df[x]){
		for(++bs;zz[x];zz[z[zs--]]=0)be[z[zs]]=bs,(z[zs]>n?g[bs]++:0),link3(bs,z[zs]);
	}
}
void dff(int x){
	if(g[x]<0)return;
	if(g[x]>0&&g[x]<gg)wz=x,gg=g[x];
	if(g[x])return;
	int y;
	ff2(i,x){
		y=to2[i];
		if(!--du[y])dff(y);
	}
}
void ch(int &v,int l,int r,int x,int y){
	if(!v)v=++ts;tt[v].v|=(ui)1<<y;
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m)ch(tt[v].l,l,m,x,y);else ch(tt[v].r,m+1,r,x,y);
}
int mer(int &v,int v1,int l,int r){
	if(!v1)return 0;
	if(!v){v=v1;return 0;}
	if(l==r){
		tt[++ts]=tt[v];v=ts;
		if(tt[v].v&tt[v1].v)return 1;
		tt[v].v|=tt[v1].v;
		return 0;
	}
	int m=l+r>>1;
	tt[++ts]=tt[v];v=ts;
	if(mer(tt[v].l,tt[v1].l,l,m))return 1;
	return mer(tt[v].r,tt[v1].r,m+1,r);
}
void dfs3(int x){
	if(bb[x])
		ff3(i,x)
			zz[to3[i]]=1;
	int y;
	ff2(i,x){
		y=to2[i];
		bb[y]=mer(rt[y],rt[x],0,n>>5);
		if(!--du[y])dff(y);
	}
}
void find(int x){
	bz[x]=1; 
	if(x>n)an[++k]=x-n;
	ff(i,x)if(!bz[to[i]])find(to[i]);
}
int main(){
//	freopen("a.in","r",stdin);
	R(n);R(m);R(h);
	fo(i,1,n)R(u[i]);js=1;
	fo(i,1,m){
		R(x);R(y);
		if(u[x]==u[y])link(x+n,y),link(x,y+n),link(y,x+n),link(y+n,x);
		if(u[x]==(u[y]+1)%h)link(y+n,x+n);
		if(u[y]==(u[x]+1)%h)link(x+n,y+n);
	}y=0;js=0;
	fo(i,1,n+n)if(!df[i])dfs(i,0);js=0;
	fo(i,1,n+n)ff(j,i)if(be[to[j]]!=be[i])
		link2(be[to[j]],be[i]),du[be[i]]++;
	fo(i,1,n+n)ch(rt[be[i]],0,n>>5,get(i)>>5,get(i)&31);
	fo(i,1,bs)if(!du[i])dfs3(i);
	fo(i,1,n+n)if(i<=n){
		if(zz[i]&&!bz[i+n])find(i+n);
	}else{
		if(zz[i])g[be[i]]=-1,find(i-n);
	}
	if(!k){
		fo(i,1,n+n)ff(j,i)if(be[to[j]]!=be[i])du[be[i]]++;
		gg=n+1;
		fo(i,1,bs)if(!du[i])dff(i);
		ff3(i,wz)if(to3[i]>n&&!zz[to3[i]])an[++k]=to3[i]-n;
	}
	printf("%d\n",k);
	fo(i,1,k)printf("%d ",an[i]);
}