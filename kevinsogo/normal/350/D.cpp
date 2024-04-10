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


ll loo(ll a, ll b) {
	return a * a + b * b;
}
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
#define norm(x, y) do {\
	int g = gcd(x, y);\
	x /= g;\
	y /= g;\
	if (y < 0) {\
		x = -x;\
		y = -y;\
	}\
} while (0)
#include <map>
#include <algorithm>
using namespace std;
map<ll,int> stx;
map<ll,int> sty;
map<ll,int> idx;
int ids = 0;
int *cts;
ll **vl1;
ll **vl2;
ll *vlt1;
ll *vlt2;

int exists(ll hsh) {
	return idx.find(hsh) != idx.end();
}
void add(ll hsh, int sx, int sy) {
	stx[hsh] = sx;
	sty[hsh] = sy;
	idx[hsh] = ids++;
}
ll gettime(ll hsh, int dx, int dy, int x, int y) {
	int sx = stx[hsh];
	int sy = sty[hsh];
	//sx + dx*t == x
	//sy + dy*t == y
	if (dx) {
		return (x - sx) / dx;
	} else {
		return (y - sy) / dy;
	}
}
ll floor(ll a, ll b) {
	if (b < 0) {
		a = -a;
		b = -b;
	}
	if (a < 0) {
		return -(((-a)+b-1)/b);
	}
	return a / b;
}

ll hush(ll dx, ll dy, ll x, ll y) {
	if (dx == 0) {
		y = 0;
	} else if (dy == 0) {
		x = 0;
	} else {
		/*
		x - dx * t >= 0 > x - dx * (t + 1)
		x >= dx * t
		t <= x / dx
		*/
		ll t = floor(x, dx);
		x -= dx * t;
		y -= dy * t;	
	}

	ll hsh = dx;
	hsh <<= 16;
	hsh += dy;
	hsh <<= 16;
	hsh += x;
	hsh <<= 16;
	hsh += y;
	return hsh;
}

int smaller_than_gt_count(ll *vl, int ct, ll t) {
	if (!ct) return 0;
	if (vl[0] >= t) return 0;
	int L = 0, R = ct;
	while (R - L > 1) {
		int M = L + R >> 1;
		(vl[M] >= t ? R : L) = M;
	}
	return R;
}
int bigger_than_gt_count(ll *vl, int ct, ll t) {
	if (!ct) return 0;
	if (vl[ct-1] <= t) return 0;
	int L = -1, R = ct-1;
	while (R - L > 1) {
		int M = L + R >> 1;
		(vl[M] <= t ? L : R) = M;
	}
	return ct - R;
}

#define inf 1111111
#define bad(X) (X < -inf || X > inf)
int main() {
	int n, m;
	sf("%d%d", &n, &m);
	int *x1 = alok(n, int);
	int *y1 = alok(n, int);
	int *x2 = alok(n, int);
	int *y2 = alok(n, int);
	int *xi = alok(m, int);
	int *yi = alok(m, int);
	int *ri = alok(m, int);
	fr(i,n) {
		ll X1, Y1, X2, Y2;
		sf("%I64d%I64d%I64d%I64d", &X1, &Y1, &X2, &Y2);
		if (bad(X1) || bad(Y1) || bad(X2) || bad(Y2)) {
			i--;
			n--;
			continue;
		}
		X1 <<= 1;
		Y1 <<= 1;
		X2 <<= 1;
		Y2 <<= 1;
		//sf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
		x1[i] = X1;//<<= 1;
		y1[i] = Y1;//<<= 1;
		x2[i] = X2;//<<= 1;
		y2[i] = Y2;//<<= 1;

		int dx = x2[i] - x1[i];
		int dy = y2[i] - y1[i];
		norm(dx, dy);
		ll hsh = hush(dx, dy, x1[i], y1[i]);
		if (!exists(hsh)) add(hsh, x1[i], y1[i]);
	}

	cts = alok(ids, int);
	fr(i,ids) cts[i] = 0;
	fr(i,n) {
		int dx = x2[i] - x1[i];
		int dy = y2[i] - y1[i];
		norm(dx, dy);
		ll hsh = hush(dx, dy, x1[i], y1[i]);
		int ind = idx[hsh];
		cts[ind]++;
	}
	ll *vlo1 = vlt1 = alok(n, ll);
	ll *vlo2 = vlt2 = alok(n, ll);
	vl1 = alok(ids, ll*);
	vl2 = alok(ids, ll*);
	fr(i,ids) {
		vl1[i] = vlo1;
		vl2[i] = vlo2;
		vlo1 += cts[i];
		vlo2 += cts[i];
		cts[i] = 0;
	}
	fr(i,n) {
		int dx = x2[i] - x1[i];
		int dy = y2[i] - y1[i];
		norm(dx, dy);
		ll hsh = hush(dx, dy, x1[i], y1[i]);
		ll gt1 = gettime(hsh, dx, dy, x1[i], y1[i]);
		ll gt2 = gettime(hsh, dx, dy, x2[i], y2[i]);
		if (gt1 > gt2) {
			gt1 ^= gt2;
			gt2 ^= gt1;
			gt1 ^= gt2;
		}
		int ind = idx[hsh];
		vl1[ind][cts[ind]] = gt1;
		vl2[ind][cts[ind]] = gt2;
		cts[ind]++;
	}
	fr(i,ids) {
		sort(vl1[i], vl1[i] + cts[i]);
		sort(vl2[i], vl2[i] + cts[i]);
	}
	ll ans = 0;
	fr(i,m) {
		sf("%d%d%d", xi + i, yi + i, ri + i);
		ll X = xi[i], Y = yi[i], R = ri[i];
		fr(j,i) {
			ll x = xi[j], y = yi[j], r = ri[j];
			if (R != r) continue;
			if ((r*r<<2) >= loo(X-x,Y-y)) continue; // common points
			ll xx = X + x;
			ll yy = Y + y;
			int dx = y - Y;
			int dy = X - x;
			norm(dx, dy);
			ll hsh = hush(dx, dy, xx, yy);
			if (!exists(hsh)) continue;
			int ind = idx[hsh];
			ans += cts[ind];
			ll gt = gettime(hsh, dx, dy, xx, yy);
			ans -= smaller_than_gt_count(vl2[ind], cts[ind], gt);
			ans -= bigger_than_gt_count(vl1[ind], cts[ind], gt);
		}
	}
	pf("%I64d\n", ans);
}