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


char g[2111][2111];
char s[11111];
int ans[2111];
int main() {
	int n, m, k;
	sf("%d%d%d", &n, &m, &k);
	fr(i,n) {
		sf("%s", s);
		fr(j,m) {
			g[i][j] = s[j];
		}
	}
	fr(i,m) ans[i] = 0;
	fr(i,n) fr(j,m) {
		if (g[i][j] == 'U') {
			if (i % 2 == 0) {
				ans[j]++;
			}
		} else if (g[i][j] == 'L') {
			int targ = j - i;
			if (targ >= 0) ans[targ]++;
		} else if (g[i][j] == 'R') {
			int targ = j + i;
			if (targ < m) ans[targ]++;
		}
	}
	fr(i,m) {
		if(i ) pf(" ");
		pf("%d", ans[i]);
	}
	pln;
}