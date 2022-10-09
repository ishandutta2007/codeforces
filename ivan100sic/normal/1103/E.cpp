#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct weird_quaternion {
	ull u, i, j, k;

	static weird_quaternion powers[10];

	weird_quaternion() {
		u = i = j = k = 0;
	}

	weird_quaternion(ull x) {
		i = j = k = 0;
		u = x;
	}

	weird_quaternion(int x, int y) {
		*this = powers[x];
	}

	weird_quaternion operator* (const weird_quaternion& b) const {
		weird_quaternion tmp;
		// do smth
		ull e = i*b.k + j*b.j + k*b.i;

		tmp.u = u*b.u - j*b.k - k*b.j - e;
		tmp.i = u*b.i + i*b.u - k*b.k + e;
		tmp.j = u*b.j + i*b.i + j*b.u - e;
		tmp.k = u*b.k + i*b.j + j*b.i + k*b.u + e;

		return tmp;
	}

	weird_quaternion& operator+= (const weird_quaternion& b) {
		u += b.u;
		i += b.i;
		j += b.j;
		k += b.k;
		return *this;
	}

	void debug() const {
		cerr << u << ' ' << i << ' ' << j << ' ' << k << '\n';
	}
};

weird_quaternion weird_quaternion::powers[10];

weird_quaternion a_part[10], c_result[10];

void dft1d(bool inverse) {
	fill(c_result, c_result+10, weird_quaternion());
	for (int i=0; i<10; i++) {
		weird_quaternion w(inverse ? (10-i)%10 : i, 1), wj = 1, tmp;
		for (int j=0; j<10; j++) {
			tmp += a_part[j] * wj;
			wj = wj * w;
		}
		c_result[i] = tmp;
	}
}

const int step[5] = {1, 10, 100, 1000, 10000};
char done[100000];

const ull inv5 = 14757395258967641293ull;

void dft5d(vector<weird_quaternion>& a, bool inverse) {
	for (int dim=0; dim<5; dim++) {
		memset(done, 0, sizeof(done));
		const int step = ::step[dim];
		for (int start=0; start<100000; start++) {
			if (!done[start]) {
				for (int j=0; j<10; j++) {
					int x = start + j*step;
					done[x] = 1;
					a_part[j] = a[x];
				}
				dft1d(inverse);
				for (int j=0; j<10; j++) {
					int x = start + j*step;
					a[x] = c_result[j];
				}
			}
		}
	}
}

weird_quaternion stepen(weird_quaternion a, int k) {
	if (k == 1)
		return a;
	auto b = stepen(a, k >> 1);
	b = b * b;
	if (k & 1)
		b = b * a;
	return b;
}

void podeli100k(ull& x) {
	x >>= 5;
	x = (x * 382401004647999005ull) & ((1ull << 58) - 1);
}

vector<weird_quaternion> stepen(vector<weird_quaternion> a, int k) {
	dft5d(a, false);
	for (int i=0; i<100000; i++)
		a[i] = stepen(a[i], k);
	dft5d(a, true);
	// podeli sa 100000
	for (int i=0; i<100000; i++)
		podeli100k(a[i].u);

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// powers

	weird_quaternion::powers[0].u = 1;
	weird_quaternion::powers[1].i = 1;
	for (int i=2; i<10; i++)
		weird_quaternion::powers[i] = stepen(weird_quaternion::powers[1], i);


	// main

	int n;
	cin >> n;

	vector<int> c(100000, 0);
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	vector<weird_quaternion> d(100000);
	for (int i=0; i<100000; i++)
		d[i] = weird_quaternion(c[i]);

	d = stepen(d, n);
	for (int i=0; i<n; i++)
		cout << d[i].u << '\n';
}