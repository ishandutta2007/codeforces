#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef unsigned long long i64;

const i64 mod = 1e13;

i64 mul(i64 x, i64 y) {
	const int B = 1000000;
	int x0 = x / B, x1 = x % B;
	int y0 = y / B, y1 = y % B;
	i64 ans = 0;
	(ans += 1LL * x0 * y0 % mod * B % mod * B % mod) %= mod;
	(ans += 1LL * x0 * y1 % mod * B % mod) %= mod;
	(ans += 1LL * x1 * y0 % mod * B % mod) %= mod;
	(ans += 1LL * x1 * y1 % mod) %= mod;
	return ans;
}

struct Mat {
	i64 a[2][2];

	Mat() { memset(a, 0, sizeof(a)); }

	Mat operator * (const Mat &oth) const {
		Mat ans;
		rep(i, 2) rep(j, 2) rep(k, 2) (ans.a[i][k] += mul(a[i][j], oth.a[j][k])) %= mod;
		return ans;
	}
};

Mat qpow(Mat x, i64 n) {
	Mat ans;
	ans.a[0][0] = ans.a[1][1] = 1;
	for (; n; n >>= 1, x = x * x) if (n & 1) ans = ans * x;
	return ans;
}

Mat trans;

i64 get(i64 n) {
	Mat x = qpow(trans, n);
	return x.a[1][0];
}

i64 tar;

int main() {
	scanf("%llu", &tar);
	trans.a[0][0] = 1;
	trans.a[0][1] = 1;
	trans.a[1][0] = 1;
	trans.a[1][1] = 0;
	std::vector <i64> cand;
	for (int i = 0; i < 1500; ++ i) {
		if (get(i) % 1000 == tar % 1000) {
			cand.push_back(i);
		}
	}
	for (auto x : cand) eprintf("%llu\n", x);
	for (int i = 3; i < 13; ++ i) {
		eprintf("!! %d\n", i);
		i64 nw = 15;
		rep(j, i - 1) nw *= 10;
		i64 nwmod = 10;
		rep(j, i) nwmod *= 10;
		std::vector <i64> ncand;
		for (int x = 0; x < 10; ++ x) {
			rep(j, cand.size()) {
				if (get(x * nw + cand[j]) % nwmod == tar % nwmod) {
					ncand.push_back(x * nw + cand[j]);
				}
			}
		}
		cand = ncand;
		for (auto x : cand) eprintf("%llu\n", x);
	}
	if (cand.empty()) printf("-1\n");
	else printf("%llu\n", cand[0]);
	return 0;
}