#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
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

const int N = 200050;
int a[N], b[N], ansa, ansb, T, n;
int main() {
	for (read(T); T; T--) {
		read(n), ansa = ansb = 0;
		for (int i = 1;i <= n; ++i) read(a[i]), ansa += a[i];
		for (int i = 1;i <= n; ++i) read(b[i]), ansb += b[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		int L = 1, ans = 0, tl = 0;
		while (L <= (n >> 2)) ansa -= a[L], ansb -= b[L], ++L;
		tl = L - 1;
		while (ansa < ansb) {
			++n, ++ans, ansa += 100;
			if (L <= (n >> 2)) ansa -= a[L++];
			else if (tl) ansb += b[tl--];
		}
		write(ans);
	}
	return 0;
}