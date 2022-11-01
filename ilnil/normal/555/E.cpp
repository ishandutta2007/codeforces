#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define link2(x,y)(ne2[++js]=la2[x],la2[x]=js,to2[js]=y)
using namespace std;
const int N=2e5+5;
int n,m,q,js,x,y;
int la[N],ne[N*2],to[N*2];
int la2[N],ne2[N*2],to2[N*2];
int df[N],lo[N],z[N],be[N],zs,ds,bs;
int fa[N],d[N],ld[N],hv[N];
int s[N][2];
bool zz[N];
void tar(int x,int j){
	df[x]=lo[x]=++ds;z[++zs]=x;zz[x]=1;
	for(int i=la[x];i;i=ne[i])if(df[to[i]]){
		if(i!=j)lo[x]=min(lo[x],df[to[i]]);
	}else{
		tar(to[i],i^1);lo[x]=min(lo[x],lo[to[i]]);
	}
	if(lo[x]==df[x])
		for(++bs;zz[x];zz[z[zs--]]=0)be[z[zs]]=bs;
}
void dfs(int x){
	d[x]=d[fa[x]]+1;df[x]=ld[x]=1;lo[++ds]=x;int y;
	for(int i=la2[x];i;i=ne2[i])if((y=to2[i])!=fa[x])
		fa[y]=x,dfs(y),ld[x]+=ld[y],(ld[y]>ld[hv[x]]?hv[x]=y:0);
}
void dfs2(int x,int st){
	ld[x]=st;
	if(!hv[x])return;
	dfs2(hv[x],st);
	for(int i=la2[x];i;i=ne2[i])if(to2[i]!=hv[x]&&to2[i]!=fa[x])dfs2(to2[i],to2[i]);
}
int lca(int x,int y){
	for(;ld[x]!=ld[y];x=fa[ld[x]])if(d[ld[x]]<d[ld[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
int main(){
	cin>>n>>m>>q;js=1;
	fo(i,1,m)scanf("%d%d",&x,&y),link(y,x),link(x,y);
	fo(i,1,n)if(!df[i])tar(i,0);
	js=0;
	fo(i,1,n)for(int j=la[i];j;j=ne[j])if(be[i]!=be[to[j]])
		link2(be[i],be[to[j]]);
	fo(i,1,bs)df[i]=0;ds=0;
	fo(i,1,bs)if(!df[i])dfs(i),df[i]=2;
	fo(i,1,bs)if(df[i]==2)dfs2(i,i);
	fo(i,1,q){
		scanf("%d%d",&x,&y);
		x=be[x];y=be[y];q=lca(x,y);
		if(!q){
			printf("No");
			return 0;
		}
		++s[x][0];--s[q][0];
		++s[y][1];--s[q][1];
	}
	fd(i,1,ds){
		x=lo[i];
		if(s[x][0]&&s[x][1]){
			printf("No");
			return 0;
		}
		s[fa[x]][0]+=s[x][0];s[fa[x]][1]+=s[x][1];
	}
	printf("Yes");
}