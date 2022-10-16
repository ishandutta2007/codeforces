#include<bits/stdc++.h>
#define MAX   111
const char ali[]="Alice";
const char bob[]="Bob";
int a[MAX];
int n;
int gcd(int a,int b) {
	while (true) {
		if (a==0) return (b);
		if (b==0) return (a);
		if (a%b==0) return (b);
		if (b%a==0) return (a);
		if (a>b) a=a%b; else b=b%a;		
	}
}
void init(void) {
	scanf("%d",&n);
	int i;
	for (i=1;i<=n;i=i+1) scanf("%d",&a[i]);
	int d=a[1];
	int m=a[1];
	for (i=2;i<=n;i=i+1) {
		if (m<a[i]) m=a[i];
		d=gcd(d,a[i]);
	}
	if ((m/d-n)%2==0) printf("%s",bob);
	else printf("%s",ali);
}
int main(void) {
	init();
	return 0;
}