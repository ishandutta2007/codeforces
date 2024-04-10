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
	int n, k, l, r, sall, sk;
	sf("%d%d%d%d%d%d", &n, &k, &l, &r, &sall, &sk);
	int ni = 0;
	#define wpf(v) do { pf("%d", (int)v); if (++ni < n) pf(" "); } while (0)
	int rest = n - k;
	fe(i,l,r) {
		ll lw = l * rest + sk;
		ll hg = i * rest + sk;
		if (lw <= sall && sall <= hg) {
			ll lw2 = i * k;
			ll hg2 = r * k;
			if (lw2 <= sk && sk <= hg2) {
				ll sr = sall - sk - l * rest;
				sk -= i * k;
				if (r - i > 0) while (sk >= r - i) {
					wpf(r);
					k--;
					sk -= r - i;
				}
				if (sk > 0) {
					wpf(sk + i);
					k--;
				}
				while (k > 0) {
					wpf(i);
					k--;
				}
				if (i - l > 0) while (sr >= i - l) {
					wpf(i);
					rest--;
					sr -= i - l;
				}
				if (sr > 0) {
					wpf(sr + l);
					rest--;
				}
				while (rest > 0) {
					wpf(l);
					rest--;
				}
				pln;
				break;
			}
		}
	}
}