// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k;
int n,m;
int x,y,z,ans,tx,ty,ans1,ans2;
int dept[maxn],fa[22][maxn];
int f1[maxn],f2[maxn],f3[maxn],th;
int a[maxn]; 
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void add(int x,int y){
	th++; f2[th]=y; f3[th]=f1[x]; f1[x]=th;
}
void dfs(int x,int faa){
	int i=f1[x],j;
	dept[x]=dept[faa]+1;
	fa[0][x]=faa;
	for (j=1;j<=20;j++) fa[j][x]=fa[j-1][fa[j-1][x]]; 
	while (i!=0){
		if (f2[i]!=faa){
			dfs(f2[i],x);
		}
		i=f3[i];
	}
}
int glca(int x,int y){
	if (x==-1) return y;
	if (y==-1) return x;
	int i;
	if (dept[x]<dept[y]) swap(x,y);
	for (i=20;i>=0;i--) if (dept[fa[i][x]]>=dept[y]) x=fa[i][x];
	if (x==y) return x;
	for (i=20;i>=0;i--) if (fa[i][x]!=fa[i][y]){ x=fa[i][x]; y=fa[i][y]; }
	return fa[0][x];
}
struct SegmentTree{
	int l[maxn*4],r[maxn*4],lca[maxn*4];
	void build(int x,int ll,int rr){
		int mid=(ll+rr)>>1;
		l[x]=ll; r[x]=rr;
		if (ll==rr){
			lca[x]=ll;
			return;
		}
		build(x*2,ll,mid);
		build(x*2+1,mid+1,rr);
		lca[x]=glca(lca[x*2],lca[x*2+1]);
	}
	int getlca(int x,int ll,int rr){
		if ((ll<=l[x])&&(r[x]<=rr)){ return lca[x]; }
		if ((r[x]<ll)||(rr<l[x])) return -1;
		return glca(getlca(x*2,ll,rr),getlca(x*2+1,ll,rr));
	}
	void gettot(int x,int ll,int rr){
		if ((ll<=l[x])&&(r[x]<=rr)){ th++; a[th]=x; return; }
		if ((r[x]<ll)||(rr<l[x])) return;
		gettot(x*2,ll,rr); gettot(x*2+1,ll,rr);
	}
}tre;
int main(){
	n=read(); m=read();
	for (i=2;i<=n;i++){
		x=read();
		add(i,x); add(x,i);
	}
	dfs(1,0);
	tre.build(1,1,n);
	for (k=1;k<=m;k++){
		x=read(); y=read(); th=0;
		tre.gettot(1,x,y);
		if (th==1){
			th=2;
			a[2]=a[1]*2+1;
			a[1]=a[1]*2;
		}
		z=tre.lca[a[1]];
		for (i=2;i<=th;i++){
			z=glca(z,tre.lca[a[i]]);
		}
		ans=z;
		z=tre.lca[a[1]];
		for (i=2;i<=th;i++){
			z=glca(z,tre.lca[a[i]]);
			if (z==ans){
				ty=i; break;
			}
		}
		for (i=1;i<ty;i++){
			z=glca(tre.lca[a[i]],tre.lca[a[ty]]);
			if (z==ans){
				tx=i; break;
			}
		}
		tx=a[tx]; ty=a[ty];
		while ((tre.l[tx]!=tre.r[tx])||(tre.l[ty]!=tre.r[ty])){
			if (tre.l[tx]==tre.r[tx]) swap(tx,ty);
			if (glca(tre.lca[tx*2],tre.lca[ty])==ans){
				tx=tx*2;
			}
			else{
				if (glca(tre.lca[tx*2+1],tre.lca[ty])==ans){
					tx=tx*2+1;
				}
				else{
					ty=tx*2+1;
					tx=tx*2; 
				}
			}
		}
		tx=tre.l[tx]; ty=tre.r[ty];
		ans1=glca(tre.getlca(1,x,tx-1),tre.getlca(1,tx+1,y));
		ans2=glca(tre.getlca(1,x,ty-1),tre.getlca(1,ty+1,y));
		if (dept[ans1]>=dept[ans2]){
			printf("%d %d\n",tx,dept[ans1]-1);
		}
		else{
			printf("%d %d\n",ty,dept[ans2]-1);
		}
	}
	return 0;
}