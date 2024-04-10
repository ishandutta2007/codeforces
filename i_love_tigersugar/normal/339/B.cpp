#include<bits/stdc++.h>
#define MAX   100100
int a[MAX];
int m,n;
int dur(const int &x,const int &y) {	
	if (y>=x) return (y-x);
	else return (n+y-x);
}
void process(void) {	
	int i;
	long long s=0LL;
	scanf("%d",&n);
	scanf("%d",&m);		
	for (i=1;i<=m;i=i+1) scanf("%d",&a[i]);			
	s+=dur(1,a[1]);	
	for (i=2;i<=m;i=i+1) {
		s+=dur(a[i-1],a[i]);	
	}		
	printf("%I64d",s);
}
int main(void) {
	process();
	return 0;
}