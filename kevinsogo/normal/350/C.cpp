#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")


int *xs;
int *ys;
int *hs;
int hcomp(const void *aa, const void *bb) {
	int a = *(int*)aa;
	int b = *(int*)bb;
	#define ducomp(Xa, Xb) do {\
		int xa = Xa, xb = Xb;\
		if (xa >= 0) {\
			xa <<= 1;\
		} else {\
			xa = -xa;\
			xa <<= 1;\
			xa--;\
		}\
		if (xb >= 0) {\
			xb <<= 1;\
		} else {\
			xb = -xb;\
			xb <<= 1;\
			xb--;\
		}\
		if (xa != xb) return (xa > xb) - (xa < xb);\
	} while (0)
	ducomp(ys[a], ys[b]);
	ducomp(xs[a], xs[b]);
	return 0;

}
int main() {
	int n;
	sf("%d", &n);
	xs = alok(n, int);
	ys = alok(n, int);
	hs = alok(n, int);
	fr(i,n) {
		sf("%d%d", xs + i, ys + i);
		hs[i] = i;
	}
	qsort(hs, n, sizeof(int), hcomp);
	int ops = 0;
	fr(i,n) {
		if (xs[i] == 0 || ys[i] == 0) {
			ops += 4;
		} else {
			ops += 6;
		}
	}
	pf("%d\n", ops);
	fr(i,n) {
		int x = xs[hs[i]], y = ys[hs[i]];
		if (x > 0) pf("1 %d R\n", x);
		if (x < 0) pf("1 %d L\n", -x);
		if (y > 0) pf("1 %d U\n", y);
		if (y < 0) pf("1 %d D\n", -y);
		pf("2\n");
		if (y > 0) pf("1 %d D\n", y);
		if (y < 0) pf("1 %d U\n", -y);
		if (x > 0) pf("1 %d L\n", x);
		if (x < 0) pf("1 %d R\n", -x);
		pf("3\n");
	}
}