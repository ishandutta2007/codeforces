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
	int n, k;
	sf("%d%d", &n, &k);
	ll *a = alok(n, ll);
	ll *s = alok(n+1, ll);
	*s = 0;
	fr(i,n) {
		sf("%I64d", a + i);
		s[i + 1] = s[i] + a[i];
	}
	ll **b = alok(3, ll*);
	int **bi = alok(3, int*);
	fr(i,3) b[i] = alok(n+1, ll);
	fr(i,3) bi[i] = alok(n+1, int);
	fe(N,0,n) {
		fr(x,3) {
			if (!x || !N) {
				b[x][N] = 0;
				bi[x][N] = n+1;
			} else {
				b[x][N] = b[x][N-1];
				bi[x][N] = bi[x][N-1];
				if (N >= k) {
					ll S = b[x-1][N-k] + s[N] - s[N-k];
					if (b[x][N] < S || b[x][N] == S && bi[x][N] > N-k) {
						b[x][N] = S;
						bi[x][N] = N-k;
					}
				}
			}
		}
	}
	int i = bi[2][n];
	int j = bi[1][i];
	pf("%d %d\n", j+1, i+1);
}