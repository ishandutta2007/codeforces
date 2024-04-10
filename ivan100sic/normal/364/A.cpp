#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int aa, n;
string s;

int z[4005];
int c[40005];

// plasim omladinu!

namespace fft {
	const int mod = 167772161;
	const int root = 243;
	const int root_inv = 114609789;

	void fft(vector<int>& a, bool inv = false) {
		// bitswap
		int N = a.size();
		int n = 31 - __builtin_clz(N);
		for (int i=0; i<N; i++) {
			int j = 0, t = i;
			for (int k=0; k<n; k++) {
				j = (j << 1) | (t & 1);
				t >>= 1;
			}
			if (j < i)
				swap(a[i], a[j]);
		}

		for (int h=1, g=0; h<N; h<<=1, g++) {

			int w1 = inv ? root_inv : root;
			for (int t=g; t<24; t++)
				w1 = w1*1ll*w1 % mod;

			for (int i=0; i<N; i+=h+h) {
				for (int j=i, w=1; j<i+h; j++, w=w*1ll*w1%mod) {
					int x = a[j];
					int y = a[j + h] * 1ll * w % mod;
					a[j] = x + y;
					if (a[j] >= mod)
						a[j] -= mod;
					a[j + h] = x - y;
					if (a[j + h] < 0)
						a[j + h] += mod;
				}
			}
		}
		
		if (inv) {
			const int inv2 = (mod + 1) >> 1;
			int Ninv = 1;
			for (int i=0; i<n; i++)
				Ninv = Ninv * 1ll * inv2 % mod;
			for (int& x : a)
				x = x * 1ll * Ninv % mod;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> aa >> s;
	n = s.size();

	if (aa == 0) {
		ll nule = 0;
		int run = 0;
		for (char x : s) {
			if (x == '0')
				run++;
			else
				run = 0;
			nule += run;
		}
		cout << nule * (n * (n+1ll) - nule);
		return 0;
	}

	for (int i=0; i<n; i++) {
		z[i+1] = z[i] + s[i] - 48;
	}

	vector<int> a(131072, 0), b(131072, 0);

	for (int i=0; i<=n; i++) {
		a[z[i]]++;
		b[36666 - z[i]]++;
	}

	fft::fft(a);
	fft::fft(b);

	for (int i=0; i<131072; i++)
		a[i] = a[i] * 1ll * b[i] % fft::mod;

	fft::fft(a, true);

	for (int i=0; i<=9*n; i++) {
		c[i] = a[36666 - i];
	}

	ll sol = 0;

	for (int i=1; i<=9*n; i++) {
		if (aa % i == 0 && aa / i <= 9*n) {
			sol += c[i] * 1ll * c[aa / i];
		}
	}

	cout << sol << '\n';
}