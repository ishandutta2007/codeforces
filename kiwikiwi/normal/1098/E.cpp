// stop creating shit problems

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int maxN = 123456;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int n, a[maxN], g[20][maxN], f[maxN];
i64 cnt[maxN];

const int kW = 100001;

i64 floordiv(i64 a, i64 b) {
	if (a > 0) return a / b;
	else if (a % b == 0) return a / b;
	else return a / b - 1;
}

i64 ksum(i64 a, i64 b, i64 c, i64 n) {
	i64 ans = 0;
	ans += (b / c) * n;
	b %= c;
	ans += (a / c) * n * (n - 1) / 2;
	a %= c;
	if (a * n + b < c) return ans;
	else return ans + ksum(c, (a * n + b) % c, a, (a * n + b) / c);
}


i64 rangesum(i64 l1, i64 l2, i64 a, i64 b, i64 c) {
	if (l1 > l2) return 0;
	i64 d = floordiv(b, c);
	b = b - d * c;
	return ksum(a, b, c, l2 + 1) - ksum(a, b, c, l1) + d * (l2 - l1 + 1);
}

i64 calcK(i64 a1, i64 d1, i64 n1, i64 a2, i64 d2, i64 n2, i64 k) {
	k = -(k + a1 - a2) - 1 + d1;
	i64 r1 = floordiv(-k - 1, d2);
	i64 r2 = floordiv(n1 * d1 - 1 - k, d2);
	i64 ans = 0;
	ans += rangesum(max(r1 + 1, 0ll), min(r2, n2 - 1), d2, k , d1);
	ans += max(n2 - max(r2 + 1, 0ll), 0ll) * n1;
	return ans;
}

i64 posl[maxN], posr[maxN];

i64 count(i64 K) {
	// find sequence >K
	i64 sl = 0;
	cnt[kW] = 1;
	vector<i64> v;
	for (int i = 1; i <= kW; i++) {
		posl[i] = sl;
		sl += cnt[i] * i;
		posr[i] = sl - i;
	}

	int lpos = 1;
	i64 csum = 0;
	i64 ans = 0;
	for (int i = 1; i <= kW; i++) {
		if (cnt[i] == 0) continue;
		while (posr[lpos] < posl[i] - K) {
			csum += cnt[lpos];
			lpos++;
		}
		ans += csum * cnt[i];
		for (int j = lpos; j <= kW; j++) {
			if (posl[j] >= posr[i] - K) break;
			ans += calcK(posl[j], j, cnt[j], posl[i], i, cnt[i], K);
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		g[0][i] = a[i];
	}
	for (int i = 1; i <= 17; i++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			g[i][j] = gcd(g[i - 1][j], g[i - 1][j + (1 << (i - 1))]);
		}
	}
	for (int i = 2; i <= n; i++) f[i] = f[i >> 1] + 1;
	auto  query = [&](int l, int r) {
		int d = f[(r - l + 1)];
		return gcd(g[d][l], g[d][r - (1 << d) + 1]);
	};
	for (int i = 1; i <= n; i++) {
		int d1 = a[i], d2 = query(i, n);
		int pos = i;
		while (1) {
			if (d1 == d2) {
				cnt[d1] += n - pos + 1;
				break;
			} else {
				int l = pos, r = n;
				while (l + 1 < r) {
					int mid = (l + r) >> 1;
					if (query(i, mid) == d1) l = mid;
					else r = mid;
				}
				cnt[d1] += l - pos + 1;
				pos = l + 1;
				d1 = query(i, pos);
			}
		}
	}
	i64 totnum = (i64)n * (n + 1) / 2;
	totnum = totnum * (totnum + 1) / 2;
	i64 midc = (totnum - 1) / 2;
	i64 l = 0, r = 1ll << 60;
	while (l + 1 < r) {
		i64 mid = (l + r) >> 1;
		if (totnum - count(mid) <= midc) l = mid;
		else r = mid;
	}
	printf("%lld\n", r);
}