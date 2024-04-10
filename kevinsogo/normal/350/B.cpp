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

int sc;
int *staf;
int *type;
int *deg;
int *pre;

int main() {
	int n;
	sf("%d", &n);
	sc = 0;
	staf = alok(n, int);
	type = alok(n, int);
	deg = alok(n, int);
	pre = alok(n, int);
	fr(i,n) {
		deg[i] = 0;
		pre[i] = -1;
	}
	fr(i,n) {
		sf("%d", type + i);
	}
	fr(i,n) {
		sf("%d", pre + i);
		deg[--pre[i]]++;
	}
	int mx = 0;
	int *mxv = alok(n, int);
	fr(i,n) {
		if (type[i] == 1) {
			int vl = 1;
			for (int j = i; pre[j] >= 0 && deg[pre[j]] == 1; j = pre[j]) vl++;
			mxv[i] = vl;
			if (mx < vl) mx = vl;
		}
	}
	pf("%d\n", mx);
	sc = mx;
	fr(i,n) {
		if (type[i] == 1 && mxv[i] == mx) {
			staf[--sc] = i;
			for (int j = i; pre[j] >= 0 && deg[pre[j]] == 1; j = pre[j]) {
				staf[--sc] = pre[j];
			}
			break;
		}
	}
	pf("%d", staf[0] + 1);
	fo(i,1,mx) {
		pf(" %d", staf[i] + 1);
	}
	pln;
}