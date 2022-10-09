#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <array>
using namespace std;

const int MOD = 1'000'000'007;

const int HI = 16;

typedef array<long long, HI> vec;
typedef array<vec, HI> mat;

mat mul(mat a, mat b) {
	mat c;
	for (int i=0; i<HI; i++) {
		for (int j=0; j<HI; j++) {
			c[i][j] = 0;
			for (int k=0; k<HI; k++) {
				c[i][j] = (a[i][k] * b[k][j] + c[i][j]) % MOD;
			}
		}
	}
	return c;
}

vec mul(vec b, mat a) {
	vec c;
	for (int j=0; j<HI; j++) {
		c[j] = 0;
		for (int k=0; k<HI; k++) {
			c[j] = (b[k] * a[k][j] + c[j]) % MOD;
		}
	}
	return c;
}

mat ident() {
	mat c;
	for (int i=0; i<HI; i++) {
		for (int j=0; j<HI; j++) {
			c[i][j] = 0;
			if (i == j) {
				c[i][j] = 1;
			}
		}
	}
	return c;
}

mat daj(int h) {
	mat c;
	for (int i=0; i<HI; i++) {
		for (int j=0; j<HI; j++) {
			c[i][j] = 0;
			if (abs(i-j) <= 1 && i <= h && j <= h) {
				c[i][j] = 1;
			}
		}
	}
	return c;
}

vec origin() {
	vec b;
	for (int i=0; i<HI; i++) {
		b[i] = 0;
		if (i == 0) b[i] = 1;
	}
	return b;
}

void clip(vec& b, int h) {
	for (int i=h+1; i<HI; i++) {
		b[i] = 0;
	}
}

mat raise(mat a, long long b) {
	
	if (b == 0) {
		return ident();
	}
	mat t = raise(a, b/2);
	t = mul(t, t);
	if (b % 2) {
		t = mul(t, a);
	}
	return t;
}

long long total(const vec& b) {
	long long t = 0;
	for (int i=0; i<HI; i++) {
		t = (t + b[i]) % MOD;
	}
}

void debug(mat a) {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			cerr << a[i][j] << ' ';
		}
		cerr << '\n';
	}
}

void debug(vec a) {
	for (int i=0; i<4; i++) {
		cerr << a[i] << ' ';
	}
	cerr << '\n';
}

long long a[105], b[105], c[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	long long k;
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	b[n] = k;

	vec v = origin();

	for (int i=1; i<=n; i++) {
		mat pw = raise(daj(c[i]), b[i] - a[i]);
		// debug(pw);

		v = mul(v, pw);

		// debug(v);

		if (i < n) {
			clip(v, c[i+1]);
		} else {
			clip(v, c[i]);
		}

		// debug(v);
	}

	cout << v[0];

}