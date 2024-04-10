#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

struct frac {
	i64 a, b;
};

inline bool operator < (const frac &a, const frac &b) {
	return a.a * b.b > b.a * a.b;
}

inline bool operator == (const frac &a, const frac &b) {
	return a.a * b.b == b.a * a.b;
}

const int mxn = 1 << 20;

int n, m;
int a[mxn];
std::vector <int> b[mxn];
std::vector <frac> vec;

struct SegmentTree {
	int sz;
	int sum[mxn << 1], pre[mxn << 1];

	void init(int _n) {
		for (sz = 1; sz < _n; sz <<= 1);
		rep(i, sz << 1) sum[i] = pre[i] = 0;
	}

	inline void pushup(int x) {
		sum[x] = sum[x << 1] + sum[x << 1 | 1];
		pre[x] = std::min(pre[x << 1], sum[x << 1] + pre[x << 1 | 1]);
	}

	inline void update(int x, int v) {
		x += sz;
		sum[x] += v;
		pre[x] += v;
		for (; x >>= 1; pushup(x));
	}
} seg;

void Main() {
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	vec.clear();
	rep(i, n) vec.push_back({a[i], 1});
	rep(i, m) {
		int k; scanf("%d", &k);
		b[i].resize(k);
		rep(j, k) scanf("%d", &b[i][j]);
		frac sum = {0, k};
		rep(j, k) sum.a += b[i][j];
		vec.push_back(sum);
		rep(j, k) {
			frac temp = sum;
			temp.a -= b[i][j];
			temp.b -= 1;
			vec.push_back(temp);
		}
	}
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	// rep(i, vec.size()) eprintf("%lld/%lld\n", vec[i].a, vec[i].b);
	auto id = [&] (frac x) { return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin(); };
	seg.init(vec.size());
	rep(i, n) seg.update(id({a[i], 1}), +1);
	rep(i, m) {
		frac sum = {0, b[i].size()};
		rep(j, b[i].size()) sum.a += b[i][j];
		seg.update(id(sum), -1);
	}
	rep(i, m) {
		frac sum = {0, b[i].size()};
		rep(j, b[i].size()) sum.a += b[i][j];
		seg.update(id(sum), +1);
		rep(j, b[i].size()) {
			frac temp = sum;
			temp.a -= b[i][j];
			temp.b -= 1;
			seg.update(id(temp), -1);
			putchar(seg.pre[1] >= 0 ? '1' : '0');
			seg.update(id(temp), +1);
		}
		seg.update(id(sum), -1);
	}
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}