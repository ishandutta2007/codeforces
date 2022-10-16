#include<bits/stdc++.h>
#define MAX   100100
int a[MAX];
int f[MAX];
int c[MAX];
int n,sz;
void init(void) {
	scanf("%d",&n);
	int i;
	for (i=1;i<=n;i=i+1) scanf("%d",&a[i]);	
}
void LIS(void) {
	int i,l,m,r;
	sz=1;
	c[sz]=1;
	f[1]=1;
	for (i=2;i<=n;i=i+1) {
		if (a[i]<=a[c[1]]) {
			f[i]=1;
			c[1]=i;
			continue;
		}
		if (a[i]>a[c[sz]]) {
			sz++;
			f[i]=sz;
			c[sz]=i;
			continue;
		}
		l=1;r=sz;
		while (true) {
			if (l==r) {
				m=r;
				break;
			}
			if (r-l==1) {
				if (a[i]>a[c[r]]) m=r;
				else m=l;
				break;				
			}
			m=(l+r)/2;
			if (a[i]>a[c[m]]) l=m;
			else r=m-1;
		}
		f[i]=m+1;
		if (a[i]<=a[c[m+1]]) c[m+1]=i;
	}
	printf("%d",sz);
}
int main(void) {
	init();
	LIS();
	return 0;
}