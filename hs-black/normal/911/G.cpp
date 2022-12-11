#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 200005;
int a[N], m, n;
int tag[N<<2][101];
int T[500], cnt;

#define p1 p << 1
#define p2 p << 1 | 1

inline void spread(int p) {
	int P1 = p1, P2 = p2;
	for (register int i = 1;i <= 100; i++) {
		tag[P1][i] = tag[p][tag[P1][i]];
		tag[P2][i] = tag[p][tag[P2][i]];
	}
	for (register int i = 1;i <= 100; i++)
		tag[p][i] = i;
}

int ql, qr, x, y;
void change(int p, int l, int r) {
	if (ql <= l && r <= qr) {
		for (int i = 1;i <= 100; i++)
			if (tag[p][i] == x) tag[p][i] = y;
		return;
	}
	spread(p);
	int mid = (l + r) >> 1;
	if (ql <= mid) change(p1, l, mid);
	if (qr > mid) change(p2, mid + 1, r);
}

void out(int p, int l, int r) {
	if (l == r) {
		write(tag[p][a[l]]), putchar(' ');
		return;
	}
	spread(p);
	int mid = (l + r) >> 1;
	out(p1, l, mid);
	out(p2, mid + 1, r);
}

void build(int p, int l, int r) {
	for (register int i = 1;i <= 100; i++) tag[p][i] = i;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(p1, l, mid); build(p2, mid + 1, r);
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(a[i]);
	read(m); build(1, 1, n);
	while (m--) {
		read(ql), read(qr), read(x), read(y);
		change(1, 1, n);
	}
	out(1, 1, n);
	return 0;
}