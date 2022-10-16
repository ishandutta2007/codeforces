#include<bits/stdc++.h>
int c[10];
int n,t,x,y,z;
int main(void) {
	scanf("%d",&n);
	memset(c,0,sizeof c);
	int i;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&t);
		if (t==5 || t>6) {
			printf("-1");
			return 0;
		}
		c[t]++;		
	}
	x=c[4];
	z=c[3];
	y=c[1]-x-z;
	if (y<0) {
		printf("-1");
		return 0;
	}
	if ((x+y)!=c[2]) {
		printf("-1");
		return 0;
	}
	if ((y+z)!=c[6]) {
		printf("-1");
		return 0;
	}
	for (i=1;i<=x;i=i+1) printf("1 2 4\n");
	for (i=1;i<=y;i=i+1) printf("1 2 6\n");
	for (i=1;i<=z;i=i+1) printf("1 3 6\n");
	return 0;
}