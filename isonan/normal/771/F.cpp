#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
const long double eps=1e-7;
int t,n,q,k,s,op,x[N],y[N],xa[N],ya[N];
struct node{
	long double x,y;
}e[N],f[N];
struct vec{
	long double a,b,c,d;
}w[N],g[N],h[N];
struct vat{
	int x,y;
}gt[N];
inline int read(){
	int num=0; char t='+',g=getchar(); while(g<48||57<g) t=g,g=getchar();
	while(47<g&&g<58) num=num*10+g-48,g=getchar(); if(t=='-') return -num; return num;
}
inline bool cmp(node a,node b){
	return atan2(a.y,a.x)<atan2(b.y,b.x);
}
inline bool dmp(node a,node b){
	return atan2(a.y,a.x)>atan2(b.y,b.x);
}
inline bool tmp(vec a,vec b){
	return atan2(a.d-a.b,a.c-a.a)<atan2(b.d-b.b,b.c-b.a);
}
inline bool qmp(vat a,vat b){
	if(a.x==b.x) return a.y<b.y; return a.x<b.x;
}
inline long double getvac(node a,node b){
	return a.x*b.y-a.y*b.x;
}
inline void adds(node a,node b){
	swap(a,b);
	q++,w[q].a=a.x+x[1],w[q].b=a.y+y[1],w[q].c=b.x+x[1],w[q].d=b.y+y[1];
}
inline bool eps_check(long double u){
	if(-eps<=u&&u<=eps) return 1; return 0;
}
inline bool node_check(vec u,long double x,long double y){
	node a,b;
	a.x=u.c-u.a,a.y=u.d-u.b,b.x=x-u.a,b.y=y-u.b;
	return (getvac(a,b)>=-eps);
}
inline node getnode(vec a,vec b){
	node z;
	long double f1=(a.d-a.b)*(b.c-b.a),f2=(b.d-b.b)*(a.c-a.a),f3=(a.b-b.b)*(b.c-b.a)*(a.c-a.a);
	f3=f3-f1*a.a+f2*b.a;
	z.x=f3/(f2-f1);
	if(eps_check(a.a-a.c)) swap(a,b);
	z.y=(z.x-a.a)*(a.d-a.b)/(a.c-a.a)+a.b;
	return z;
}
inline bool check(vec a,vec b,vec c){
	node z=getnode(b,c);
	return node_check(a,z.x,z.y);
}
inline bool getvat(node a,node b){
	a.x-=b.x,a.y-=b.y,b.x=-b.x,b.y=-b.y;
	return (getvac(a,b)<=eps);
}
inline bool getvas(node a,node b){
	a.x-=b.x,a.y-=b.y,b.x=-b.x,b.y=-b.y;
	return (getvac(a,b)<=-eps);
}
inline int gcd(int a,int b){
	if(!b) return a; return gcd(b,a%b);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.ans","w",stdout);
	t=read(); bool og=0;
	while(t--){
		n=read(),q=0,k=0,op=0; bool fl=0;
		for(int i=1;i<=n;i++) xa[i]=x[i]=read(),ya[i]=y[i]=read();
		for(int i=2;i<=n;i++) x[i]=x[i]-x[1],y[i]=y[i]-y[1],e[i-1].x=x[i],e[i-1].y=y[i]; n--;
		for(int i=2;i<=n+1;i++){
			int z=gcd(abs(x[i]),abs(y[i])); x[i]/=z,y[i]/=z;
			if(x[i]<0) x[i]=-x[i],y[i]=-y[i];
			if(x[i]==0) y[i]=1;
			if(y[i]==0) x[i]=1;
			op++,gt[op].x=x[i],gt[op].y=y[i];
		}
		sort(gt+1,gt+op+1,qmp);
		for(int i=2;i<=op;i++) if(gt[i-1].x==gt[i].x&&gt[i-1].y==gt[i].y) fl=1;
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++) e[i+n]=e[i]; int j=1;
		for(int i=1;i<=n;i++){
			j=max(j,i+1);
			while(j<=i+n-2&&getvat(e[i],e[j+1])) j++;
			if(getvat(e[i],e[j])) adds(e[i],e[j]);
			if(getvat(e[i],e[i+1])) adds(e[i],e[i+1]);
		}
		q++,w[q].a=-1000000,w[q].b=1000000,w[q].c=1000000,w[q].d=1000000;
		q++,w[q].a=1000000,w[q].b=1000000,w[q].c=1000000,w[q].d=-1000000;
		q++,w[q].a=1000000,w[q].b=-1000000,w[q].c=-1000000,w[q].d=-1000000;
		q++,w[q].a=-1000000,w[q].b=-1000000,w[q].c=-1000000,w[q].d=1000000;
		sort(w+1,w+q+1,tmp),g[1]=w[1],k=1;
		for(int i=2;i<=q;i++){
			if(eps_check(atan2(w[i].d-w[i].b,w[i].c-w[i].a)-atan2(g[k].d-g[k].b,g[k].c-g[k].a))){
				if(node_check(w[i],g[k].a,g[k].b)) g[k]=w[i];
			}
			else g[++k]=w[i];
		}
		
		int l=1,r=2;
		for(int i=1;i<=2;i++) h[i]=g[i];
		for(int i=3;i<=k;i++){
			if(i==3){
				node a,b;
				a=getnode(h[1],h[2]);
				b=getnode(h[2],h[1]);
			}
			while(r-l>=1&&check(g[i],h[r],h[r-1])) r--;
			while(r-l>=1&&check(g[i],h[l],h[l+1])) l++;
			h[++r]=g[i];
		}
		while(r-l>=2&&check(h[l],h[r],h[r-1])) r--;
		
		if(r-l<=1||fl){
			if(!og) printf("0\n");
		}
		else{
			s=0; long double ans=0;
			for(int i=l;i<r;i++) f[++s]=getnode(h[i],h[i+1]);
			f[++s]=getnode(h[l],h[r]);
			for(int i=2;i<=s;i++) f[i].y-=f[1].y,f[i].x-=f[1].x;
			for(int i=2;i<s;i++) ans=ans+abs(getvac(f[i],f[i+1]))/2;
			printf("%.7Lf\n",ans);
		}
	}
}