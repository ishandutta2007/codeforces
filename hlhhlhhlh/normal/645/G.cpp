#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
const double eps=1e-9;
const double pi=acos(-1);
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-')fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int i,j,k;
int n,ll,rr;
double l,r,mid;
int d[maxn];
double ans,w;
struct node{
	double x,y;
	node (double xx=0,double yy=0){
		x=xx; y=yy;
	}
}a[maxn];
node operator - (node a,node b){ return node(a.x-b.x,a.y-b.y); }
node operator / (node a,double b){ return node(a.x/b,a.y/b); }
node operator * (node a,long double b){ return node(a.x*b,a.y*b); }
node operator + (node a,node b){ return node(a.x+b.x,a.y+b.y); }
double cha (node a,node b){ return (a.x*b.y-a.y*b.x); }
double dian (node a,node b){ return (a.x*b.x+a.y*b.y); }
double len(node a){ return sqrt(dian(a,a)); }
node zhuan(node a,double w){
	node b=node(cos(w),sin(w));
	return node(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
struct CC{
	node a;
	double l;
	CC (node aa=node(0,0),double ll=0){
		a=aa; l=ll;
	}
}b[maxn];
struct nodee{
	node a;
	int l;
	double ccc;
	nodee (node aa=node(0,0),int ll=0){
		a=aa; l=ll;
	}
}c[maxn*2];
void work(CC a,CC b,int fla){
	if (a.l<b.l) swap(a,b);
	if (len(a.a-b.a)>a.l+b.l-eps) return;
	if (len(a.a-b.a)+b.l-eps<a.l) return;
	long double t1=(long double)len(a.a-b.a)*(long double)len(a.a-b.a)+(long double)a.l*a.l-(long double)b.l*b.l;
	t1=t1/2/len(a.a-b.a);
	node t=((b.a-a.a)/len(b.a-a.a))*t1+a.a;
	t1=sqrt(a.l*a.l-t1*t1);
	ll++; c[ll].a=t+(zhuan(b.a-a.a,pi/2)/len(b.a-a.a))*t1; c[ll].l=fla;
	ll++; c[ll].a=t+(zhuan(b.a-a.a,-pi/2)/len(b.a-a.a))*t1; c[ll].l=fla;
}
bool cmp(nodee a,nodee b){
	return (a.ccc<b.ccc);
}
int check(double mid){
	int i,j,k; ll=0,rr=0;
	for (i=1;i<=n;i++){
		b[i].a=a[i];
		b[i].l=len(a[i]-node(-w,0));
	}
	for (i=1;i<=n;i++){
		work(b[i],CC(node(w,0),mid),i);
	}
	for (i=1;i<=ll;i++) c[i].ccc=atan2(c[i].a.x-w,c[i].a.y);
	sort(c+1,c+ll+1,cmp);
	for (i=1;i<=ll;i++){
		if (d[rr]!=c[i].l){
			rr++; d[rr]=c[i].l;
		}
		else{
			rr--;
		}
	}
	if (rr==0) return 0;
	else return 1;
}
int main(){
//	freopen("distance.in","r",stdin);
//	freopen("distance.out","w",stdout);
	
	n=read(); w=read(); ans=2*w;
	for (i=1;i<=n;i++){
		a[i].x=read(); a[i].y=read();
		if (a[i].x==0) j++;
	}
	if (j>=2){
		printf("0\n"); return 0;
	}
	l=0; r=2*w;
	while (r-l>=eps){
		mid=(l+r)/2.0;
		if (check(mid)==1){
			ans=mid; r=mid;
		}
		else l=mid;
	}
	printf("%.8lf\n",ans);
	
	return 0;
}
/*
2 5
1 0
2 1
*/