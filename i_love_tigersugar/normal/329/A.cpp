#include<cstdio>
#define MAX   111
char a[MAX][MAX];
int r[MAX];
int c[MAX];
int n;
int max(const int &x,const int &y) {
	if (x>y) return (x); else return  (y);
}
void init(void) {
	scanf("%d",&n);
	int i,j;
	for (i=1;i<=n;i=i+1) {
		r[i]=-1;
		c[i]=-1;
	}
	for (i=1;i<=n;i=i+1) {
		scanf("%s",&a[i][1]);
		for (j=1;j<=n;j=j+1)
			if (a[i][j]=='.') {
				r[i]=max(r[i],j);
				c[j]=max(c[j],i);
			}
	}
}
void check(void) {
	int i;
	bool p=true;
	for (i=1;i<=n;i=i+1)
		if (r[i]<0) {
			p=false;
			break;
		}
	if (p) {		
		for (i=1;i<=n;i=i+1) printf("%d %d\n",i,r[i]);
		return;
	}
	p=true;
	for (i=1;i<=n;i=i+1)
		if (c[i]<0) {
			p=false;
			break;
		}	
	if (p) {	
		for (i=1;i<=n;i=i+1) printf("%d %d\n",c[i],i);
		return;
	}
	printf("-1");
}
int main(void) {
	init();
	check();
	return 0;
}