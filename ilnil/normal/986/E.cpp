#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define link2(x,y,z)(ne2[++j2]=la2[x],la2[x]=j2,to2[j2]=y,cs[j2]=z)
#define ff(x)for(int i=la[x];i;i=ne[i])
#define _(x)(x&-x)
#define ll long long
using namespace std;
const int N=1e5+5,mo=1e9+7,M=1e7+5;
int n,q,x,y,z,f[N],ld[N],d[N],hv[N],s[N],e[N],ds;
int la[N],ne[N*2],to[N*2],js;
int la2[M],ne2[N*16],to2[N*16],cs[N*16],j2;
int an[N],u[N],v[N],lc[N],ca[N];
int p[664600],ps,be[M],g[M],k[M];
int t[N],t1[N];
bool b[M];
struct no{int cs,x;}l[N*2];
bool cmp(no x,no y){return x.cs<y.cs||x.cs==y.cs&&x.x<y.x;}
void R(int &n){
	char c;for(;(c=getchar())<'0'||c>'9';);
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void dfs(int x){
	d[x]=d[f[x]]+1;ld[x]=1;s[x]=e[x]=++ds;int y;
	ff(x)if((y=to[i])!=f[x])f[y]=x,dfs(y),ld[x]+=ld[y],(ld[y]>ld[hv[x]]?hv[x]=y:0),e[x]=e[y];
}
void df(int x,int st){
	ld[x]=st;
	if(!hv[x])return;
	df(hv[x],st);
	ff(x)if((y=to[i])!=f[x]&&y!=hv[x])df(y,y);
}
int lca(int x,int y){
	for(;ld[x]!=ld[y];x=f[ld[x]])if(d[ld[x]]<d[ld[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
void get(int x,int w){
	for(int i=x;i>1;i=be[i])link2(g[i],w,k[i]);
}
ll ksm(ll x,int y){
	ll t=1;for(;y;y>>=1,x=x*x%mo)if(y&1)t=t*x%mo;
	return t;
}
int fi(int x,int y){
	int z=0;
	for(x=s[x];x;x-=_(x))z+=t1[x]-t[x]*y;
	return z;
}
int c(int x){
	int z=0;
	for(x=s[x];x;x-=_(x))z+=t[x];
	return z;
}
int main(){
//	freopen("a.in","r",stdin);
	R(n);
	fo(i,2,n)R(x),R(y),link(x,y),link(y,x);
	dfs(1);df(1,1);
	fo(i,2,10000000){
		if(!b[i])p[++ps]=i,g[i]=i,k[i]=1,be[i]=1;
		for(int j=1;j<=ps&&(y=i*p[j])<=1e7;j++){
			b[y]=1;
			if(i%p[j]==0){
				be[y]=be[i];g[y]=g[i];k[y]=k[i]+1;
				break;
			}
			be[y]=i;g[y]=p[j];k[y]=1;
		}
	}
	fo(i,1,n)R(x),get(x,i);
	R(q);
	fo(i,1,q)R(u[i]),R(v[i]),lc[i]=lca(u[i],v[i]),R(z),an[i]=1,get(z,i+n);
	for(int a=1,i;i=p[a],a<=ps;a++)if(la2[i]){
		js=0;
		for(int j=la2[i];j;j=ne2[j])l[++js].cs=cs[j],l[js].x=to2[j];
		sort(l+1,l+js+1,cmp);
		fo(j,1,js)if((x=l[j].x)>n)x-=n,y=l[j].cs,ca[x]=fi(u[x],y)+fi(v[x],y)-fi(lc[x],y)-fi(f[lc[x]],y);
		else{
			z=l[j].cs;
			for(y=s[x];y<=n;y+=_(y))t[y]++,t1[y]+=z;
			for(y=e[x]+1;y<=n;y+=_(y))t[y]--,t1[y]-=z;
		}
		fo(j,1,js)if((x=l[j].x)>n)x-=n,an[x]=ksm(i,ca[x]+(c(u[x])+c(v[x])-c(lc[x])-c(f[lc[x]]))*l[j].cs)*an[x]%mo;
		fo(j,1,js)if((x=l[j].x)<=n){
			z=l[j].cs;
			for(y=s[x];y<=n;y+=_(y))t[y]--,t1[y]-=z;
			for(y=e[x]+1;y<=n;y+=_(y))t[y]++,t1[y]+=z;
		}
	}
	fo(i,1,q)printf("%d\n",an[i]);
}