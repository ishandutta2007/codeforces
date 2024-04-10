#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

const int MOD = 1'000'000'007;

int pw(int a, int b) {
	if (b == 0) {
		return 1;
	}
	int t = pw(a, b/2);
	t = t * 1ll * t % MOD;
	if (b & 1) {
		t = t * 1ll * a % MOD;
	}
	return t;
}

int inv(int x) {
	return pw(x, MOD-2);
}

int fac[200005], finv[200005];

int bin(int a, int b) {
	return fac[a+b] * 1ll * finv[a] % MOD * finv[b] % MOD;
}

int altbin(int items, int places) {
	return bin(places-1, items);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int f, w, h;

	fac[0] = 1;
	finv[0] = 1;
	for (int i=1; i<200005; i++) {
		fac[i] = fac[i-1] * 1ll * i % MOD;
		finv[i] = inv(fac[i]);
	}

	cin >> f >> w >> h;

	int q = bin(f, w);
	int p = 0;


	if (1) {
		if (w == 0) {
			// svi arrangementi su dobri jer nema wine stekova
			cout << 1;
			return 0;
		}
	}

	for (int k=1; k<=w; k++) {
		int wrem = w - k*(h+1);
		if (wrem < 0) {
			break;
		}

		int frem = f - (k - 1);
		if (frem < 0) {
			break;
		}

		int t = altbin(wrem, k) * 1ll * altbin(frem, k+1) % MOD;

		p += t;
		if (p >= MOD) {
			p -= MOD;
		}
	}

	/*
	cerr << finv[0] << '\n';
	cerr << p << ' ' << q << '\n';
	*/
	
	cout << (p * 1ll * inv(q) % MOD);

}