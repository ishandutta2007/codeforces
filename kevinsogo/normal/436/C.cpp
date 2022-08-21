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

struct ed{
	int i, j, c;
};

int ecomp(const void *aa, const void *bb) {
	ed a = *(ed*)aa;
	ed b = *(ed*)bb;
	return a.c - b.c;

}

char ***gs;
char *s = alok(111111, char);
int diff[1111][1111];
ed *eds = alok(1111111, ed);
int p[11111];
int find(int n) {
	if (p[n] < 0) return n;
	int pt = find(p[n]);
	p[n] = pt;
	return pt;
}
int wi[11111];
int wj[11111];
int *ado = alok(11111, int);
int **adj = alok(11111, int*);
int *adc = alok(11111, int);
int *typ = alok(11111, int);
int nm;
void rt(int p, int i) {
	fr(nb,adc[i]) {
		int j = adj[i][nb];
		if (j == p) continue;
		if (diff[i][j] == nm) {
			typ[j] = 0;
			pf("%d 0\n", j+1);
		} else {
			pf("%d %d\n", j+1,i+1);
		}
		rt(i,j);
	}
}
int main() {
	int n, m, k, w;
	sf("%d%d%d%d", &n, &m, &k, &w);
	gs = alok(k, char**);
	fr(i,k) {
		gs[i] = alok(n, char*);
		fr(j,n) {
			gs[i][j] = alok(m, char);
		}
	}
	fr(i,k) {
		fr(j,n) {
			sf("%s", s);
			fr(a,m) {
				gs[i][j][a] = s[a];
			}
		}
	}
	 nm = n * m;
	int ans = nm, e = 0;
	fr(i1,k) fr(i2,i1) {
		int df = 0;
		fr(j,n) fr(a,m) {
			if (gs[i1][j][a] != gs[i2][j][a]) df++;
		}
		df *= w;
		if (df > nm) df = nm;
		eds[e].i = i1;
		eds[e].j = i2;
		eds[e].c = df;
		diff[i1][i2] = diff[i2][i1] = df;
		e++;
	}
	qsort(eds, e, sizeof(ed), ecomp);
	fr(i,k) p[i] = -1;
	int cp = k;
	int i = 0;
	int ww = 0;
	fr(i,k) adc[i] = 0;
	while (cp > 1) {
		int a = (eds[i].i);
		int b = (eds[i].j);
		int c = eds[i].c;
		int fa = find(a);
		int fb = find(b);
		if (fa != fb) {
			if (p[fa] == p[fb]) p[fb]--;
			if (p[fa] > p[fb]) {
				p[fa] = fb;
			} else {
				p[fb] = fa;
			}
			cp--;
			ans += c;
			wi[ww] = a;
			wj[ww] = b;
			adc[a]++;
			adc[b]++;
			ww++;
		}
		i++;
	}
	int *adt = ado;
	fr(i,k) {
		adj[i] = adt;
		adt += adc[i];
		adc[i] = 0;
	}
	fr(i,k-1) {
		adj[wi[i]][adc[wi[i]]++] = wj[i];
		adj[wj[i]][adc[wj[i]]++] = wi[i];
	}
	typ[0] = 0;



	pf("%d\n", ans);
	pf("%d %d\n", 1, 0);
	rt(-1,0);
}