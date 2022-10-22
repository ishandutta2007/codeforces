#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
const long double eps=1e-10;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
struct point{
	long double x,y;
	point (long double xx=0,long double yy=0){
		x=xx; y=yy;
	}
}a[maxn];
long double dis(point a,point b){ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }
long double len(point a){ return sqrt(a.x*a.x+a.y*a.y); }
point operator - (point a,point b){ return point((a.x-b.x),(a.y-b.y)); }
point operator + (point a,point b){ return point((a.x+b.x),(a.y+b.y)); }
point operator / (point a,long double b){ return point((a.x/b),(a.y/b)); }
point operator * (long double a,point b){ return point((a*b.x),(a*b.y)); }
long double dian(point a,point b){ return (a.x*b.x+a.y*b.y); }
int i,j,k;
int n,m,th;
long double ans,l,r,mid,tot,tot1,tot2;
struct node{
	long double l,r;
	int x;
}b[maxn],c[maxn];
struct node2{
	long double x;
	int w;
}dd[maxn*10];
void pan(point a,point b,point c,long double r,long double xx,long double yy){
	if (fabs(xx-yy)<eps) return;
	if (dis(a,b)<eps){
		if (len(a)-r>eps) return;
		while (tot1+tot-xx<eps){ tot1=tot1+tot; tot2=tot2+tot; }
		while (tot1-yy<eps){
			th++; dd[th].x=max(tot1,xx)-tot1; dd[th].w=1;
			th++; dd[th].x=min(tot2,yy)-tot1; dd[th].w=-1;
			tot1=tot1+tot; tot2=tot2+tot;
		}tot1=tot1-tot; tot2=tot2-tot;
		return;
	}
	point d=a+(dian(point(0,0)-a,b-a)/len(b-a))*((b-a)/len(b-a));
//	printf("d=(%.3lf , %.3lf ) r=%.3lf\n",d.x,d.y,r);
	if (len(d)-r>eps) return;
//	printf("yes3\n");
	if ((len(a)-r<eps)&&(len(b)-r<eps)){
		while (tot1+tot-xx<eps){ tot1=tot1+tot; tot2=tot2+tot; }
		while (tot1-yy<eps){
			th++; dd[th].x=max(tot1,xx)-tot1; dd[th].w=1;
			th++; dd[th].x=min(tot2,yy)-tot1; dd[th].w=-1;
			tot1=tot1+tot; tot2=tot2+tot;
		}tot1=tot1-tot; tot2=tot2-tot;
		return;
	}
	long double ll=sqrt(r*r-len(d)*len(d));
	point x=d+ll*((a-d)/len(a-d));
	point y=d+ll*((b-d)/len(b-d));
//	printf("x=(%.3lf , %.3lf )\n",x.x,x.y);
//	printf("y=(%.3lf , %.3lf )\n",y.x,y.y);
	if (dis(x,y)<eps){
		if ((len(a)-r>eps)&&(len(b)-r>eps)) return;
		if (len(a)-r<eps) yy=xx+dis(x,a)/len(c);
		else xx=xx+dis(x,a)/len(c);
	}
	else{
		if (dian(c,x-a)>eps) xx=xx+len(x-a)/len(c);
		if (dian(c,y-a)-dian(c,b-a)<eps) yy=yy-len(y-b)/len(c);
	}
	if (yy-xx>eps){
//		printf("%.3lf %.3lf\n",xx,yy);
		while (tot1+tot-xx<eps){ tot1=tot1+tot; tot2=tot2+tot; }
		while (tot1-yy<eps){
			th++; dd[th].x=max(tot1,xx)-tot1; dd[th].w=1;
			th++; dd[th].x=min(tot2,yy)-tot1; dd[th].w=-1;
			tot1=tot1+tot; tot2=tot2+tot;
		}tot1=tot1-tot; tot2=tot2-tot;
	}
}
void work(long double l,long double r,int x,int y,long double thi){
	if (r-l<eps) return;
	point sx,sy,tx,ty,ds,dt,dd;
	sx=a[x]+(l-b[x].l)*((a[x+1]-a[x])/dis(a[x+1],a[x]));
	sy=a[y]+(l-c[y].l)*((a[y+1]-a[y])/dis(a[y+1],a[y]));
	ds=sx-sy;
	tx=a[x]+(r-b[x].l)*((a[x+1]-a[x])/dis(a[x+1],a[x]));
	ty=a[y]+(r-c[y].l)*((a[y+1]-a[y])/dis(a[y+1],a[y]));
	dt=tx-ty;
//	printf("sx=(%.3lf , %.3lf )\n",sx.x,sx.y);
//	printf("sy=( %.3lf ,%.3lf )\n",sy.x,sy.y);
//	printf("tx=(%.3lf , %.3lf )\n",tx.x,tx.y);
//	printf("ty=( %.3lf ,%.3lf )\n",ty.x,ty.y);
//	printf("ds=(%.3lf , %.3lf )\n",ds.x,ds.y);
//	printf("dt=( %.3lf ,%.3lf )\n",dt.x,dt.y);
	dd=((a[x+1]-a[x])/dis(a[x+1],a[x]))-((a[y+1]-a[y])/dis(a[y+1],a[y]));
	pan(ds,dt,dd,thi,l,r);
}
bool cmp(node2 a,node2 b){ return (a.x<b.x); }
int check(long double thi){
	int i,j,sum;
	b[0].r=-eps;
	for (i=1;i<=n;i++){
		b[i].l=b[i-1].r+eps*2;
		b[i].r=b[i-1].r+dis(a[i+1],a[i]);
		b[i].x=i;
		c[i].l=b[i].l+tot;
		c[i].r=b[i].r+tot;
		c[i].x=i;
//		printf("%.3lf,%.3lf %d\n",b[i].l,b[i].r,i);
	}
//	printf("yes1 %.3lf\n\n",ans);
	i=1; j=1; th=0; tot1=eps; tot2=tot-eps;
	while (b[i].r<tot) i++;
	while (i<=n){
		if (j==(n/2)+1) break;
//		printf("%.3lf %.3lf %d %d %.3lf\n",max(b[i].l,c[j].l),min(b[i].r,c[j].r),i,j,thi);
//		printf("ke3=%d\n",th);
		work(max(b[i].l,c[j].l),min(b[i].r,c[j].r),i,j,thi);
		if (b[i].r-c[j].r<eps) i++; else j++;
	}
//	printf("yes2 %d %d\n",m,th);
	sort(dd+1,dd+th+1,cmp); sum=0;
	for (i=1;i<=th;i++){
//		printf("%.10lf %d\n",dd[i].x,dd[i].w);
		sum=sum+dd[i].w;
		if (sum>=m) return 1;
	}
//	printf("no %d\n",m);
	return 0;
}
int main(){
//	freopen("n.in","r",stdin);
//	freopen("n.out","w",stdout);
	n=read(); m=read();
	for (i=1;i<=n;i++){
		a[i].x=read(); a[i].y=read();
	}
	for (i=n+1;i<=2*n;i++){
		a[i]=a[i-n];
	}
	a[2*n+1]=a[1];
	for (i=1;i<=n;i++) tot=tot+dis(a[i],a[i+1]);
	tot=tot/m; n=n*2;
	l=0; r=4000; ans=1e9;
	
	while (r-l>=0.0000005){
		mid=(l+r)/2.0;
		if (check(mid)==1){
			ans=mid; r=mid;
		}
		else l=mid;
	}
	printf("%.8Lf\n",ans);
	return 0;
}
/*
4 2
0 0
0 1
1 1
1 0

2 2
0 0
1 0

4 3
0 0
10000 0
0 1
10000 1

4 2333
-776 -597
-776 308
-164 308
-164 -597

10 3
17 5
7 5
7 -4
-18 -4
-18 -10
-4 -10
-4 -5
-2 -5
-2 16
17 16
*/