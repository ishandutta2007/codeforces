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


struct pt {
	int x, y;
};

pt *ps;
int *qs = alok(311111, int);
int xxcomp(pt& a, pt& b) {
	if (a.x != b.x) return a.x - b.x;
	return a.y - b.y;
}
int xcomp(const void *aa, const void *bb) {
	return xxcomp(ps[*(int*)aa], ps[*(int*)bb]);
}
int yycomp(pt& a, pt& b) {
	if (a.y != b.y) return a.y - b.y;
	return a.x - b.x;
}
int ycomp(const void *aa, const void *bb) {
	return yycomp(ps[*(int*)aa], ps[*(int*)bb]);
}
int main() {
	int n, m;
	sf("%d%d", &n, &m);
	ps = alok(n, pt);
	int *psx = alok(n, int);
	int *psy = alok(n, int);
	fr(i,n) {
		int x, y;
		sf("%d%d", &x, &y);
		ps[i].x = x;
		ps[i].y = y;
		psx[i] = psy[i] = i;
	}
	qsort(psx, n, sizeof(int), xcomp);
	qsort(psy, n, sizeof(int), ycomp);

	#define N 1001111
	int ht = 1;
	for (int sz = N, nsz = sz + 1 >> 1; sz > 1; ht++, sz = nsz, nsz = sz + 1 >> 1);
	
	int ***arrs = alok(ht, int**);
	int **arrc = alok(ht, int*);
	arrs[0] = alok(N, int*);
	arrc[0] = alok(N, int);
	fr(i,N) arrc[0][i] = 0;
	fr(i,n) {
		arrc[0][ps[i].x]++;
	}
	fr(i,N) {
		arrs[0][i] = alok(arrc[0][i], int);
		arrc[0][i] = 0;
	}
	fr(i,n) {
		int x = ps[i].x;
		arrs[0][x][arrc[0][x]++] = i;
	}
	fr(i,N) {
		if (arrc[0][i]) {
			qsort(arrs[0][i], arrc[0][i], sizeof(int), ycomp);
		}
	}
	for (int sz = N, nsz = sz + 1 >> 1, h = 1; sz > 1; h++, sz = nsz, nsz = sz + 1 >> 1) {
		arrs[h] = alok(nsz, int*);
		arrc[h] = alok(nsz, int);
		fr(i,nsz) {
			int son1 = i << 1;
			int son2 = son1 + 1;
			if (son2 < sz) {
				int *ars1 = arrs[h - 1][son1];
				int *ars2 = arrs[h - 1][son2];
				int arc1 = arrc[h - 1][son1];
				int arc2 = arrc[h - 1][son2];

				arrs[h][i] = alok(arc1 + arc2, int);
				arrc[h][i] = 0;
				int ison1 = 0, ison2 = 0;
				while (ison1 < arc1 && ison2 < arc2) {
					int comp = yycomp(ps[ars1[ison1]], ps[ars2[ison2]]);
					if (comp <= 0) arrs[h][i][arrc[h][i]++] = ars1[ison1++];
					if (comp >= 0) arrs[h][i][arrc[h][i]++] = ars2[ison2++];
				}
				while (ison1 < arc1) arrs[h][i][arrc[h][i]++] = ars1[ison1++];
				while (ison2 < arc2) arrs[h][i][arrc[h][i]++] = ars2[ison2++];
				//merge
			} else {
				arrc[h][i] = arrc[h - 1][son1];
				arrs[h][i] = arrs[h - 1][son1];
			}
		}
	}

	while (m--) {
		int c;
		sf("%d", &c);
		fr(i,c) sf("%d", qs + i);
		int ans = n;
		int lef = qs[c-1]+1, ryg = qs[0]-1;
		int L, R;
		if (ps[psy[0]].y <= ryg) {
			L = 0, R = n;
			while (R - L > 1) {
				int M = L + R >> 1;
				if (ps[psy[M]].y <= ryg) {
					L = M;
				} else {
					R = M;
				}
			}
			ans -= R;
		}
		if (lef > ps[psx[0]].x) {
			L = 0, R = n;
			while (R - L > 1) {
				int M = L + R >> 1;
				if (lef > ps[psx[M]].x) {
					L = M;
				} else {
					R = M;
				}
			}
			ans -= n - R;
		} else {
			ans -= n;
		}
		fr(ccc,c-1) {
			lef = qs[ccc]+1, ryg = qs[ccc+1]-1;
			if (lef > ryg) continue;

			//fr(i,n) {
				//if (lef <= ps[i].x && ps[i].y <= ryg) ans--;
			//}
			int L = lef, R = N;
			for (int h = 0; L < R; h++, L >>= 1, R >>= 1) {
				if (L & 1) {
					int *ars = arrs[h][L];
					int arc = arrc[h][L];
					if (arc) {
						if (ps[ars[0]].y <= ryg) {
							int l = 0, r = arc;
							while (r - l > 1) {
								int M = l + r >> 1;
								if (ps[ars[M]].y <= ryg) {
									l = M;
								} else {
									r = M;
								}
							}
							ans -= r;
						}
					}
					L++;
				}
				if (R & 1) {
					R--;
					int *ars = arrs[h][R];
					int arc = arrc[h][R];
					if (arc) {
						if (ps[ars[0]].y <= ryg) {
							int l = 0, r = arc;
							while (r - l > 1) {
								int M = l + r >> 1;
								if (ps[ars[M]].y <= ryg) {
									l = M;
								} else {
									r = M;
								}
							}
							ans -= r;
						}
					}
				}
			}
		}
		pf("%d\n", ans);
	}
}