#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

#include <set>
const int N = 200050;
int v[N], n, m, q, cnt;
void add(int x, int y) {
	if (x < y) swap(x, y);
	cnt += !v[y]++;
}

void del(int x, int y) {
	if (x < y) swap(x, y);
	cnt -= !--v[y];
}

int main() {
	read(n), read(m);
	for (int i = 1, x, y;i <= m; ++i) read(x), read(y), add(x, y);
	read(q);
	for (int i = 1, op,  x, y;i <= q; ++i) {
		read(op);
		if (op == 3) write(n - cnt);
		else read(x), read(y), op == 1 ? add(x, y) : del(x, y);
	}
	return 0;
}