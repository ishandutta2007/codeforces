#include <iostream>
#include <map>
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

const int N = 1000500;
int f[N], e[N], v[N], st[N], tp, n, q;
int pr[N], a[N], tot;
void prework(int n) {
	for (int i = 2;i <= n; ++i) {
		if (!e[i]) pr[e[i] = ++tot] = i;
		for (int j = 1;j <= e[i] && pr[j] * i <= n; ++j) 
			e[pr[j] * i] = j;
	}
}

map<int, int> mp[150005];
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
	read(n), read(q), prework(1e6 + 1);
	for (int i = 1;i <= n; ++i) f[i] = i;
	//puts("OK");
	for (int i = 1, x;i <= n; ++i) {
		read(a[i]), x = a[i];
		while (x > 1) {
			if (v[e[x]]) f[find(v[e[x]])] = i;
			v[e[x]] = i, x /= pr[e[x]];
		}
	}
	//puts("OK");
	//for (int i = 1;i <= n; ++i) 
		//printf ("f[%d] = %d\n", i, f[i]);
	////for (int i = 1;i <= 10; ++i)
		//printf ("v[%d] = %d\n", i, v[i]);
	for (int i = 1, x;i <= n; ++i) {
		x = a[i] + 1, st[tp = 1] = find(i);
		while (x > 1) {
			if (v[e[x]]) st[++tp] = find(v[e[x]]);
			x /= pr[e[x]];
		}
		sort(st + 1, st + tp + 1);
		tp = unique(st + 1, st + tp + 1) - st - 1;
		//for (int i = 1;i <= tp; ++i)
			//printf ("st[%d] = %d\n", i, st[i]);
		for (int i = 1;i <= tp; ++i)
			for (int j = 1;j <= tp; ++j) 
				mp[st[i]][st[j]] = 1;
	}
	//puts("OK");
	for (int i = 1, s, t;i <= q; ++i) {
		read(s), read(t), s = find(s), t = find(t);
		if (find(s) == find(t)) write(0);
		else if (mp[s][t]) write(1);
		else write(2);
	}
	return 0;
}