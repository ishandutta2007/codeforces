#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int a[MAX][MAX];
int n,q,s;
void process(void) {
	scanf("%d",&n);
	FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
	FOR(i,1,n) s^=a[i][i];
	scanf("%d",&q);
	REP(zz,q) {
		int t,u;
		scanf("%d",&t);
		if (t<3) {
			scanf("%d",&u);
			s^=1;
		}
		else printf("%d",s);
	}
}
int main(void) {
	process();
	return 0;
}