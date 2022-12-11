#include <bits/stdc++.h>
#define ok printf ("ok on line#%d\n", __LINE__)
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c);  c = getchar())
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

#define NO puts("No"), 0
const int lim = 2e5;
const int N = 205000;
ll a[N]; int n; 
inline bool is(ll x) {
	ll t = sqrt(x);
	return t * t == x || (t + 1) * (t + 1) == x;
}

int main() {
	read(n);
	for (int i = 2;i <= n; i += 2) read(a[i]);
	ll pre = 1;
	while ((pre * pre <= a[2] || !is(pre * pre - a[2])) && pre <= lim) ++pre;
	if (pre > lim) return NO;
	a[1] = pre * pre - a[2];
	for (int i = 4;i <= n; i += 2) {
		ll nw = pre + 2;
		while (nw <= lim && (nw * nw - pre * pre <= a[i] || !is(nw * nw - a[i])))
			++nw;
		if (nw > lim) return NO;
		a[i - 1] = nw * nw - a[i] - pre * pre, pre = nw;
	}
	puts("Yes");
	for (int i = 1;i <= n; ++i) write(a[i], ' ');
	return 0;
}