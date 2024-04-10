#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100005, P = 998244353;
int pow(int x, int y) {
	int r = 1;
	for (; y; y >>= 1, x = (ll)
		x * x % P)
			if (y & 1)
				r = (ll)
					r * x % P;
	return r;
} 
int n, x[N], v[N], p[N], l[N][4], val[N * 2];
pair < pii, pii > s[N * 2];
struct tag{
	int s[2][2];
}
;
struct node{
	int c[2];
	tag t;
} 
f[550005];
tag merge(tag a, tag b) {
	tag res ={
		0, 0, 0, 0}
	;
	for (int i = 0; i < 2; i ++)
		for (int j = 0; j < 2; j ++)
			for (int k = 0; k < 2; k ++)
				res.s[i][k] = (res.s[i][k] + (ll)
					a.s[i][j] * b.s[j][k]) % P;
	return res;
} 
void mul(int * a, tag b) {
	int res[2] ={
		0, 0}
	;
	for (int i = 0; i < 2; i ++)
		for (int j = 0; j < 2; j ++)
			res[j] = (res[j] + (ll)
				a[i] * b.s[i][j]) % P;
	a[0] = res[0], a[1] = res[1];
} 
void pd(int x) {
	if (f[x].t.s[0][0] != 1 || f[x].t.s[0][1] || f[x].t.s[1][0] || f[x].t.s[1][1] != 1) {
		mul(f[x << 1].c, f[x].t);
		mul(f[x << 1 | 1].c, f[x].t);
		f[x << 1].t = merge(f[x << 1].t, f[x].t);
		f[x << 1 | 1].t = merge(f[x << 1 | 1].t, f[x].t);
		f[x].t = (tag) {
			1, 0, 0, 1}
		;
	}
} 
void pu(int x) {
	for (int i = 0; i < 2; i ++)
		f[x].c[i] = (f[x << 1].c[i] + f[x << 1 | 1].c[i]) % P;
} 
void mul(int x, int l, int r, int ql, int qr, tag v) {
	if (l >= ql && r <= qr) {
		mul(f[x].c, v);
		f[x].t = merge(f[x].t, v);
		return;
	} 
	int t = (l + r) >> 1;
	pd(x);
	if (ql <= t)
		mul(x << 1, l, t, ql, qr, v);
	if (qr > t)
		mul(x << 1 | 1, t + 1, r, ql, qr, v);
	pu(x);
} 
void mod(int x, int l, int r, int p, int cp, int v) {
	if (l == r) {(f[x].c[cp] += v) %= P;
		return;
	} 
	int t = (l + r) >> 1;
	pd(x);
	if (p <= t)
		mod(x << 1, l, t, p, cp, v);
	else mod(x << 1 | 1, t + 1, r, p, cp, v);
	pu(x);
} 
int qry(int x, int l, int r, int ql, int qr, int p) {
	if (l >= ql && r <= qr)
		return f[x].c[p];
	int t = (l + r) >> 1, res = 0;
	pd(x);
	if (ql <= t)
		res += qry(x << 1, l, t, ql, qr, p);
	if (qr > t)
		res += qry(x << 1 | 1, t + 1, r, ql, qr, p);
	return res >= P ? res - P : res;
} 
void build(int x, int l, int r) {
	f[x].t = (tag) {
		1, 0, 0, 1}
	;
	if (l != r) {
		int t = (l + r) >> 1;
		build(x << 1, l, t);
		build(x << 1 | 1, t + 1, r);
	}
} 
struct tmpm{
	int v, x, y;
	bool operator < (const tmpm & o)
		const{
			return v < o.v;
	}
}
;
int main() {
	scanf("%d", & n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d%d", x + i, v + i, p + i);
		p[i] = p[i] * 828542813ll % P;
	} 
	int c = 0;
	for (int i = 1; i <= n - 1; i ++) {
		s[c ++] = mp(mp(x[i + 1] - x[i], v[i + 1] + v[i]), mp(i, 2));
		if (v[i] > v[i + 1]) {
			s[c ++] = mp(mp(x[i + 1] - x[i], v[i] - v[i + 1]), mp(i, 3));
		} 
		else if (v[i] < v[i + 1]) {
			s[c ++] = mp(mp(x[i + 1] - x[i], v[i + 1] - v[i]), mp(i, 0));
		}
	} 
	sort(s, s + c,[&](const pair < pii, pii >& a, const pair < pii, pii >& b) {
		pii x = a.xx, y = b.xx; return(ll)
			x.xx * y.yy < (ll)
				y.xx * x.yy;}
	);
	for (int i = 0; i < c; i ++) {
		l[s[i].yy.xx][s[i].yy.yy] = i + 1;
		val[i + 1] = (ll)
			s[i].xx.xx * pow(s[i].xx.yy, P - 2) % P;
	} 
	build(1, 0, c + 1);
	mod(1, 0, c + 1, c + 1, 0, P + 1 - p[1]);
	mod(1, 0, c + 1, c + 1, 1, p[1]);
	for (int i = 2; i <= n; i ++) {
		tmpm t[4];
		tag tmp;
		for (int x = 0; x < 2; x ++)
			for (int y = 0; y < 2; y ++) {
				if (l[i - 1][x * 2 + y]) {
					int v = l[i - 1][x * 2 + y];
					t[x * 2 + y] = (tmpm) {
						v, x, y}
					;
				} 
				else {
					t[x * 2 + y] = (tmpm) {
						c + 1, x, y}
					;
				} 
				tmp.s[x][y] = (y ? p[i] : P + 1 - p[i]);
		} 
		sort(t, t + 4);
		int lst = 0;
		for (int j = 0; j < 4; j ++) {
			if (lst > t[j].v)
				continue;
			mul(1, 0, c + 1, lst, t[j].v, tmp);
			int u = 0;
			if (t[j].v != c + 1)
				u = qry(1, 0, c + 1, t[j].v + 1, c + 1, t[j].x);
			mod(1, 0, c + 1, t[j].v, t[j].y,(ll)
				u * tmp.s[t[j].x][t[j].y] % P);
			tmp.s[t[j].x][t[j].y] = 0;
			lst = t[j].v + 1;
		}
	} 
	int ans = 0;
	for (int i = 1; i <= c; i ++)
		ans = (ans + (ll)
			val[i] * (qry(1, 0, c + 1, i, i, 0) + qry(1, 0, c + 1, i, i, 1))) % P;
	printf("%d\n", ans);
}