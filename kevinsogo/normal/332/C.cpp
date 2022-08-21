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


ll *as;
ll *bs;
int hcomp(const void *aa, const void *bb) {
	int a = *(int*)aa;
	int b = *(int*)bb;
	if (bs[a] != bs[b]) return (bs[a] > bs[b]) - (bs[a] < bs[b]);
	return (as[a] < as[b]) - (as[a] > as[b]);
}
int jcomp(const void *aa, const void *bb) {
	int a = *(int*)aa;
	int b = *(int*)bb;
	if (bs[a] != bs[b]) return (bs[a] < bs[b]) - (bs[a] > bs[b]);
	return (as[a] < as[b]) - (as[a] > as[b]);
}
int kcomp(const void *aa, const void *bb) {
	int a = *(int*)aa;
	int b = *(int*)bb;
	if (as[a] != as[b]) return (as[a] < as[b]) - (as[a] > as[b]);
	return (bs[a] < bs[b]) - (bs[a] > bs[b]);
}
int main() {
	int n, p, k;
	sf("%d%d%d", &n, &p, &k);
	as = alok(n, ll);
	bs = alok(n, ll);
	int *hs = alok(n, int);
	int *js = alok(n, int);
	int *ks = alok(n, int);
	int *his = alok(n, int);
	int *jis = alok(n, int);
	int *kis = alok(n, int);
	fr(i,n) {
		sf("%I64d%I64d", as + i, bs + i);
		hs[i] = i;
		js[i] = i;
		ks[i] = i;
	}
	qsort(hs, n, sizeof(int), hcomp);
	qsort(js, n, sizeof(int), jcomp);
	qsort(ks, n, sizeof(int), kcomp);
	fr(i,n) his[hs[i]] = i;
	fr(i,n) jis[js[i]] = i;
	fr(i,n) kis[ks[i]] = i;

	p -= k;
	// p on left, k on right

	int **ctl = alok(20, int*);
	ll **sl = alok(20, ll*);
	int **ctr = alok(20, int*);
	ll **sr = alok(20, ll*);
	*ctl = alok(n, int);
	*sl = alok(n, ll);
	*ctr = alok(n, int);
	*sr = alok(n, ll);
	for (int sz = n, nsz = sz + 1 >> 1, h = 1; sz > 1; h++, sz = nsz, nsz = sz + 1 >> 1) {
		ctl[h] = alok(nsz, int);
		sl[h] = alok(nsz, ll);
		ctr[h] = alok(nsz, int);
		sr[h] = alok(nsz, ll);
	}
	#define addar(ar,ixx,ad) do {\
		int ix = ixx;\
		ar[0][ix] += ad;\
		for (int sz = n, nsz = sz + 1 >> 1, h = 1; sz > 1; h++, sz = nsz, nsz = sz + 1 >> 1) {\
			ix >>= 1;\
			ar[h][ix] += ad;\
		}\
	} while (0)
	#define addl(ix) do {\
		int xx = jis[ix];\
		ll ad = bs[ix];\
		addar(ctl,xx,1);\
		addar(sl,xx,ad);\
	} while (0)
	#define addr(ix) do {\
		int xx = kis[ix];\
		ll ad = as[ix];\
		addar(ctr,xx,1);\
		addar(sr,xx,ad);\
	} while (0)
	#define remover(ix) do {\
		int xx = kis[ix];\
		ll ad = as[ix];\
		addar(ctr,xx,-1);\
		addar(sr,xx,-ad);\
	} while (0)
	#define xsum(ar,ix,vl) do {\
		vl = 0;\
		for (int h = 0, xx = ix; xx; h++, xx >>= 1) {\
			if (xx & 1) {\
				vl += ar[h][--xx];\
			}\
		}\
	} while (0)
	#define countl(ix,vl) xsum(ctl,ix,vl)
	#define suml(ix,vl) xsum(sl,ix,vl)
	#define countr(ix,vl) xsum(ctr,ix,vl)
	#define sumr(ix,vl) xsum(sr,ix,vl)

	#define init(spl) do {\
		fr(i,n) {\
			(*ctl)[i] = 0;\
			(*sl)[i] = 0;\
			(*ctr)[i] = 0;\
			(*sr)[i] = 0;\
		}\
		for (int sz = n, nsz = sz + 1 >> 1, h = 1; sz > 1; h++, sz = nsz, nsz = sz + 1 >> 1) {\
			fr(v,nsz) {\
				ctl[h][v] = 0;\
				sl[h][v] = 0;\
				ctr[h][v] = 0;\
				sr[h][v] = 0;\
			}\
		}\
		fr(i,spl) {\
			addl(hs[i]);\
		}\
		fo(i,spl,n) {\
			addr(hs[i]);\
		}\
	} while (0)

	#define value(va, vb) do {\
		int La = p-1, Ra = n;\
		while (Ra - La > 1) {\
			int Ma = La + Ra >> 1;\
			int vl;\
			countl(Ma,vl);\
			if (vl >= p) Ra = Ma; else La = Ma;\
		}\
		suml(Ra,va);\
		int Lb = k-1, Rb = n;\
		while (Rb - Lb > 1) {\
			int Mb = Lb + Rb >> 1;\
			int vl;\
			countr(Mb,vl);\
			if (vl >= k) Rb = Mb; else Lb = Mb;\
		}\
		sumr(Rb,vb);\
	} while (0)

	init(p);
	ll va, vb, nva, nvb;
	value(va, vb);
	int bsp = p;
	fo(i,p,n-k) {
		addl(hs[i]);
		remover(hs[i]);
		value(nva, nvb);
		if (nvb > vb || nvb == vb && nva > va) {
			va = nva;
			vb = nvb;
			bsp = i+1;
		}
	}
	init(bsp);
	int prt = 0;
	#define pert(v) {\
		if (prt) pf(" ");\
		prt = 1;\
		pf("%d", v+1);\
	} while (0)

	fr(i,n) {
		if ((*ctl)[i]) {
			pert(js[i]);
			if (!--p) break;
		}
	}
	fr(i,n) {
		if ((*ctr)[i]) {
			pert(ks[i]);
			if (!--k) break;
		}
	}
	pln;
}