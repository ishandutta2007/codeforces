#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int  x = 0, f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
inline void write(int x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) {putchar('-'); x = -x;}
	int stk[20], tp = 0;
	for (; x; x /= 10) stk[tp ++] = x % 10;
	for (; tp; putchar(stk[-- tp] + '0')) ;
}
const int N = 500005;
int n, m;
struct Dsu {
	int fa[N], siz[N];
	Dsu() {for (int i = 0; i < N; ++ i) fa[i] = i, siz[i] = 1;}
	int Fa(int x) {return fa[x] == x ? x : fa[x] = Fa(fa[x]);}
	void Mg(int x, int y) {
		x = Fa(x), y = Fa(y);
		if (x == y) return;
		fa[y] = x; siz[x] += siz[y];
	}
	void sol() {
		for (int i = 1; i <= n; ++ i) {
			write(siz[Fa(i)]); putchar(32);
		}
	}
} dsu;
int main() {
	n = read(), m = read();
	for (int i = 0; i < m; ++ i) {
		int k = read();
		int lst = -1;
		for (int j = 0; j < k; ++ j) {
			int x = read();
			if (~lst) dsu.Mg(lst, x);
			lst = x;
		}
	}
	dsu.sol();
	return 0;
}