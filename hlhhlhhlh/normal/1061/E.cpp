#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
const int S=2005;
const int T=2006;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int i,j,k;
int n,sx,sy,x,y;
int q0,q1,t,tt,ans,anss;
int c[maxn];
int dist[maxn],d[maxn*maxn],ha[maxn],w[maxn],haa[maxn];
struct node{
	int x,y;
}a[maxn],b[maxn];
int f1[maxn*10],f2[maxn*10],f3[maxn*10],f4[maxn*10],f5[maxn*10],th;
void build(int x,int y,int fl,int fw){
//	printf("%d %d %d %d\n",x,y,fl,fw);
	th++; f2[th]=y; f3[th]=fl; f4[th]=fw; f5[th]=f1[x]; f1[x]=th;
	th++; f2[th]=x; f3[th]=0; f4[th]=-fw; f5[th]=f1[y]; f1[y]=th;
}
struct Tree{
	int f1[maxn],f2[maxn],f3[maxn],th,tot[maxn],faa[maxn],dept[maxn],ha[maxn];
	void add(int x,int y){
		th++; f2[th]=y; f3[th]=f1[x]; f1[x]=th;
	}
	int dfs1(int x,int fa,int xx){
		int i=f1[x],ans=0;
//		printf("%d %d",x,fa);
		faa[x]=fa; dept[x]=dept[fa]+1;
		if ((tot[x]!=0)&&(x!=xx)) return tot[x];
		while (i!=0){
			if (f2[i]!=fa){
				ans=ans+dfs1(f2[i],x,xx);
			}
			i=f3[i];
		}
		return ans;
	}
	void dfs2(int x,int fa,int w,int fla){
		int i=f1[x];
		if (ha[x]==1) return;
		ha[x]=1; 
		if (fla==1) build(w,x,1,0);
		else build(x+n,w,1,0);
		while (i!=0){
			if (f2[i]!=fa){
				dfs2(f2[i],x,w,fla);
			}
			i=f3[i];
		}
	}
}tre1,tre2;
bool cmp1(node a,node b){
	return (tre1.dept[a.x]>tre1.dept[b.x]);
}
bool cmp2(node a,node b){
	return (tre2.dept[a.x]>tre2.dept[b.x]);
}
int SPFA(){
	int i,l,r,x;
	for (i=1;i<maxn;i++) dist[i]=1e9;
	for (i=1;i<maxn;i++) ha[i]=0;
	l=1; r=1; d[l]=S; dist[S]=0; ha[S]=0; w[S]=1e9; haa[S]=-1;
	while (l<=r){
		i=f1[d[l]];
		while (i!=0){
			if ((f3[i]!=0)&&(dist[f2[i]]>dist[d[l]]+f4[i])){
				dist[f2[i]]=dist[d[l]]+f4[i];
				w[f2[i]]=min(f3[i],w[d[l]]);
				haa[f2[i]]=i;
				if (ha[f2[i]]==0){
					r++; d[r]=f2[i]; ha[f2[i]]=1;
				}
			}
			i=f5[i];
		}
		ha[d[l]]=0; d[l]=0; l++;
	}
	if (dist[T]==1e9) return 0;
	ans=ans+dist[T]*w[T]; x=T;
	while (x!=S){
		f3[haa[x]]=f3[haa[x]]-w[T];
		if (haa[x]%2==1){
			f3[haa[x]+1]=f3[haa[x]+1]+w[T];
			x=f2[haa[x]+1];
		}
		else{
			f3[haa[x]-1]=f3[haa[x]-1]+w[T];
			x=f2[haa[x]-1];
		}
	}
	return w[T];
}
int main(){
//	freopen("w.in","r",stdin);
//	freopen("w.out","w",stdout);
	n=read(); sx=read(); sy=read();
	for (i=1;i<=n;i++) c[i]=read();
	for (i=1;i<n;i++){
		x=read(); y=read();
		tre1.add(x,y);
		tre1.add(y,x);
	}
	for (i=1;i<n;i++){
		x=read(); y=read();
		tre2.add(x,y);
		tre2.add(y,x);
	}
	tre1.dfs1(sx,0,0);
	tre2.dfs1(sy,0,0);
	q0=read();
	for (i=1;i<=q0;i++){
		a[i].x=read(); a[i].y=read();
		tre1.tot[a[i].x]=a[i].y;
	}
	for (i=1;i<=q0;i++){
		if (a[i].x==sx){
			anss=max(anss,a[i].y);
			a[i].y=a[i].y-tre1.dfs1(sx,0,sx);
			if (a[i].y<0){
				printf("-1\n");
				return 0;
			}
		}
	}
	for (i=1;i<=q0;i++){
		if (a[i].x!=sx){
			a[i].y=a[i].y-tre1.dfs1(a[i].x,tre1.faa[a[i].x],a[i].x);
			if (a[i].y<0){
				printf("-1\n");
				return 0;
			}
		}
	}
	q1=read();
	for (i=1;i<=q1;i++){
		b[i].x=read(); b[i].y=read();
		tre2.tot[b[i].x]=b[i].y;
	}
	for (i=1;i<=q1;i++){
		if (b[i].x==sy){
			anss=max(anss,b[i].y);
			b[i].y=b[i].y-tre2.dfs1(sy,0,sy);
			if (b[i].y<0){
				printf("-1\n");
				return 0;
			}
		}
	}
	for (i=1;i<=q1;i++){
		if (b[i].x!=sy){
			b[i].y=b[i].y-tre2.dfs1(b[i].x,tre2.faa[b[i].x],b[i].x);
			if (b[i].y<0){
				printf("-1\n");
				return 0;
			}
		}
	}
	if (anss>n){ printf("-1\n"); return 0; }
//	for (i=1;i<=n;i++) printf("%d ",tre1.dept[i]); printf("\n");
//	for (i=1;i<=n;i++) printf("%d ",tre2.dept[i]); printf("\n");
	sort(a+1,a+q0+1,cmp1);
	sort(b+1,b+q1+1,cmp2);
	for (i=1;i<=q0;i++){
		tre1.dfs2(a[i].x,tre1.faa[a[i].x],i+n*2,1);
		build(S,i+n*2,a[i].y,0);
	}
	for (i=1;i<=q1;i++){
		tre2.dfs2(b[i].x,tre2.faa[b[i].x],i+n*3,2);
		build(i+n*3,T,b[i].y,0);
	}
	for (i=1;i<=n;i++){
		build(i,i+n,1,-c[i]);
	}
	tt=0; ans=0; t=SPFA();
//	printf("yes %d %d\n",tt,ans);
	while (t!=0){
		tt=tt+t;
		t=SPFA();
//		printf("yes %d %d\n",tt,ans);
	}
	if (tt==anss) printf("%d\n",-ans);
	else printf("-1\n");
	return 0;
}