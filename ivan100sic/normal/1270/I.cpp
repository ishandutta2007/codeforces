#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef float realt;
typedef complex<realt> cd;
const realt pi = acos(realt(-1));

int bitrev(int x, int k) {
	int y = 0;
	for (int i=0; i<k; i++) {
		y = (y << 1) ^ (x & 1);
		x >>= 1;
	}
	return y;
}

void fft(vector<cd>& a, int n, int dir) {
	int k = 31 - __builtin_clz(n);
	for (int i=0; i<n; i++) {
		int j = bitrev(i, k);
		if (i < j)
			swap(a[i], a[j]);
	}
	for (int h=1; h<n; h<<=1) {
		cd base = exp(cd(0, dir*pi/h));
		for (int i=0; i<n; i+=2*h) {
			cd w = 1;
			for (int j=i; j<i+h; j++) {
				cd u = a[j];
				cd v = a[j+h] * w;
				w *= base;
				a[j] = u + v;
				a[j+h] = u - v;
			}
		}
	}
}

vector<vector<cd>> fft2d(const vector<vector<cd>>& s, int n, int dir) {
	auto a = s;
	for (auto& b : a)
		fft(b, n, dir);

	for (int i=0; i<n; i++) {
		vector<cd> b(n);
		for (int j=0; j<n; j++)
			b[j] = a[j][i];
		fft(b, n, dir);
		for (int j=0; j<n; j++)
			a[j][i] = b[j];
	}

	return a;
}

int n, m;
ll a[512][512], c[512][512];
vector<pair<int, int>> f;
bitset<512> b[512], bt[512];

void dizi_slow() {
	b[0][0] = 1;
	bitset<512> mask;
	for (int i=0; i<n; i++)
		mask[i] = 1;
	for (int i=1; i<n; i++) {
		memset(bt, 0, sizeof bt);
		for (auto [x, y] : f)
			for (int j=0; j<n; j++)
				bt[(j+x)&m] ^= (b[j] << y) | (b[j] >> (n - y));
		for (int j=0; j<n; j++)
			bt[j] &= mask;
		memcpy(b, bt, sizeof bt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	n = 1<<n;
	m = n - 1;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> a[i][j];
	int fs;
	cin >> fs;
	while (fs--) {
		int x, y;
		cin >> x >> y;
		f.emplace_back(x, y);
	}

	dizi_slow();

	vector<vector<cd>> btf(n, vector<cd>(n));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			btf[i][j] = b[i][j];

	btf = fft2d(btf, n, 1);

	for (int e=0; e<30; e++) {
		vector<vector<cd>> a1(n, vector<cd>(n));
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				a1[i][j] = cd((a[i][j] >> (2*e)) & 1, (a[i][j] >> (2*e+1)) & 1);
		a1 = fft2d(a1, n, 1);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				a1[i][j] = a1[i][j] * btf[i][j];
		a1 = fft2d(a1, n, -1);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				c[i][j] ^= (1 & (ll)round(a1[i][j].real()/n/n)) << (2*e),
				c[i][j] ^= (1 & (ll)round(a1[i][j].imag()/n/n)) << (2*e+1);
	}

	int z = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			z += !!c[i][j];
	cout << z << '\n';
}