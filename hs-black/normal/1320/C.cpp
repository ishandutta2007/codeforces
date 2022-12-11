#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
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
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 405000;
struct Q {
	int x, y, z;
	int opt;
	Q(int xx = 0, int yy = 0, int zz = 0, int o = 0) {
		x = xx, z = zz, y = yy, opt = o;
	}
	bool operator < (const Q &i) const {
		if (x != i.x) return x < i.x;
		return opt < i.opt;
	}
}q[N<<1];

struct node {
	ll b, z;
	bool operator < (const node &i) const {
		return b < i.b;
	}
}b[N];

ll add[N<<3], mx[N<<3], d[N];
int L[N<<3], R[N<<3];
#define p1 p << 1
#define p2 p << 1 | 1
const ll INF = 0x7ffffffffff;
void build(int l, int r, int p) {
	L[p] = l, R[p] = r;
	if (l == r) return mx[p] = -b[l].z, void();
	int mid = (l + r) >> 1;
	build(l, mid, p1), build(mid + 1, r, p2);
	if (!L[p1]) mx[p1] = -INF;
	if (!L[p2]) mx[p2] = -INF;
	mx[p] = max(mx[p1], mx[p2]);
}

void spread(int p) {
	add[p1] += add[p], add[p2] += add[p];
	mx[p1] += add[p], mx[p2] += add[p];
	add[p] = 0;
}

void change(int l, int r, int p, int k) {
	if (l <= L[p] && R[p] <= r) return add[p] += k, mx[p] += k, void();
	if (add[p]) spread(p);
	if (l <= R[p1]) change(l, r, p1, k);
	if (r >= L[p2]) change(l, r, p2, k);
	mx[p] = max(mx[p1], mx[p2]);
}

int cnt, n, m, p;
ll ans = -INF;
int main() {
	read(n), read(m), read(p);
	for (int i = 1;i <= n; i++) {
		int x, y; read(x), read(y);
		q[++cnt] = Q(x - 1, 0, y, 1);
	}
	for (int i = 1;i <= m; i++) read(b[i].b), read(b[i].z), d[i] = b[i].b;
	sort(b + 1, b + m + 1); sort(d + 1, d + m + 1);
	for (int i = 1;i <= p; i++) {
		int x, y, z; read(x), read(y), read(z);
		q[++cnt] = Q(x, y, z, 0);
	}
	sort(q + 1, q + cnt + 1);
	build(1, m, 1);
	for (int i = 1;i <= cnt; i++) {
		if (q[i].opt) ans = max(ans, mx[1] - q[i].z);
		else {
			int k = upper_bound(d + 1, d + m + 1, q[i].y) - d;
			if (k > m) continue;
			change(k, m, 1, q[i].z);
		}
	}
	cout << ans << endl;
	return 0;
}