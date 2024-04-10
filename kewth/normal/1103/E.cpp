#if 0
2020.05.06


#endif
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef unsigned long long ull;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 100000;
struct num {
	ull x[5];
	num () { memset(x, 0, sizeof x); }
	ull con () {
		ull k = x[4];
		x[0] -= k;
		x[2] -= k;
		x[4] -= k;
		x[1] += k;
		x[3] += k;
		return x[0];
	}
};
num operator * (num a, num b) {
	num c;
	for (int i = 0; i < 5; i ++)
		for (int j = 0; j < 5; j ++)
			i + j < 5 ?
				c.x[i + j] += a.x[i] * b.x[j] :
				c.x[i + j - 5] -= a.x[i] * b.x[j];
	return c;
}
num operator + (num a, num b) {
	num c;
	for (int i = 0; i < 5; i ++) c.x[i] = a.x[i] + b.x[i];
	return c;
}
num operator - (num a, num b) {
	num c;
	for (int i = 0; i < 5; i ++) c.x[i] = a.x[i] - b.x[i];
	return c;
}
num f[maxn], w[20];
ull ans[maxn];

void FFT (int N, int t) {
	for (int m = 1; m < N; m *= 10)
		for (int i = 0; i < N; i += m * 10)
			for (int j = i; j < i + m; j ++) {
				num a[10];
				for (int k = 0; k < 10; k ++)
					std::swap(f[j + k * m], a[k]);
				for (int k = 0; k < 10; k ++)
					for (int kk = 0; kk < 10; kk ++)
						f[j + k * m] = f[j + k * m] + a[kk] * w[10 + t * k * kk % 10];
			}
}

int main () {
	for (int k = 0; k < 5; k ++) {
		w[k].x[k] = 1;
		w[k + 5].x[k] = ull(-1);
		w[k + 10].x[k] = 1;
		w[k + 15].x[k] = ull(-1);
	}

	int n = read;
	for (int i = 0; i < n; i ++)
		++ f[read].x[0];

	int N = 100000;

	FFT(N, 1);
	for (int i = 0; i < N; i ++) {
		int k = n;
		num x = f[i];
		f[i] = num();
		f[i].x[0] = 1;
		while (k) {
			if (k & 1)
				f[i] = f[i] * x;
			x = x * x;
			k >>= 1;
		}
	}
	FFT(N, -1);

	for (int i = 0; i < N; i ++)
		ans[i] = f[i].con();
	ull inv5;
	inv5 = 1;
	for (int m = 1; m < N; m *= 10)
		inv5 *= 14757395258967641293llu;
	for (int i = 0; i < N; i ++)
		ans[i] = ans[i] * inv5 << 1 >> 6;

	for (int i = 0; i < n; i ++)
		printf("%llu\n", ans[i]);
}