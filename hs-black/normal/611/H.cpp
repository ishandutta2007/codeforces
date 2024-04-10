/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)


*/

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

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

int cnt[10], ok[10], ed[10][10], st[10], A, B, n, m;
char a[10], b[10];
inline bool check(void) {
	for (int i = 1;i < (1 << m) - 1; ++i) {
		int t1 = 0, t2 = 0;
		for (int j = 0;j < m; ++j) if (i >> j & 1) {
			t1 += cnt[j];
			for (int k = 0;k < m; ++k)
				if ((~i >> k & 1) || j <= k) t2 += ed[j][k];
		}
		if (t2 < t1) return 0;
	}
	return 1;
}

int main() {
	read(n); int t = n;
	while (t) ++m, t /= 10;
	st[0] = 1;
	for (int i = 1;i <= m; ++i) st[i] = st[i-1] * 10;
	for (int i = 0;i < m; ++i) cnt[i] = st[i + 1] - st[i];
	cnt[m - 1] = n - st[m - 1] + 1;
	for (int i = 1;i < n; ++i) {
		scanf ("%s%s", a, b), A = strlen(a) - 1, B = strlen(b) - 1;
		++ed[A][B];
		if (A != B) ++ed[B][A];
	}
	if (!check()) return write(-1), 0;
	--cnt[0], ok[0] = 1, st[0] = 2;
	int edges = 0;
	while (edges < n - 1) {
		for (int i = 0;i < m; ++i) if (ok[i]) {
			for (int j = 0;j < m; ++j) if (cnt[j] && ed[i][j]) {
				--cnt[j], --ed[i][j]; if (i != j) --ed[j][i];
				if (check()) write(st[i] - 1, ' '), write(st[j]), ++edges, ++st[j], ok[j] = 1;
				else { ++cnt[j], ++ed[i][j]; if (i != j) ++ed[j][i]; }
			}
		}
	}
	return 0;
}