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

const int N = 505000;
vector<int> vec[N];
int a[N], b[N], cnt, n;
int main() {
	read(n);
	for (int i = 1;i <= n; ++i) read(a[i]), vec[n - a[i]].push_back(i);
	for (int i = 1;i <= n; ++i) if (vec[i].size()) {
		int sz = vec[i].size(); if (sz % i) return puts("Impossible"), 0;
		int las = 0;
		for (auto t: vec[i]) {
			if (!las) ++cnt, las = i;
			--las, b[t] = cnt;
		}
	}
	puts("Possible");
	for (int i = 1;i <= n; ++i)
		write(b[i], ' ');
	return 0;
}