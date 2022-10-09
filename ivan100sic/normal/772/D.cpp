#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 1'000'000;

int n;
int c[H];
int d[H];
int s[H], s2[H];
int p[H];
int pw2[H+1];

const int mod = 1'000'000'007;

void ad(int& x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

void run_up(int* a) {
	for (int q=1; q<H; q*=10) {
		for (int i=H-1; i>=0; i--) {
			if (i/q%10 < 9) {
				ad(a[i], a[i+q]);
			}
		}
	}
}

void run_down(int* a) {
	for (int q=1; q<H; q*=10) {
		for (int i=0; i<H; i++) {
			if (i/q%10 < 9) {
				ad(a[i], mod-a[i+q]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pw2[0] = 1;
	for (int i=1; i<=H; i++) {
		ad(pw2[i], pw2[i-1]);
		ad(pw2[i], pw2[i-1]);
	}

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	copy(c, c+H, d);

	run_up(d);
	for (int i=0; i<H; i++) {
		s[i] = 1ll*i*c[i] % mod;
		s2[i] = 1ll*i*i*c[i] % mod;
	}
	run_up(s);
	run_up(s2);

	for (int i=0; i<H; i++) {
		if (d[i] == 1)
			p[i] = s2[i];
		else if (d[i] >= 2)
			p[i] = pw2[d[i] - 2] * (s[i]*1ll*s[i] % mod + s2[i]) % mod;
	}

	run_down(p);
	ll z = 0;
	for (int i=0; i<H; i++)
		z ^= ll(i) * p[i];
	cout << z << '\n';
}