#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define link2(x,y)(ne2[++js]=la2[x],la2[x]=js,to2[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,q,x,y,la[N],to[N*2],ne[N*2],js;
int k,m,r,w,a[N];
int ld[N],d[N],fa[N],hv[N],st[N],en[N];
int z[N],zs,b[N*2],bs,dd[N],ds;
ll f[2][305];
int la2[N],to2[N*2],ne2[N*2],p[N],su[N];
bool bz[N];
void go(int x){
	d[x]=d[fa[x]]+1;ld[x]=1;st[x]=++js;
	ff(i,x)if(to[i]!=fa[x])
		fa[to[i]]=x,go(to[i]),ld[x]+=ld[to[i]],(ld[to[i]]>ld[hv[x]]?hv[x]=to[i]:0);
	en[x]=js;
}
void go2(int x,int st){
	ld[x]=st;
	if(!hv[x])return;
	go2(hv[x],st);
	ff(i,x)if(to[i]!=fa[x]&&to[i]!=hv[x])go2(to[i],to[i]);
}
int lca(int x,int y){
	for(;ld[x]!=ld[y];x=fa[ld[x]])if(d[ld[x]]<d[ld[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
bool cmp(int x,int y){return st[x]<st[y];}
void dfs(int x){
	su[x]=su[p[x]]+bz[x];
	if(bz[x]){
		w^=1;
		fo(j,0,m)
			f[w][j]=((j?f[!w][j-1]:0)+(j>su[x]-1?f[!w][j]*(j-(su[x]-1)):0))%mo;
	}
	for(int i=la2[x];i;i=ne2[i])if(to2[i]!=p[x])
		p[to2[i]]=x,dfs(to2[i]);
}
int main(){
	scanf("%d%d",&n,&q);
	fo(i,2,n)scanf("%d%d",&x,&y),link(x,y),link(y,x);
	js=0;
	go(1);go2(1,1);
	for(;q--;){
		scanf("%d%d%d",&k,&m,&r);
		bs=zs=0;
		fo(i,1,k)scanf("%d",&a[i]),b[i]=a[i],bz[a[i]]=1;
		b[bs=k+1]=r;
		sort(b+1,b+bs+1,cmp);
		bs=unique(b+1,b+bs+1)-b-1;
		fo(i,1,bs-1)b[++bs]=lca(b[i],b[i+1]);
		sort(b+1,b+bs+1,cmp);
		bs=unique(b+1,b+bs+1)-b-1;
		js=0;
		fo(i,1,bs){
			x=b[i];
			for(;zs&&en[z[zs]]<st[x];)zs--;
			if(zs)link2(x,z[zs]),link2(z[zs],x);
			z[++zs]=x;
		}
		f[0][0]=1;
		fo(i,1,m)f[0][i]=0;
		w=p[r]=0;dfs(r);
		ll ans=0;
		fo(i,0,m)ans=(ans+f[w][i])%mo;
		fo(i,1,k)bz[a[i]]=0;
		fo(i,1,bs)la2[b[i]]=0;
		printf("%I64d\n",ans);
	}
}