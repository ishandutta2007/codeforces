#include<bits/stdc++.h>
struct point {
	int x,y;
	point(){}
	point(const int &_x,const int &_y) {
		x=_x;y=_y;
	}
	void input(void) {
		scanf("%d",&x);
		scanf("%d",&y);
	}
	bool operator == (const point &a) const {
		return (x==a.x && y==a.y);
	}	
};
struct seg {
	point a,b;
	seg(){}
	seg(const point &_a,const point &_b) {
		a=_a;b=_b;
	}
	bool operator == (const seg &x) const {
		if (a==x.a && b==x.b) return (true);
		if (a==x.b && b==x.a) return (true);
		return (false);
	}
	bool parallel(void) const {
		if (a.x==b.x) return (true);
		if (a.y==b.y) return (true);
		return (false);
	}	
};
point a[30];
seg b[30];
int vx[30];
int vy[30];
int np,nx,ny;
void answer_no(void) {
	printf("NO");
	exit(0);
}
void answer_yes(void) {
	printf("YES");
	exit(0);
}
void add_point(const point &p) {
	int j;
	for (j=1;j<=np;j=j+1)
		if (a[j]==p) return;
	np++;
	a[np]=p;
}
void addval(int v[],int &n,const int &t) {
	int i;
	for (i=1;i<=n;i=i+1)
		if (v[i]==t) return;
	n++;
	v[n]=t;
}
bool find_seg(const seg &s) {
	if (!s.parallel()) return (true);
	int i;
	for (i=1;i<=4;i=i+1)
		if (b[i]==s) return (true);
	return (false);
}
void process(void) {
	np=0;
	nx=0;
	ny=0;
	int i,j;
	bool t;
	point m,n;
	for (i=1;i<=4;i=i+1) {
		m.input();
		n.input();
		b[i]=seg(m,n);				
		if (m==n) answer_no();	
		if (!b[i].parallel()) answer_no();
		add_point(m);
		add_point(n);
		addval(vx,nx,m.x);
		addval(vy,ny,m.y);
		addval(vx,nx,n.x);
		addval(vy,ny,n.y);
	}
	if (np!=4) answer_no();
	if (nx!=2) answer_no();
	if (ny!=2) answer_no();
	t=true;
	for (i=1;i<=np;i=i+1)
		for (j=i+1;j<=np;j=j+1)
			if (!find_seg(seg(a[i],a[j]))) answer_no();
	answer_yes();
}
int main(void) {
	process();
	return 0;
}