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


ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int *seq;
int *seq2;
ll md;
ll ggs[21111];
int ans(int off, int len, ll p, int e) {
	if (!e) {
		md = 1;
		*ggs = 0;
		return 1;
	}
	int ct = 0, coff = off;
	while (ct < p && coff < off + len && !seq[coff]) {
		ct++;
		coff++;
	}
	//pf("!"); for (int i = off; i < off + len; i++) pf("%d ", seq[i]); pln;
	//pf("%I64d %d", p,e );
	if (coff >= off + len) {
		md = p;
		int clen = p - len;
		fr(i,clen) ggs[i] = i;
		return clen;
	}
	int doff = coff - off;
	len -= coff - off;
	off = coff;
	int lseq = 0;
	for (int i = off; i < off + len; i += p) {
		seq2[lseq++] = seq[i] - 1;
	}
	int *t = seq; seq = seq2; seq2 = t;
	int ggc = ans(0, lseq, p, e - 1);
	md *= p;
	fr(i,ggc) ggs[i] = ggs[i] * p + p - 1 - doff;
	return ggc;
}
ll x, y;
void egcd(ll a, ll b) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	} else {
		egcd(b, a % b);
		ll t = x - (a / b) * y;
		x = y;
		y = t;
	}
}
ll inv(ll a, ll n) {
	egcd(a, n);
	return x % n;
}
ll mul(ll a, ll b, ll m) {
	if (!b) return 0;
	if (b < 0) return -mul(a, -b, m);
	return ((mul(a, b >> 1, m) << 1) + (b & 1) * a) % m;
}
ll chinese(ll a, ll m, ll b, ll n) {
	ll mn = m * n;
	return (mul(a * n, inv(n, m), mn) + mul(b * m, inv(m, n), mn)) % mn;
}
int valid(int off, int len, ll p, int e) {
	//pf("OOO "); fo(i,off,off+len) pf("%d ", seq[i]); pln;
	if (!e) {
		//pf("hey %d %d\n", off, len);
		fo(i,off,off+len) if (seq[i]) return 0;
		//pf("dud\n");
		return 1;
	}
	int ct = 0, coff = off;
	while (ct < p && coff < off + len && !seq[coff]) {
		ct++;
		coff++;
	}
	//pf("OOO "); fo(i,off,off+len) pf("%d ", seq[i]); pln;
	if (ct >= p) return 0;
	//pf("OOO "); fo(i,off,off+len) pf("%d ", seq[i]); pln;
	if (coff >= off + len) return 1;
	//pf("OOO "); fo(i,off,off+len) pf("%d ", seq[i]); pln;
	len -= coff - off;
	off = coff;
	for (int i = off; i < off + len; i++) {
		if (!seq[i] == !((i - off) % p)) {
			return 0;
		}
	}
	int lseq = 0;
	for (int i = off; i < off + len; i += p) {
		seq2[lseq++] = seq[i] - 1;
	}
	int *t = seq; seq = seq2; seq2 = t;
	return valid(0, lseq, p, e - 1);
}
ll **anss = alok(1111, ll*);
int *ansc = alok(1111, int);
ll *mds = alok(1111, ll);

int subok(ll a, ll md, ll lim, int i, int pc) {
	if (i >= pc) {
		if (a < 0) a += md;
		//pf("got %I64d %I64d\n", a, md);
		return a <= lim;
	} else {
		fr(j,ansc[i]) {
			ll ggt = chinese(a, md, anss[i][j], mds[i]);
			if (subok(ggt, md * mds[i], lim, i + 1, pc)) return 1;
		}
		return 0;
	}

}
int main() {
	ll n, m;
	int k;
	sf("%I64d%I64d%d", &n, &m, &k);
	ll *a = alok(k, ll);
	seq = alok(k, int);
	seq2 = alok(k, int);
	ll *p = alok(1111, ll);
	int *e = alok(1111, int);
	ll g = 1;
	fr(i,k) {
		sf("%I64d", a + i);
		ll gg = gcd(g, a[i]);
		if (g / gg > n / a[i]) {
			g = n + 1;
			break;
		}
		g = g  / gcd(g, a[i]) * a[i];
	}
	if (g > n) {
		pf("NO\n");
	} else {
		ll gg = g;
		int pc = 0;
		int good = 1;
		for (ll cp = 2; cp <= gg; cp++) {
			if (cp > gg / cp) cp = gg;
			e[pc] = 0;
			while (gg % cp == 0) {
				e[pc]++;
				gg /= cp;
			}
			if (e[pc]) {
				fr(i,k) {
					seq[i] = 0;
					ll aa = a[i];
					while (aa % cp == 0) {
						aa /= cp;
						seq[i]++;
					}
				}
				//pf("%I64d^%d: ", cp, e[pc]);
				//fr(i,k) pf("%d ", seq[i]); pln;
				if (valid(0, k, cp, e[pc])) {
					fr(i,k) {
						seq[i] = 0;
						while (a[i] % cp == 0) {
							a[i] /= cp;
							seq[i]++;
						}
					}
					//pf("%I64d^%d: ", cp, e[pc]);
					//fr(i,k) pf("%d ", seq[i]); pln;	
					ansc[pc] = ans(0, k, cp, e[pc]);
					anss[pc] = alok(ansc[pc], ll);
					//pf("got %d\n", ansc[pc]);
					fr(i,ansc[pc]) anss[pc][i] = ggs[i];
					mds[pc] = md;
				} else {
					//pf("bad!\n");
					good = 0;
					break;
				}
				pc++;
			}
		}
		if (good) {
			/*
			fr(i,pc) {
				pf("%I64d %d: ", mds[i], ansc[i]);
				fr(j,ansc[i]) pf("%I64d ", anss[i][j]); pln;
			}//*/
			//pf("%I64d\n", m - k);
			if (subok(0, 1, m - k, 0, pc)) {
				pf("YES\n");
			} else {
				pf("NO\n");
			}
		} else {
			pf("NO\n");
		}
	}

}