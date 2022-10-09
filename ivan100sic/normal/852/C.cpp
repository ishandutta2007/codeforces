#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std;

struct broj {
	int id;
	long double x;

	bool operator< (const broj& other) const {
		return x < other.x;
	}
};

int n;
int p[50005];
int sol[50005];

broj a[50005];
typedef complex<long double> cmplx;

long double det(cmplx a, cmplx b, cmplx c) {
	return a.real() * b.imag() + b.real() * c.imag() + c.real() * a.imag()
		- a.imag() * b.real() - b.imag() * c.real() - c.imag() * a.real();
}

long double ldabs(long double x) {
	if (x > 0) {
		return x;
	}
	return -x;
}

long double izracunaj(int a, int b) {
	
	const long double pitaa = 3.14159265358979323;

	cmplx p = { (long double)a, 0 };
	cmplx m = { (long double)n, 0 };
	cmplx unutra = pitaa / n * cmplx(0, (long double)1);
	cmplx dr = exp(unutra);
	
	cmplx k = m + m * dr + dr * dr * cmplx((long double)b, 0);

	cmplx u = m;
	cmplx v = m + dr * cmplx((long double)1, 0);

	return ldabs(det(p, k, v)) - ldabs(det(p, k, u));
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
	}

	for (int i = 0; i < n; i++) {
		a[i].x = izracunaj(p[i], p[(i + 1) % n]);
		a[i].id = i;
		// fprintf(stderr, "%.14f\n", (double)a[i].x);
	}

	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		sol[a[i].id] = i;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", sol[i]);
	}

	{
		int _;
		scanf("%d", &_);
	}
}