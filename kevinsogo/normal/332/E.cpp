#include<stdio.h>
#include<stdlib.h>
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
	char *p = alok(1111111, char);
	char *s = alok(211, char);
	char *kt = alok(111, char);
	int k;
	fgets(p, 1111111, stdin);
	fgets(s, 1111111, stdin);
	fgets(kt, 1111111, stdin);
	sscanf(kt, "%d", &k);

	int np = strlen(p);
	int ns = strlen(s);
	p[--np] = 0;
	s[--ns] = 0;
	int sc = k - (np % k);
	int lc = np % k;
	int st = np / k;
	int lt = np / k + 1;
	char *ans1 = alok(11111, char);
	char *ans2 = alok(11111, char);
	char **cols = alok(k, char*);
	fr(i,k) cols[i] = alok(lt+1,char);

	char **pcols = alok(k, char*);
	fr(i,k) pcols[i] = alok(lt+1,char);
	int I = 0, J = 0;
	fr(i,np) {
		pcols[I][J] = p[i];
		if (++I >= k) {
			I = 0;
			J++;
		}
	}
	fr(i,k) {
		pcols[I][J] = 0;
		if (++I >= k) {
			I = 0;
			J++;
		}		
	}
///	fr(i,k) {
///		pf("pcol %d: %s\n", i, pcols[i]);
///	}
	int fd = 0;
	int *inds = alok(k, int);
	ans1[k] = ans2[k] = 0;
	fe(ab,0,k) {
		int a = ns - st * ab;
		if (!(0 <= a && a <= lc)) continue;
		int b = ab - a;
		if (!(0 <= b && b <= sc)) continue;
		I = J = 0;
		fr(i,ns) {
			cols[I][J] = s[i];
			if (++I >= ab) {
				I = 0;
				J++;
			}
		}
		fr(i,ab) {
			cols[I][J] = 0;
			if (++I >= ab) {
				I = 0;
				J++;
			}
		}
///		fr(i,ab) {
///			pf("col %d: %s\n", i, cols[i]);
///		}
		int abi = ab - 1, ki = k - 1;
		while (abi >= 0 && ki >= 0) {
			if (!strcmp(cols[abi], pcols[ki])) inds[abi--] = ki;
			ki--;
		}
		if (abi < 0) {
			// success
			fr(i,k) ans2[i] = '0';
			fr(i,ab) ans2[inds[i]] = '1';
//			pf("key %s\n", ans2);
			if (!fd || strcmp(ans1, ans2) > 0) {
				fd = 1;
				char *tmp = ans2; ans2 = ans1; ans1 = tmp;
			}
		}
	}
	if (fd) {
		pf("%s\n", ans1);
	} else {
		pf("0\n");
	}
}