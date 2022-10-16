#include<bits/stdc++.h>
#define MAX   500500
using namespace std;
struct lady {
	int x,y,z;
	lady(){}
	lady(const int &_x,const int &_y,const int &_z) {
		x=_x;y=_y;z=_z;
	}
	bool operator < (const lady &a) const {
		if (x>a.x) return (true);
		if (x<a.x) return (false);
		if (y>a.y) return (true);
		if (y<a.y) return (false);
		return (z>a.z);
	}
};
lady a[MAX];
int v[MAX];
int t[MAX<<2];
int n;
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
void init(void) {
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1) scanf("%d",&a[i].x);
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&a[i].y);
		v[i]=a[i].y;
	}
	for (i=1;i<=n;i=i+1) scanf("%d",&a[i].z);
	sort(&a[1],&a[n+1]);
	sort(&v[1],&v[n+1]);
	for (i=1;i<=n;i=i+1)
		a[i].y=lower_bound(&v[1],&v[n+1],a[i].y)-&v[0];	
	memset(t,-1,sizeof t);
}
void update(const int &u,const int &val) {
	int i,l,m,r;
	i=1;
	l=1;
	r=n;
	while (true) {
		t[i]=max(t[i],val);
		if (l==r) return;
		m=(l+r)/2;
		if (u>m) {
			l=m+1;
			i=2*i+1;
		}
		else {
			r=m;
			i=2*i;
		}
	}
}
int maxval(int i,int l,int r,int u,int v) {
	if (l>v) return (-1);
	if (r<u) return (-1);
	if (l>r) return (-1);
	if (v<u) return (-1);
	if (u<=l && r<=v) return (t[i]);
	int m=(l+r)/2;
	int left=maxval(2*i,l,m,u,v);
	int right=maxval(2*i+1,m+1,r,u,v);
	return (max(left,right));
}
void process(void) {
	int i,j,k;
	int res=0;
	j=1;
	for (i=1;i<=n;i=i+1) {
		if (a[i].x<a[j].x) {
			for (k=j;k<i;k=k+1) update(a[k].y,a[k].z);
			j=i;
		}
		if (maxval(1,1,n,a[i].y+1,n)>a[i].z) res++;
	}
	printf("%d",res);
}
int main(void) {
	init();
	process();
	return 0;
}