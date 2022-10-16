#include<stdio.h>	
#include<algorithm>
#define MAX   2020202
using namespace std;
typedef unsigned long long ull;
ull n,p,r;
ull a[MAX];
bool cmp(ull x,ull y) {
	return (x>y);
}
void init(void) {		
	scanf("%I64u",&p);
	n=0;
	ull i,j;
	while ((1<<(2*n))<p) n=n+1;
	for (i=1;i<=p;i=i+1) scanf("%I64u",&a[i]);
	sort(&a[1],&a[p+1],cmp);		
	r=a[1]*(n+1);	
	for (i=1;i<=n;i=i+1)
		for (j=(1<<(2*i-2))+1;j<=1<<(2*i);j=j+1)
			r=r+a[j]*(n+1-i);
	printf("%I64u",r);
}
int main(void) {
	init();
	return 0;
}