#pragma GCC optimize(3,"inline")
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
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
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 2000500;
int f[N], a[N], b[N], c[N], m, n;

inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	read(n);
	for (int i = 1;i <= n; i++) {
		read(a[i]), read(b[i]);
		c[++m] = a[i], c[++m] = b[i];
	}
	sort(c + 1, c + m + 1);
	m = unique(c + 1, c + m + 1) - c - 1;
	for (int i = 1;i <= m; i++) f[i] = i;
	int ans = 0;
	for (int i = 1;i <= n; i++) {
		int x = lower_bound(c + 1, c + m + 1, a[i]) - c;
		int y = lower_bound(c + 1, c + m + 1, b[i]) - c;
		x = find(x), y = find(y);
		if (x > y) swap(x, y);
		if (!x && !y) return puts("-1");
		if (!x || x == y) Mx(ans, y), f[y] = 0;
		else f[x] = y, Mx(ans, x);
	}
	
	printf ("%d\n", c[ans]);
	
	return 0;
}