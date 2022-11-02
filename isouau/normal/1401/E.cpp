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

const int N = 1 << 20;

struct ele {
	int x, l, r;
	ele (int a = 0, int b = 0, int c = 0) : x(a), l(b), r(c) {}
} a[N], b[N];

set <pii> wxw;
int f[N];
int n, m; ll ans;

inline int lowbit(int x) { return  x & -x; }

void add(int x, int y) {
	++x;
	while (x < (1 << 20)) {
		f[x] += y;
		x += lowbit(x);
	}
}

int query(int x) {
	++x;
	int ans = 0;
	while (x) {
		ans += f[x];
		x ^= lowbit(x);
	}
	return ans;
}

bool cmpa(ele a, ele b) { return a.x < b.x; }
bool cmpb(ele a, ele b) { return a.l < b.l; }

int val[N << 2];

void add(int u, int L, int R, int l, int r, int x) {
	if (l <= L && R <= r) {
		val[u] = x;
		return;
	}
	int mid = (L + R) >> 1;
	if (mid >= l) add(u << 1, L, mid, l, r, x);
	if (mid + 1 <= r) add(u << 1 | 1, mid + 1, R, l, r, x);
}

int query(int u, int l, int r, int x) {
	if (l == r) return val[u];
	int mid = (l + r) >> 1, ans = val[u];
	if (mid >= x) ans = min(ans, query(u << 1, l, mid, x));
	else ans = min(ans, query(u << 1 | 1, mid + 1, r, x));
	return ans;
}

int main() {
	memset(val, 0x7f, sizeof(val));
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i].x), read(a[i].l), read(a[i].r);
	for (int i = 1; i <= m; i++) read(b[i].x), read(b[i].l), read(b[i].r);
	a[++n] = ele(0, 0, 1000000); a[++n] = ele(1000000, 0, 1000000);
	b[++m] = ele(0, 0, 1000000); b[++m] = ele(1000000, 0, 1000000);
	sort(a + 1, a + n + 1, cmpa); sort(b + 1, b + m + 1, cmpb);
	int now = m;
	for (int i = n; i >= 1; i--) {
		add(1, 0, 1000000, a[i].l, a[i].r, a[i].x);
		while (now && (i == 1 || b[now].l > a[i - 1].x)) {
			b[now].l = query(1, 0, 1000000, b[now].x);
			--now;
		}
	}
	sort(b + 1, b + m + 1, cmpb);
	for (int i = 2; i <= n; i++) {
		while (now <= m && b[now].l == a[i - 1].x) {
			add(b[now].x, 1);
			wxw.insert(make_pair(b[now].r, b[now].x));
			++now;
		}
		while (wxw.size()) {
			auto it = wxw.begin();
			if (it -> first < a[i].x) {
				add(it -> second, -1);
				wxw.erase(it);
			} else break;
		}
		ans += query(a[i].r) - query(a[i].l - 1) - 1;
	}
	print(ans, '\n');
	return 0;
}