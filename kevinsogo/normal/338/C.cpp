#include<stdio.h>
#include<stdlib.h>
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


ll *v;// = alok(n, ll);
ll **p;// = alok(n, ll*);
int *pc;// = alok(n, int);
int n;
int wolf(int i, int t, int j, ll y, int w, int r);
int best = 11111;
int sons[111][2];
int sonc = 0;
int subok(int i, int t, int w, int r) {
	if (i >= n) {
		/*if (best > t + (r == 1 ? -1 : 0)) {
			best = t + (r == 1 ? -1 : 0);
			printf("%d: %d %d %d %d: \n", i, t, w, r, best);
			fr(ww, sonc) pf("%d %d\n", sons[ww][0], sons[ww][1]); pln;
		}*/
		return t + (r == 1 ? -1 : 0);
	}
	int x = subok(i + 1, t, w, r);
	int y = wolf(i, t, 0, v[i], w, r);
	if (x > y) x = y;
	return x;
}
int wolf(int i, int t, int j, ll y, int w, int r) {
	if (j >= i) {
		return subok(i + 1, t, w, r);
	} else {
		int yy = wolf(i, t, j + 1, y, w, r);
		if (!(w & (1 << j)) && y % v[j] == 0) {
			sons[sonc][0] = i;
			sons[sonc][1] = j;
			sonc++;
			int z = wolf(i, t - pc[j], j + 1, y / v[j], w | (1 << j), r - 1);
			sonc--;
			if (yy > z) yy = z;
		}
		return yy;
	}
}

int comp(const void *aa, const void *bb) {
	ll a = *(ll*)aa;
	ll b = *(ll*)bb;
	return (a > b) - (a < b);
}
int main() {
	sf("%d", &n);
	v = alok(n, ll);
	pc = alok(n, int);
	int t = n + 1;
	fr(i,n) {
		sf("%I64d", v + i);
	}
	qsort(v, n, sizeof(ll), comp);
	fr(i,n) {
		pc[i] = 0;
		ll w = v[i];
		for (ll j = 2; j <= w; j++) {
			if (j > w / j) j = w;
			while (w % j == 0) {
				w /= j;
				pc[i]++;
			}
		}
		//pf("%I64d: %d\n", v[i], pc[i]);
		if (pc[i] > 1) t += pc[i];
	}
	int ans = subok(0, t, 0, n);
	pf("%d\n", ans);
}