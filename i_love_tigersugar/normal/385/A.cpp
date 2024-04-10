#include<cstdio>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int a[MAX];
int n,c;
int main(void) {
	int res=0;
	scanf("%d",&n);
	scanf("%d",&c);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n-1) if (res<a[i]-a[i+1]-c) res=a[i]-a[i+1]-c;
	printf("%d",res);
	return 0;
}