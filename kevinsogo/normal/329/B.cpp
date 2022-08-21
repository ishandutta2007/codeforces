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

#define INF 1111111111
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int main() {
	int r, c;
	sf("%d%d", &r, &c);
	char **g = alok(r, char*);
	int *amt = alok(r*c, int);
	fr(i,r*c) amt[i] = 0;
	int **dst = alok(r, int*);
	int si, sj;
	fr(i,r) {
		g[i] = alok(c+11, char);
		dst[i] = alok(c, int);
		sf("%s", g[i]);
		fr(j,c) {
			if (g[i][j] == 'E') {
				si = i;
				sj = j;
			}
			dst[i][j] = INF;
		}
	}
	g[si][sj] = '0';
	dst[si][sj] = 0;
	int *is = alok(r*c, int);
	int *js = alok(r*c, int);
	int q = 1;
	*is = si;
	*js = sj;
	int targ = 11111111;
	fr(f,q) {
		int i = is[f];
		int j = js[f];
		if (dst[i][j] > targ) break;
		fr(d,4) {
			int ni = i + di[d];
			int nj = j + dj[d];
			if (0 <= ni && ni < r && 0 <= nj && nj < c)
			if (0 <= ni && ni < r && 0 <= nj && nj < c && g[ni][nj] != 'T' && dst[ni][nj] >= INF) {
				dst[ni][nj] = dst[i][j] + 1;
				if (g[ni][nj] == 'S') {
					targ = dst[ni][nj];
				} else {
					amt[dst[ni][nj]] += g[ni][nj] - '0';
				}
				is[q] = ni;
				js[q] = nj;
				q++;
			}
		}
	}
	fq(i,targ) amt[i] += amt[i - 1];
	pf("%d\n", amt[targ]);
}