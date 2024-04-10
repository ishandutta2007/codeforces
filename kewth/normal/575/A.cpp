#if 0
2020.01.28

 m = 0 
 m 



#endif
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<ll, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

struct Matrix {
	ll v[2][2];
	Matrix(int x = 0) {
		v[0][0] = v[1][1] = x;
		v[1][0] = v[0][1] = 0;
	}
};

int mod;
inline Matrix operator * (Matrix a, Matrix b) {
	Matrix c;
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j < 2; j ++) {
			for(int k = 0; k < 2; k ++)
				c.v[i][j] += a.v[i][k] * b.v[k][j];
			c.v[i][j] %= mod;
		}
	return c;
}

const int maxn = 50005;
int s[maxn << 1];
par diff[maxn];
Matrix seg[maxn << 2];

Matrix make(int a, int b) {
	Matrix m;
	m.v[0][0] = 0;
	m.v[0][1] = a;
	m.v[1][0] = 1;
	m.v[1][1] = b;
	return m;
}

int n;
void build(int now, int L, int R) {
	if(L == R) return seg[now] = make(s[L + n - 1], s[L]), void();
	int M = (L + R) >> 1;
	build(now << 1, L, M);
	build(now << 1 | 1, M + 1, R);
	seg[now] = seg[now << 1] * seg[now << 1 | 1];
}

Matrix query(int now, int L, int R, int l, int r) {
	if(r < L or l > R) return 1;
	if(l <= L and R <= r) return seg[now];
	int M = (L + R) >> 1;
	return query(now << 1, L, M, l, r) * query(now << 1 | 1, M + 1, R, l, r);
}

Matrix power(Matrix x, ll k) {
	Matrix res = 1;
	while(k) {
		if(k & 1) res = res * x;
		x = x * x;
		k >>= 1;
	}
	return res;
}

Matrix mul(ll l, ll r) {
	if(l > r) return 1;
	if(l / n == r / n) return query(1, 0, n - 1, l % n, r % n);
	return
		query(1, 0, n - 1, l % n, n - 1) *
		power(seg[1], r / n - l / n - 1) *
		query(1, 0, n - 1, 0, r % n);
}

void shit(Matrix test) {
	debug("%lld %lld %lld %lld\n",
			test.v[0][0],
			test.v[0][1],
			test.v[1][0],
			test.v[1][1]);
}

int main() {
	ll k = read;
	mod = read;
	n = read;

	if(mod == 1) return puts("0"), 0;
	if(k == 0) return puts("0"), 0;
	if(k == 1) return puts("1"), 0;

	for(int i = 0; i < n; i ++)
		s[n + i] = s[i] = read;

	build(1, 0, n - 1);

	int m = read;
	for(int i = 1; i <= m; i ++) {
		diff[i].first = read;
		diff[i].second = read;
	}

	diff[0] = par(1, s[1]);
	std::sort(diff + 1, diff + m + 1);
	while(diff[m].first >= k)
		-- m;

	Matrix F = 0;
	F.v[0][0] = 1;
	F.v[0][1] = s[1];

	for(int i = 1; i <= m; i ++)
		if(diff[i - 1].first == diff[i].first - 1)
			F = F * make(diff[i - 1].second, diff[i].second);
		else
			F = F * make(diff[i - 1].second, s[(diff[i - 1].first + 1) % n]) *
				mul(diff[i - 1].first + 2, diff[i].first - 1) *
				make(s[(diff[i].first - 1) % n], diff[i].second);

	// shit(make(diff[m].second, s[(diff[m].first + 1) % n]));
	// shit(F * make(diff[m].second, s[(diff[m].first + 1) % n]));
	// shit(mul(diff[m].first + 2, k));
	// shit(seg[1]);

	F = F * make(diff[m].second, s[(diff[m].first + 1) % n]) *
		mul(diff[m].first + 2, k);

	printf("%lld\n", F.v[0][0] % mod);
}