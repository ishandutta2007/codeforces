#include <bits/stdc++.h>
#define fi first
#define se second
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

const int P = 1e9 + 7;
const int N = 4005;
int n, p, k;
char A[N];
ll f[2][N][2][2], V[N], bit[N];
inline void Add(ll &x, ll y) { x = (x + y) % P; }
ll calc(ll x) { 
	if (x < 0) return 0;
	if (x < p) return (1 + x + 1) * (x + 1) >> 1;
	ll tmp = 1ll * p * p;
	++x;
	if (x <= 2 * p - 2) tmp -= (1 + 2 * p - 1 - x) * (2 * p - x - 1) >> 1;
	return tmp;
}
const int bs = 1e9;
ll calc(int l, int r) { return (calc(r) - calc(l - 1)) % P; }
int main() {
	read(p), read(k);
	scanf ("%s", A), n = strlen(A), reverse(A, A + n);
	int lim = (n - 1) / 9;
	for (int i = 0;i <= lim; ++i) {
		for (int j = min(n - 1, (i + 1) * 9 - 1);j >= i * 9; --j)
			bit[i] = bit[i] * 10 + (A[j] ^ '0');
	}
	n = 0;
	while (lim >= 0) {
		ll res = 0;
		for (int i = lim;i >= 0; --i)
			res = res * bs + bit[i], bit[i] = res / p, res %= p;
		V[++n] = res;
		while (lim >= 0 && !bit[lim]) --lim;
	}
	if (n < k) return write(0), 0;
	int nw = 0, pr = 1;
	f[nw][0][0][0] = 1;
	for (int i = 1;i <= n; ++i) {
		swap(nw, pr), memset(f[nw], 0, sizeof(f[nw]));
		for (int t = 0;t <= k && t <= i; ++t) {
			for (int p1 = 0;p1 <= 1; ++p1) 
				for (int p2 = 0;p2 <= 1; ++p2) {
					ll tmp = f[pr][t][p1][p2];
					if (!tmp) continue;
					if (V[i] >= p1) Add(f[nw][t][0][p2], (V[i] - p1 + 1) * tmp);
					if (V[i] < p - 1) Add(f[nw][t][0][1], calc(V[i] + 1 - p1, p - 1 - p1) * tmp);
					if (V[i] > p1) Add(f[nw][t][0][0], calc(0, V[i] - 1 - p1) * tmp);
					int to = min(t + 1, k);
					Add(f[nw][to][1][p2], calc(V[i] - p1 + p, V[i] - p1 + p) * tmp);
					if (V[i] < p - 1) Add(f[nw][to][1][1], calc(V[i] - p1 + p + 1, p + p - 1 - p1) * tmp);
					if (V[i]) Add(f[nw][to][1][0], calc(p - p1, p + V[i] - 1 - p1) * tmp);
				}
		}
	}
	write(f[nw][k][0][0]);
	return 0;
}