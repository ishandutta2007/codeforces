#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define MP make_pair
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

const ll inf = 1e17;
const int N = 1305000;
ll st[23], a[23], v1[N], v2[N];
int prework(ll *v, int l, int r) {
	static ll A[N], B[N];
	int L = 1; v[1] = 0;
	for (int i = l;i <= r; ++i) {
		for (int j = 1;j <= L; ++j) A[j] = v[j] + st[i], B[j] = v[j] - st[i];
		int t1 = 0, t2 = 0, t = 0;
		while (t1 < L || t2 < L) {
			ll v1 = t1 >= L ? inf : A[t1 + 1];
			ll v2 = t2 >= L ? inf : B[t2 + 1];
			v1 < v2 ? (v[++t] = v1, ++t1) : (v[++t] = v2, ++t2);
		}
		L = t;
	}
	return L;
}

int f[N], n;
bool check(int s) {
	int t = 0, k = 1; ll sum = 0;
	for (int i = 1;i <= n; ++i)
		if (s >> i - 1 & 1) st[++t] = a[i], sum += a[i];
	if (((sum - t + 1) % 2) || t <= 1) return 0;
	int cnt = abs(sum) < t ? 3 : 1;
	int A = prework(v1, 1, t / 2), B = prework(v2, t / 2 + 1, t);
	for (int i = A;i >= 1 && cnt; --i) {
		while (k <= B && v2[k] + v1[i] < - (t - 1)) ++k;
		if (k > B) break;
		for (int tk = k;tk <= B && cnt && v2[tk] + v1[i] < t; ++tk) --cnt;
	}
	return !cnt;
}

int main() {
	read(n); int m = 0;
	for (int i = 1;i <= n; ++i) read(a[i]), a[i] && (a[++m] = a[i]);
	n = m;
	int lim = (1 << n) - 1;
	for (int i = 1;i <= lim; ++i) if (check(i) && !f[i]) {
		f[i] = 1; int s = lim ^ i;
		for (int t = s; t; t = (t - 1) & s)
			f[i | t] = max(f[i | t], f[t] + 1);
	}
	write(n - f[lim]);
	return 0;
}