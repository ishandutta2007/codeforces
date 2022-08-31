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

int n, m;
char nxt[256];
int **l;
char **c;
int **r;
int di[4] = {0, 1, 0, -1};
int dj[4] = {-1, 0, 1, 0};
int len(int i, int j) {
	if (r[i][j]) {
		pf("Poor Inna!\n");
		return -111;
	}
	r[i][j] = 1;
	if (!l[i][j]) {
		int bs = 1;
		fr(d,4) {
			int ni = i + di[d];
			int nj = j + dj[d];
			if (0 <= ni && ni < n && 0 <= nj && nj < m) {
				if (nxt[c[i][j]] == c[ni][nj]) {
					int ln = len(ni, nj) + 1;
					if (ln < 0) return -111;
					if (bs < ln) bs = ln;
				}
			}
		}
		l[i][j] = bs;
	}
	r[i][j] = 0;
	return l[i][j];
}
int main() {
	sf("%d%d", &n, &m);
	c = alok(n, char*);
	fr(i,n) {
		c[i] = alok(m + 111, char);
		sf("%s", c[i]);
	}
	r = alok(n, int*);
	l = alok(n, int*);
	fr(i,n) {
		r[i] = alok(m, int);
		l[i] = alok(m, int);
		fr(j,m) {
			r[i][j] = 0;
			l[i][j] = 0;
		}
	}
	nxt['D'] = 'I';
	nxt['I'] = 'M';
	nxt['M'] = 'A';
	nxt['A'] = 'D';
	int ans = 0;
	fr(i,n) {
		fr(j,m) {
			if (c[i][j] == 'D') {
				int nans = len(i, j);
				if (nans < 0) return 0;
				if (ans < nans) ans = nans;
			}
		}
	}
	ans >>= 2;
	if (ans) {
		pf("%d\n", ans);
	} else {
		pf("Poor Dima!\n");
	}

}