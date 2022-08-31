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

int get(int l, int n, int *def, int *nex) {
	if (l >= n || !~def[l]) {
		return l;
	}
	int m = get(nex[l], n, def, nex);
	nex[l] = m;
	return m;
}
int main() {
	int n, m;
	sf("%d%d", &n, &m);
	int *def = alok(n, int);
	int *nex = alok(n, int);
	fr(i,n) def[i] = -1;
	fr(i,n) nex[i] = i+1;
	fr(i,m) {
		int l, r, x;
		sf("%d%d%d", &l, &r, &x);
		//* */pf("[%d %d %d]\n", l, r, x);
		l--; x--;
		l = get(l, n, def, nex);
		r = get(r, n, def, nex);
		while (l < x) {
			def[l] = x;
			int y = get(nex[l], n, def, nex);
			nex[l] = x;
			l = y;
		}
		{
			int t = get(nex[x], n, def, nex);
			nex[x] = r;
			l = t;
		}
		while (l < r) {
			def[l] = x;
			int y = get(nex[l], n, def, nex);
			nex[l] = r;
			l = y;
		}
		/*
		fr(ii,n) {
			if (ii) pf(" ");
			pf("%d", def[ii] + 1);
		}
		pln;
		//*/
	}
	fr(i,n) {
		if (i) pf(" ");
		pf("%d", def[i] + 1);
	}
	pln;
	//pf("it=%d\n", it);
}