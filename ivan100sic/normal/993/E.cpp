#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<ld> cd;

int bitinv(int x) {
	int y = 0;
	for (int i=0; i<19; i++) {
		y <<= 1;
		y |= x & 1;
		x >>= 1;
	}
	return y;
}

const int maxn = 524288;
const ld pi = acos(ld(-1));

void fft(vector<cd>& a, bool inv) {
	for (int i=0; i<maxn; i++) {
		int j = bitinv(i);
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int h=1; h<maxn; h<<=1) {
		cd g = exp(cd(0, inv ? pi/h : -pi/h));
		for (int i=0; i<maxn; i+=2*h) {
			cd w = 1;
			for (int j=i; j<i+h; j++) {
				cd u = a[j], v = a[j+h];
				a[j] = u + v*w;
				a[j+h] = u - v*w;
				w *= g;				
			}
		}
	}

	if (inv) {
		for (int i=0; i<maxn; i++)
			a[i] /= maxn;
	}
}

int n, k, a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a[i+1] = a[i] + (x < k);
	}

	vector<cd> b(maxn);
	vector<cd> c(maxn);
	for (int i=0; i<=n; i++) {
		// cerr << i << ": " << a[i] << '\n';
		b[a[i]] += 1, c[(maxn-a[i]) % maxn] += 1;
	}
	fft(b, false);
	fft(c, false);
	for (int i=0; i<maxn; i++)
		b[i] *= c[i];
	fft(b, true);
	for (int i=0; i<=n; i++) {
		ll x = b[i].real() + 0.5;
		if (!i) x = (x-n-1) / 2;
		cout << x << " \n"[i == n];
	}
}