#include<cstdio>
#include<cstring>
#define MAX   111
struct point {
	int x,y;
	point(){}
	void input(void) {
		scanf("%d",&x);
		scanf("%d",&y);
	}	
};
int abs(const int &x) {
	if (x<0) return (-x); else return (x);
}
int dis(const point &a,const point &b) {
	return (abs(a.x-b.x)+abs(a.y-b.y));
}
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
point a[MAX];
int e[MAX];
int c[MAX][MAX];
int n,d;
void init(void) {
	scanf("%d",&n);
	scanf("%d",&d);
	int i,j;	
	for (i=2;i<n;i=i+1) scanf("%d",&e[i]);
	for (i=1;i<=n;i=i+1) a[i].input();
	memset(c,0x3f,sizeof c);
	for (i=1;i<=n;i=i+1)
		for (j=1;j<=n;j=j+1) {
			if (i==j) c[i][j]=0;
			else minimize(c[i][j],d*dis(a[i],a[j])-e[j]);
		}	
}
void floyd(void) {
	int i,j,k;
	for (i=1;i<=n;i=i+1)
		for (j=1;j<=n;j=j+1)
			for (k=1;k<=n;k=k+1)
				minimize(c[j][k],c[j][i]+c[i][k]);
	printf("%d",c[1][n]);
}
int main(void) {
	init();
	floyd();
	return 0;
}