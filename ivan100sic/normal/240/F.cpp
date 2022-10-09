#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define cin compileerror
#define cout compileerror

struct node {
	int sm[26], len, lz;

	node() {
		fill(sm, sm+26, 0);
		len = 0;
		lz = -2;
	}

	node operator+ (const node& b) const {
		node tmp;
		for (int i=0; i<26; i++)
			tmp.sm[i] = sm[i] + b.sm[i];
		tmp.len = len + b.len;
		return tmp;
	}
};

const int maxn = 131072;
node b[2 * maxn];

void push(int x) {
	if (b[x].lz != -2) {
		if (x < maxn) {
			b[2*x].lz = b[x].lz;
			b[2*x+1].lz = b[x].lz;
		}
		fill(b[x].sm, b[x].sm+26, 0);
		if (b[x].lz >= 0)
			b[x].sm[b[x].lz] = b[x].len;
	}
}

node query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
	push(x);
	if (r < xl || xr < l)
		return node();
	if (l <= xl && xr <= r)
		return b[x];
	int xm = (xl+xr) >> 1;
	return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
}

void update1(int l, int r, int c, int x=1, int xl=0, int xr=maxn-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}
	if (l <= xl && xr <= r) {
		b[x].lz = c;
		push(x);
		return;
	}
	push(x);
	int xm = (xl+xr) >> 1;
	update1(l, r, c, 2*x, xl, xm);
	update1(l, r, c, 2*x+1, xm+1, xr);
	b[x] = b[2*x] + b[2*x+1];
}

void update_all0(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}
	if (l <= xl && xr <= r) {
		b[x].lz = -1;
		push(x);
		return;
	}
	push(x);
	int xm = (xl+xr) >> 1;
	update_all0(l, r, 2*x, xl, xm);
	update_all0(l, r, 2*x+1, xm+1, xr);
	b[x] = b[2*x] + b[2*x+1];
}

void rek(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
	push(x);
	if (r < xl || xr < l)
		return;
	if (xl == xr) {
		for (int i=0; i<26; i++)
			if (b[x].sm[i])
				fout << (char)('a'+i);
		return;
	}
	int xm = (xl+xr) >> 1;
	rek(l, r, 2*x, xl, xm);
	rek(l, r, 2*x+1, xm+1, xr);
}

int main() {
	for (int i=0; i<maxn; i++)
		b[i + maxn].len = 1;
	for (int i=maxn-1; i; i--)
		b[i] = b[2*i] + b[2*i+1];

	int n, q;
	string s;
	fin >> n >> q >> s;
	for (int i=0; i<n; i++) {
		update1(i, i, s[i]-'a');
	}
	while (q--) {
		int l, r;
		fin >> l >> r;
		l--, r--;
		auto t = query(l, r);
		int oddc = 0, odd = 0;
		for (int i=0; i<26; i++) {
			if (t.sm[i] % 2) {
				odd = i;
				oddc++;
			}
		}

		if (oddc >= 2)
			continue;

		update_all0(l, r);

		int tl = l, tr = r;
		for (int i=0; i<26; i++) {
			int w = t.sm[i] / 2;
			if (w) {
				update1(tl, tr, i);
				tl += w;
				tr -= w;
			}
		}

		if (oddc) {
			update1(tl, tr, odd);
		}
	}

	rek(0, n-1);
	fout << '\n';
}