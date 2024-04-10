#include<cstdio>
#define MAX   2020
#define LEN   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int a[MAX][MAX];
int l[MAX][13];
int r[MAX][13];
int d[13][13];
int s[LEN];
int m,n,p,q;
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
int abs(const int &x) {
	if (x<0) return (-x); else return (x);
}
void maximize(int &x,const int &y) {
	if (x<y) x=y;
}
void init(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&p);
	scanf("%d",&q);
	FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
	FOR(i,1,q) scanf("%d",&s[i]);
}
void precount(void) {
	FOR(i,1,m) {
		FOR(j,1,n) r[i][a[i][j]]=j;
		FORD(j,n,1) l[i][a[i][j]]=j;
	}
}
int dis(const int &x,const int &y) {	
	int res=-1;
	int tx,ty;
	FOR(i,1,m) FOR(j,1,m) {		
		tx=l[i][x];
		ty=r[j][y];
		if (1<=tx && tx<=n && 1<=ty && ty<=n) maximize(res,abs(tx-ty)+abs(i-j));	
		tx=r[i][x];
		ty=l[j][y];
		if (1<=tx && tx<=n && 1<=ty && ty<=n) maximize(res,abs(tx-ty)+abs(i-j));	
	}
	return (res);
}
void process(void) {
	FOR(i,1,p) FOR(j,i,p) d[i][j]=dis(i,j);
	int res=-1;
	FOR(i,2,q) maximize(res,d[min(s[i],s[i-1])][max(s[i],s[i-1])]);
	printf("%d",res);
}
int main(void) {
	init();
	precount();
	process();	
	return 0;
}