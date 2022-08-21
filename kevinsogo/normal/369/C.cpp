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


int main() {
	int n;
	sf("%d", &n);
	int *as = alok(n, int);
	int *bs = alok(n, int);
	int *cs = alok(n, int);
	int **adj = alok(n, int*);
	int **adtj = alok(n, int*);
	int *ado = alok(n * 2 + 11, int);
	int *adto = alok(n * 2 + 11, int);
	int *adc = alok(n, int);
	fr(i,n) adc[i] = 0;
	int *qs = alok(n, int);
	int *depth = alok(n, int);
	int *prob = alok(n, int);
	int *vis = alok(n, int);
	int *parent = alok(n, int);
	fr(i,n) {
		depth[i] = -1;
		prob[i] = 0;
		vis[i] = 0;
	}
	int *nqs = alok(n, int);
	int nq = 0;

	fr(i,n-1) {
		int a, b, c;
		sf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		as[i] = a;
		bs[i] = b;
		cs[i] = c;
		adc[a]++;
		adc[b]++;
	}
	int *adt = ado;
	int *adtt = adto;
	fr(i,n) {
		adj[i] = adt;
		adtj[i] = adtt;
		adt += adc[i];
		adtt += adc[i];
		adc[i] = 0;
	}
	fr(i,n-1) {
		int a = as[i], b = bs[i], c = cs[i];
		adj[a][adc[a]] = b;
		adj[b][adc[b]] = a;
		adtj[a][adc[a]++] = c;
		adtj[b][adc[b]++] = c;
	}
	int q = 1;
	*qs = 0;
	*depth = 0;
	//int ct = 0;
	fr(f,q) {
		int i = qs[f];
		fr(nb,adc[i]) {
			int j = adj[i][nb];
			int t = adtj[i][nb];
			if (!~depth[j]) {
				parent[j] = i;
				depth[j] = depth[i] + 1;
				if (t == 2) prob[j] = 1, nqs[nq++] = j;//, ct++;
				qs[q++] = j;

			}
		}
	}
	vis[0] = 1;
	int ct = 0;
	int *ans = alok(n, int);
	ffr(f,nq) {
		int i = nqs[f];
		//pf("i = %d\n", i);
		if (!vis[i]) {
			vis[i] = 1;
			prob[i] = 0;
			ans[ct++] = i;
			i = parent[i];
			while (!vis[i]) {
				vis[i] = 1;
				//pf("hoy %d\n", i);
				if (prob[i]) {
					//ct--;
					prob[i] = 0;
				}
				i = parent[i];
			}
		}
	}
	pf("%d\n", ct);
	fr(i,ct) {
		if (i) pf(" ");
		pf("%d", ans[i]+1);
	}
	pln;
}