// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,m;
struct point{
	long long x,y;
	point (long long xx=0,long long yy=0){
		x=xx; y=yy;
	}
}d[2][maxn],f[2][maxn],ans[maxn*30],ans2[maxn*30];
int x,y,wa,wb,anss,anss2;
int r[2];
struct node{
	int u,a,b,las;
}a[maxn*2],b[maxn*2];
point operator + (point a,point b){ return point(a.x+b.x,a.y+b.y); }
point operator - (point a,point b){ return point(a.x-b.x,a.y-b.y); }
double operator * (point a,point b){ return ((double)1.0*a.x*b.y-(double)1.0*a.y*b.x); }
bool operator < (point a,point b){ return ((a.x<b.x)||((a.x==b.x)&&(a.y<b.y))); }
int f1a[maxn],f1b[maxn],th1,th2,c[maxn];
void add1(int x,int y,int wa,int wb){
	th1++; a[th1].u=y; a[th1].a=wa; a[th1].b=wb; a[th1].las=f1a[x]; f1a[x]=th1;
}
void add2(int x,int y,int wa,int wb){
	th2++; b[th2].u=y; b[th2].a=wa; b[th2].b=wb; b[th2].las=f1b[x]; f1b[x]=th2;
	th2++; b[th2].u=x; b[th2].a=wa; b[th2].b=wb; b[th2].las=f1b[y]; f1b[y]=th2;
}
void dfs1(int x,int fa){
	int i=f1a[x],t=0;
	while (i!=0){
		if (a[i].u!=fa){
			dfs1(a[i].u,x);
			t++; if (t>=2){ n++; add2(c[x],n,0,0); c[x]=n; }
			add2(c[x],a[i].u,a[i].a,a[i].b);
		}
		i=a[i].las;
	}
}
int w[2],ww,www,siz[maxn],wwww;
void getw(int x,int fa,int faa){
	int i=f1b[x],t;
	siz[x]=1;
	while (i!=0){
		if ((b[i].u!=0)&&(b[i].u!=fa)){
			getw(b[i].u,x,i);
			siz[x]=siz[x]+siz[b[i].u];
		}
		i=b[i].las;
	}
	t=max(siz[x],www-siz[x]);
	if ((fa!=0)&&(ww>t)){ w[0]=x; w[1]=fa; ww=t; wwww=faa; }
}
void dfs2(int k,int x,int fa,long long wa,long long wb){
	int i=f1b[x],t=0;
	while (i!=0){
		if ((b[i].u!=0)&&(b[i].u!=fa)){
			dfs2(k,b[i].u,x,wa+b[i].a,wb+b[i].b);
			t++;
		}
		i=b[i].las;
	}
	if (t==0){ r[k]++; d[k][r[k]].x=wa; d[k][r[k]].y=wb; }
}
void work(int x,int tot){
	if (tot==1) return;
	w[0]=0; w[1]=0; ww=1e9; www=tot; wwww=0; getw(x,0,0);
	int i,k,j,t1,t2,t3,t4;
	for (k=0;k<=1;k++){
		r[k]=0; dfs2(k,w[k],w[k^1],0,0);
		sort(d[k]+1,d[k]+r[k]+1);
		j=1; f[k][1]=d[k][1];
		for (i=2;i<=r[k];i++){
			while ((j>1)&&( (f[k][j]-f[k][j-1])*(d[k][i]-f[k][j-1])>=0 )) j--;
			j++; f[k][j]=d[k][i];
		}
		r[k]=j;
	}
	i=1; j=1;
	while ((i!=r[0])||(j!=r[1])){
		anss++; ans[anss]=f[0][i]+f[1][j]; ans[anss].x=ans[anss].x+b[wwww].a; ans[anss].y=ans[anss].y+b[wwww].b;
		if (i==r[0]){ j++; continue; }
		if (j==r[1]){ i++; continue; }
		if ((f[0][i+1]-f[0][i])*(f[1][j+1]-f[1][j])>0) j++;
		else i++;
	}
	anss++; ans[anss]=f[0][i]+f[1][j]; ans[anss].x=ans[anss].x+b[wwww].a; ans[anss].y=ans[anss].y+b[wwww].b;
	b[wwww].u=0; if (wwww%2==1) b[wwww+1].u=0; else b[wwww-1].u=0;
	t1=w[0]; t2=siz[w[0]]; t3=w[1]; t4=tot-siz[w[0]];
	work(t1,t2); work(t3,t4);
}
int main(){
	n=read(); m=read();
	for (i=1;i<n;i++){
		x=read(); y=read(); wa=read(); wb=read();
		add1(x,y,wa,wb); add1(y,x,wa,wb);
	}
	for (i=1;i<=n;i++) c[i]=i;
	dfs1(1,0);
	work(1,n);
	sort(ans+1,ans+anss+1);
	j=1; ans2[1]=ans[1];
	for (i=2;i<=anss;i++){
		while ((j>1)&&( (ans2[j]-ans2[j-1])*(ans[i]-ans2[j-1])>=0 )) j--;
		j++; ans2[j]=ans[i];
	}
	anss2=j; j=1;
	for (i=0;i<m;i++){
		while ((j<anss2)&&(ans2[j].x*i+ans2[j].y<=ans2[j+1].x*i+ans2[j+1].y)) j++;
		printf("%I64d\n",ans2[j].x*i+ans2[j].y);
	}
	return 0;
}
/*
5 10
1 2 0 100
1 3 0 100
1 4 10 80
1 5 20 0
*/