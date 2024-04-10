#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(e,i,x)for(int i=e.la[x];i;i=e.ne[i])
using namespace std;
const int N=3e5+5;
int n,m,q,x,y,n1,m1,nn;
int df[N],lo[N],z[N],ds,zs,be[N],bs;
int fa[N],d[N],ld[N],hv[N];
int s[N],ss;
int df2[N],lo2[N],be2[N];
int a[N*3],b[N];
bool zz[N];
long long R;
struct nod{
	int la[N],ne[N*2],to[N*2],js;
	void link(int x,int y){
		ne[++js]=la[x];la[x]=js;to[js]=y;
		ne[++js]=la[y];la[y]=js;to[js]=x;
	}
}e1,e2,e3;
int chs(int x){
	x=(R+x)%n;
	return x==0?n:x;
}
void tar(int x,int j){
	lo[x]=df[x]=++ds;z[++zs]=x;zz[x]=1;
	ff(e1,i,x)if(df[e1.to[i]]){
		if(i!=j)lo[x]=min(lo[x],df[e1.to[i]]);
	}else{
		tar(e1.to[i],i^1);lo[x]=min(lo[x],lo[e1.to[i]]);
	}
	if(lo[x]==df[x])
		for(++bs;zz[x];zz[z[zs--]]=0)be[z[zs]]=bs;
}
void dfs(int x){
	df[x]=++ds;d[x]=d[fa[x]]+1;ld[x]=1;int y;
	ff(e2,i,x)if((y=e2.to[i])!=fa[x])
		fa[y]=x,dfs(y),ld[x]+=ld[y],(ld[y]>ld[hv[x]]?hv[x]=y:0);
	lo[x]=ds;
}
void dfs2(int x,int st){
	ld[x]=st;
	if(!hv[x])return;
	dfs2(hv[x],st);int y;
	ff(e2,i,x)if((y=e2.to[i])!=fa[x]&&y!=hv[x])dfs2(y,y);
}
bool cmp(int x,int y){return df[x]<df[y];}
int lca(int x,int y){
	for(;ld[x]!=ld[y];x=fa[ld[x]])if(d[ld[x]]<d[ld[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
void tar2(int x,int j){
	lo2[x]=df2[x]=++ds;z[++zs]=x;zz[x]=1;
	ff(e3,i,x)if(df2[e3.to[i]]){
		if(i!=j)lo2[x]=min(lo2[x],df2[e3.to[i]]);
	}else{
		tar2(e3.to[i],i^1);lo2[x]=min(lo2[x],lo2[e3.to[i]]);
	}
	if(lo2[x]==df2[x])
		for(++bs;zz[x];df2[z[zs]]=0,zz[z[zs--]]=0)be2[z[zs]]=bs;
}
int main(){
	cin>>n>>m>>q;e1.js=1;
	fo(i,1,m)scanf("%d%d",&x,&y),e1.link(x,y);
	fo(i,1,n)if(!df[i])tar(i,0);
	fo(i,1,n)ff(e1,j,i)if(be[i]<be[e1.to[j]])e2.link(be[i],be[e1.to[j]]);
	ds=0;
	fo(i,1,bs)if(!ld[i])dfs(i),dfs2(i,i);
	fo(o,1,q){
		scanf("%d%d",&n1,&m1);
		fo(i,1,n1)scanf("%d",&a[i]),b[i]=a[i]=be[chs(a[i])];
		nn=n1;
		e3.js=1;
		fo(i,1,m1){
			scanf("%d%d",&x,&y);
			x=be[chs(x)];y=be[chs(y)];
			a[++n1]=x;a[++n1]=y;
			e3.link(x,y);
		}
		sort(a+1,a+n1+1,cmp);n1=unique(a+1,a+n1+1)-a-1;
		fo(i,2,n1){
			x=lca(a[i],a[i-1]);
			if(x)a[++n1]=x;
		}
		sort(a+1,a+n1+1,cmp);n1=unique(a+1,a+n1+1)-a-1;
		ss=0;
		fo(i,1,n1){
			x=a[i];
			for(;ss&&lo[s[ss]]<df[x];)--ss;
			if(ss)e3.link(s[ss],x);
			s[++ss]=x;
		}
		bs=ds=zs=0;
		tar2(b[1],0);
		bool is=1;
		fo(i,2,nn)if(be2[b[1]]!=be2[b[i]])is=0;
		R+=is*o;printf(is?"YES\n":"NO\n");
		fo(i,1,n1)be2[a[i]]=e3.la[a[i]]=0;
	}
}