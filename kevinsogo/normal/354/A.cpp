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


int main() {
	int n, l, r, ql, qr;
	sf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
	ll *w = alok(n, ll);
	fr(i,n) sf("%I64d", w + i);
	ll *wl = alok(n+1, ll);
	ll *wr = alok(n+1, ll);
	wl[0] = wr[n] = 0;
	fr(i,n) wl[i+1] = wl[i] + w[i];
	ffr(i,n) wr[i] = wr[i+1] + w[i];
	ll best = 111111111111111111ll;
	fe(i,0,n) {
		int lm = i, rm = n - i;
		ll cost = wl[i] * l + wr[i] * r;
		#define fuu(lm,ql,rm,qr) do {\
			int ex = lm - rm - 1;\
			if (ex > 0) {\
				cost += ql * ex;\
			}\
		} while (0)
		if (lm > rm) fuu(lm,ql,rm,qr); else fuu(rm,qr,lm,ql);
		if (best > cost) best = cost;
	}
	pf("%I64d\n", best);
}