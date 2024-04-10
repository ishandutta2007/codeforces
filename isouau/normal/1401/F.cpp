#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1 << 19 | 5;

ll sum[N];
int a[N], tag1[25], tag2[25];
int n, q;

void build(int u, int l, int r) {
	if (l == r) {
		sum[u] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

void change(int u, int l, int r, int x, int y, int dep) {
	if (l == r) {
		sum[u] = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (tag1[dep - 1]) {
		if (mid >= x) x += (1 << (dep - 1));
		else x -= (1 << (dep - 1));
	}
	if (tag2[dep]) x = l + (1 << dep) - 1 - (x - l);
	if (mid >= x) change(u << 1, l, mid, x, y, dep - 1);
	else change(u << 1 | 1, mid + 1, r, x, y, dep - 1);
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

ll query(int u, int L, int R, int l, int r, int dep) {
	if (l <= L && R <= r) return sum[u];
	int mid = (L + R) >> 1; ll ans = 0;
	if (tag2[dep]) l = L + (1 << dep) - 1 - (l - L), r = L + (1 << dep) - 1 - (r - L), swap(l, r);
	// cout << u << " " << L << " " << R << " " << l << " " << r << " " << dep << endl;
	if (mid >= l) {
		if (tag1[dep - 1]) ans += query(u << 1 | 1, mid + 1, R, l + (1 << (dep - 1)), min(r + (1 << (dep - 1)), R), dep - 1);
		else ans += query(u << 1, L, mid, l, min(r, mid), dep - 1);
	}
	if (mid + 1 <= r) {
		if (tag1[dep - 1]) ans += query(u << 1, L, mid, max(L, l - (1 << (dep - 1))), r - (1 << (dep - 1)), dep - 1);
		else ans += query(u << 1 | 1, mid + 1, R, max(l, mid + 1), r, dep - 1);
	}
	return ans;
}

int main() {
	read(n); read(q);
	for (int i = 1; i <= (1 << n); i++) read(a[i]);
	build(1, 1, 1 << n);
	for (int i = 1; i <= q; i++) {
		int opt; read(opt);
		if (opt == 1) {
			int x, k;
			read(x); read(k);
			change(1, 1, 1 << n, x, k, n);
		}
		if (opt == 2) {
			int k; read(k); tag2[k] ^= 1;
		}
		if (opt == 3) {
			int k; read(k); tag1[k] ^= 1;
		}
		if (opt == 4) {
			int l, r; read(l); read(r);
			print(query(1, 1, 1 << n, l, r, n), '\n');
		}
	}
	return 0;
}