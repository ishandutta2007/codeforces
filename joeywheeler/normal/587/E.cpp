#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct gs {
	int l[65];
	int ls;

	gs() {
		ls = 0;
	}

	void gauss() {
		int r = 0;
		for (int i = 31; i >= 0 && r < ls; i--) {
			FO(j,r,ls) if (l[j] & (1<<i)) swap(l[j],l[r]);
			if (!(l[r] & (1<<i))) continue;
			FO(j,r+1,ls) if (l[j] & (1<<i)) l[j] ^= l[r];
			r++;
		}
		ls = r;
	}

	void addnum(int x) {
		l[ls++] = x;
		gauss();
	}

	long long cnt() {
		return 1ll<<ls;
	}
};

void merge(gs &a, const gs &b) {
	FO(i,0,b.ls) a.l[a.ls++] = b.l[i];
	a.gauss();
}

void axor(gs &a, int k) {
	FO(i,0,a.ls) if (a.l[i]&1) a.l[i] ^= k<<1;
	a.gauss();
}

#define N 200005

gs rt[4*N];
int d[4*N];

gs q(int i, int rs, int re, int qs, int qe) {
	if (rs == qs && re == qe) {
		return rt[i];
	} else {
		int md = (rs+re)/2;
		gs res; res.ls = 0;
		if (qs<md) merge(res, q(2*i+1, rs, md, qs, min(qe,md)));
		if (qe>md) merge(res, q(2*i+2, md, re, max(qs,md), qe));
		axor(res, d[i]);
		return res;
	}
}

int initv[N];

void u2(int i, int rs, int re) {
	if (rs+1 == re) {
		rt[i].addnum(initv[rs]*2+1);
	} else {
		int md = (rs+re)/2;
		u2(2*i+1, rs, md);
		u2(2*i+2, md, re);
		rt[i] = rt[2*i+1];
		merge(rt[i],rt[2*i+2]);
	}
}

void u(int i, int rs, int re, int qs, int qe, int dv) {
	if (rs == qs && re == qe) {
		axor(rt[i], dv);
		d[i] ^= dv;
	} else {
		int md = (rs+re)/2;
		if (qs<md) u(2*i+1, rs, md, qs, min(qe,md), dv);
		if (qe>md) u(2*i+2, md, re, max(qs,md), qe, dv);
		rt[i] = rt[2*i+1];
		merge(rt[i],rt[2*i+2]);
		axor(rt[i],d[i]);
	}
}

int n, Q;

int main() {
	scanf("%d%d", &n, &Q);
	FO(i,0,n) {
		int v; scanf("%d", &v);
		initv[i] = v;
	}
	u2(0,0,n);
	FO(z,0,Q) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int l, r, k; scanf("%d%d%d", &l, &r, &k);
			l--;
			u(0,0,n,l,r,k);
		} else {
			int l, r; scanf("%d%d", &l, &r); l--;
			gs g = q(0,0,n,l,r);
			FO(i,0,g.ls) g.l[i] /= 2;
			g.gauss();
			printf("%lld\n", g.cnt());
		}
	}
}