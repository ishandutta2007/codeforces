#include<cstdio>
#define MAXN   103
#define MAXV   111111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int a[MAXN];
int b[MAXN];
int n,q,sa,sb;
int f[MAXN][MAXV*2];
void maximize(int &x,const int &y) {
	if (x<y) x=y;
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&q);
	sa=0;
	sb=0;
	FOR(i,1,n) {
		scanf("%d",&a[i]);
		sa+=a[i];
	}
	FOR(i,1,n) {
		scanf("%d",&b[i]);
		b[i]=b[i]*q;
		sb+=b[i];
	}
}
void optimize(void) {
	REP(i,n+1) FOR(j,-sb,sa) f[i][j+MAXV]=-1;
	f[0][MAXV]=0;
	REP(i,n) FOR(j,-sb,sa)
		if (f[i][j+MAXV]>=0) {
			maximize(f[i+1][j+MAXV],f[i][j+MAXV]);
			maximize(f[i+1][j+a[i+1]-b[i+1]+MAXV],f[i][j+MAXV]+a[i+1]);
		}
	/*REP(i,n+1) {
		FOR(j,-sb,sa) if (f[i][j+MAXV]>=0) printf("f(%d,%d)=%d\n",i,j,f[i][j+MAXV]);
		printf("\n");
	}*/	
	if (f[n][MAXV]>0) printf("%d",f[n][MAXV]); else printf("-1");
}
int main(void) {
	init();
	optimize();
	return 0;
}