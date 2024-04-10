#include<cstdio>
#define MAX   3030
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int a[MAX],b[MAX],n,m;
int main(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,m) scanf("%d",&b[i]);
	int id=1;
	int res=0;
	FOR(i,1,n) {
		while (id<=m && a[i]>b[id]) id++;
		if (id>m) res++; else id++;
	}
	printf("%d",res);
	return 0;
}