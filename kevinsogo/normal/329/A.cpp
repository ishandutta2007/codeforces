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


int main() {
	int n;
	sf("%d", &n);
	int **g = alok(n, int*);
	char *line = alok(11111, char);
	int **gud = alok(n, int*);
	fr(i,n) {
		g[i] = alok(n, int);
		gud[i] = alok(n, int);
		fr(j,n) gud[i][j] = 0;
		sf("%s", line);
		fr(j,n) {
			g[i][j] = line[j];
		}
	}
	int gudh = 0;
	fr(i,n) {
		int found = 0;
		fr(j,n) {
			if (g[i][j] == '.') {
				found = 1;
				break;
			}
		}
		if (found) {
			fr(j,n) gud[i][j] = 1;
			gudh++;
		}
	}
	int gudv = 0;
	fr(j,n) {
		int found = 0;
		fr(i,n) {
			if (g[i][j] == '.') {
				found = 1;
				break;
			}
		}
		if (found) {
			fr(i,n) gud[i][j] = 1;
			gudv++;
		}
	}
	int guda = 1;
	fr(i,n) {
		fr(j,n) {
			if (!gud[i][j]) {
				guda = 0;
				break;
			}
		}
		if (!guda) break;
	}
	if (guda) {
		if (gudh == n) {
			fr(i,n) {
				fr(j,n) {
					if (g[i][j] == '.') {
						pf("%d %d\n", i + 1, j + 1);
						break;
					}
				}
			}
		} else {
			fr(j,n) {
				fr(i,n) {
					if (g[i][j] == '.') {
						pf("%d %d\n", i + 1, j + 1);
						break;
					}
				}
			}
		}
	} else {
		pf("-1\n");
	}
}