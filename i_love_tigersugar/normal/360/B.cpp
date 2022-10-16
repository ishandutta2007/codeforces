#include<cstdio>
#define MAX   2020
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
int a[MAX];
int f[MAX];
int n,k;
int abs(const int &x) {
	if (x<0) return (-x); else return (x);
}
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	FOR(i,1,n) scanf("%d",&a[i]);	
}
bool ok(const int &x) {
	FOR(i,1,n) {
		f[i]=i-1;
		FOR(j,1,i-1)
			if (1LL*abs(a[i]-a[j])<=1LL*x*(i-j)) minimize(f[i],f[j]+i-j-1);
	}
	FOR(i,1,n) if (f[i]+n-i<=k) return (true);
	return (false);
}
void process(void) {
	int l,m,r;
	l=0;
	r=(int)2e9+7;	
	while (true) {
		if (l==r) {
			printf("%d",l);
			return;
		}
		if (r-l==1) {
			if (ok(l)) printf("%d",l);
			else printf("%d",r);
			return;
		}
		m=(int)((0LL+l+r)/2);
		if (ok(m)) r=m;
		else l=m+1;
	}
}
int main(void) {
	init();
	process();
	return 0;
}