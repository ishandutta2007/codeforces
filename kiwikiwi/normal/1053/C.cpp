#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 mod = 1000000007;

const int maxN = 223456;

i64 c[maxN], c2[maxN];
int pos[maxN], w[maxN], n, q, a, b;

void modify(int x, i64 s) {
	for (; x <= n; x += x & -x)
		c[x] += s;
}

void modify2(int x, i64 s) {
	for (; x <= n; x += x & -x)
		c2[x] = (c2[x] + s) % mod;
}

i64 query(int x) {
	i64 s = 0;
	for (; x; x -= x & -x)
		s += c[x];
	return s;
}

i64 query3(int x) {
	i64 s = 0;
	for (; x; x -= x & -x)
		s = (s + c2[x]) % mod;
	return s;
}

int query2(i64 s) {
	int x = 0;
	for (int i = 18; i >= 0; i--) {
		if (x + (1 << i) <= n && s > c[x + (1 << i)]) {
			x += (1 << i);
			s -= c[x];
		}
	}
	return x + 1;
}

i64 query(int l, int r) {
	i64 q1 = query(l - 1);
	i64 q2 = query(r);
	int mid = query2((q1 + q2 + 1) / 2);
	i64 p1 = query3(mid) - query3(l - 1);
	i64 p2 = (query(mid) - query(l - 1)) % mod * pos[mid];
	i64 p3 = query3(r) - query3(mid);
	i64 p4 = (query(r) - query(mid)) % mod * pos[mid];
	i64 ans = (p3 - p4) + (p2 - p1);
	ans %= mod;
	if (ans < 0) ans += mod;
	return ans;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", pos + i);
		pos[i] -= i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", w + i);
		modify(i, w[i]);
		modify2(i, (i64)pos[i]*w[i] % mod);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &a, &b);
		if (a > 0) {
			printf("%lld\n", query(a, b));
		} else {
			a = -a;
			modify(a, -w[a]);
			modify2(a, -(i64)pos[a]*w[a] % mod);
			w[a] = b;
			modify(a, w[a]);
			modify2(a, (i64)pos[a]*w[a] % mod);
		}
	}
}