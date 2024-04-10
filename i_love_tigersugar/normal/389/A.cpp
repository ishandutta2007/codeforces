#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int gcd(int a,int b) {
	while (true) {
		if (a==0) return (b);
		if (b==0) return (a);
		if (a>b) a=a%b; else b=b%a;
	}
}
int main(void) {
	int n;
	int d;
	scanf("%d",&n);
	scanf("%d",&d);
	REP(i,n-1) {
		int v;
		scanf("%d",&v);
		d=gcd(d,v);
	}
	printf("%d",d*n);
	return 0;
}