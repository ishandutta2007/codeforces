#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n;
struct point{
	int x,y;
}p[100005];
int cmpy(const point&a,const point&b){
	return a.y<b.y;
}
int x[100005],y[100005],xn,yn;
int xx[100005],yy[100005];
int a[9];

struct node{
	int v,l,r;
}t[2000005];int ndtot=0;
int head[100005]={0};
int I;
int add(int x,int l,int r){
	int y=++ndtot;
	t[y]=t[x];
	t[y].v++;
	if(l!=r){
		int mid=l+r>>1;
		if(I<=mid)t[y].l=add(t[x].l,l,mid);
		else t[y].r=add(t[y].r,mid+1,r);
	}
	return y;
}
int l1,r1;
int que(int x,int l,int r){
	if(!x||l>r)return 0;
	if(l1<=l && r<=r1)return t[x].v;
	int mid=l+r>>1;
	int ret=0;
	if(l1<=mid)ret+=que(t[x].l,l,mid);
	if(r1>mid)ret+=que(t[x].r,mid+1,r);
	return ret;
}
int q(int x,int y){
	l1=1,r1=x;
	return que(head[y],1,xn);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y),x[i]=p[i].x,y[i]=p[i].y;
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	xn=unique(x+1,x+1+n)-x-1;
	yn=unique(y+1,y+1+n)-y-1;
	for (int i=1;i<=n;i++)xx[i]=p[i].x=lower_bound(x+1,x+1+xn,p[i].x)-x,yy[i]=p[i].y=lower_bound(y+1,y+1+yn,p[i].y)-y;
	sort(xx+1,xx+1+n);sort(yy+1,yy+1+n);
	for (int i=0;i<9;i++)scanf("%d",&a[i]);sort(a,a+9);
	int su=0;for (int i=0;i<9;i++)su+=a[i];
	if(su!=n){
		printf("-1\n");
		return 0;
	}
	sort(p+1,p+1+n,cmpy);
	for (int i=1;i<=n;i++)I=p[i].x,head[p[i].y]=add(head[p[i-1].y],1,xn);
	do{
		int sl=a[0]+a[3]+a[6],sll=n-a[2]-a[5]-a[8];
		int sd=a[6]+a[7]+a[8],sdd=n-a[0]-a[1]-a[2];
		if(sl!=n && xx[sl]==xx[sl+1])continue;
		if(sll!=n && xx[sll]==xx[sll+1])continue;
		if(sd!=n && yy[sd]==yy[sd+1])continue;
		if(sdd!=n && yy[sdd]==yy[sdd+1])continue;
		int x1=xx[sl],x2=xx[sll],y1=yy[sd],y2=yy[sdd];
		if(q(x1,y1)!=a[6])continue;
		if(q(x1,y2)!=a[6]+a[3])continue;
		if(q(x2,y1)!=a[6]+a[7])continue;
		if(q(x2,y2)!=a[6]+a[3]+a[7]+a[4])continue;
		/*if(q(xn,y1)!=a[6]+a[7]+a[8])continue;
		if(q(xn,y2)!=a[6]+a[7]+a[8]+a[3]+a[4]+a[5])continue;
		if(q(x1,yn)!=a[6]+a[3]+a[0])continue;
		if(q(x2,yn)!=a[6]+a[3]+a[0]+a[7]+a[4]+a[1])continue;*/
		printf("%.1lf %.1lf\n%.1lf %.1lf\n",x[x1]+0.5,x[x2]+0.5,y[y1]+0.5,y[y2]+0.5);
		return 0;
	}while(next_permutation(a,a+9));
	printf("-1\n");
	return 0;
}