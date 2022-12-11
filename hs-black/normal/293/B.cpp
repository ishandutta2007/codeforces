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

const int N = 50;
int a[N][N], n, m, k;
int used[N];
ll f[N][(1<<11)+5];

const int P = 1e9+7;
ll dfs(int x, int y) {
	if (y > m) x = x + (y = 1);
	if (x == n + 1) return 1;
	ll tmp = f[x][y-1] | f[x-1][y], use = 0, fl = 0;
	for (int i = 1;i <= k; i++) use += !((1 << (i - 1)) & tmp);
	if (n + m - x - y + 1 > use) return 0;
	ll res = 0;
	for (int i = 1;i <= k; i++) {
		if (a[x][y]) i = a[x][y];
		f[x][y] = tmp | (1 << (i - 1));
		if (f[x][y] == tmp) {
			if (a[x][y]) break;
			continue;
		}
		used[i]++;
		if (used[i] == 1) {
			if (!fl) use = dfs(x, y + 1), fl = 1;
			res += use;
		}
		else res += dfs(x, y + 1);
		res %= P, used[i]--;
		if (a[x][y]) break;
	}
	return res;
}

int main() {
	read(n), read(m), read(k);
	if (n + m - 1 > k) return puts("0"), 0;
	for (int i = 1;i <= n; i++) 
		for (int j = 1;j <= m; j++)
			read(a[i][j]), used[a[i][j]]++;
	return printf ("%lld\n", dfs(1, 1)), 0;
}