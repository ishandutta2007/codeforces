#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ull f[55], br[55];

void dp() {
	f[0] = f[1] = br[1] = 1;
	for (int i=2; i<=22; i++) {
		f[i] = f[i-1] * i;
		br[i] = f[i-2];
		for (int j=1; j<i; j++)
			br[i] += f[max(0, j-2)] * br[i-j];
		// cerr << i << ' ' << br[i] << '\n';
	}
	for (int i=20; i<=50; i++)
		f[i] = 2e18;
	for (int i=23; i<=50; i++)
		br[i] = 2e18;
}

basic_string<int> cikl(int n, ull k) {
	basic_string<int> a(n, -1), ainv(n, -1);
	a[0] = n-1;
	ainv[n-1] = 0;
	for (int i=1; i<n; i++) {
		string moze(n, 1);
		for (int x : a)
			if (x != -1)
				moze[x] = 0;
		if (i < n-1) {
			for (int x = i; x != -1; x = ainv[x])
				moze[x] = 0;
		}
			

		ull q = f[max(n-i-2, 0)];
		int r = k / q;
		k %= q;
		int v = 0;
		// cerr << "step " << i << ' ' << r << ' ' << q << '\n';
		for (int j=0; j<n; j++) {
			if (moze[j]) {
				r--;
				if (r == -1) {
					v = j;
					break;
				}
			}
		}
		a[i] = v;
		ainv[v] = i;
	}
	return a;
}

basic_string<int> resi(int n, ull k) {
	ull l = 0;
	for (int i=1; i<n; i++) {
		ull r = l + f[max(0, i-2)] * br[n-i];
		if (k < r) {
			ull b = k - l;
			ull p = b / br[n-i];
			ull q = b % br[n-i];
			auto a1 = cikl(i, p);
			auto a2 = resi(n - i, q);
			for (int& x : a2)
				x += a1.size();
			return a1 + a2;
		}
		l = r;
	}
	return cikl(n, k-l);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	dp();

	/*for (int i=0; i<24; i++) {
		for (int x : cikl(6, i))
			cerr << x << ' ';
		cerr << '\n';
	}*/

	int t;
	cin >> t;
	while (t--) {
		int n;
		ull k;
		cin >> n >> k;
		if (n <= 22 && k > br[n]) {
			cout << "-1\n";
			continue;
		} else {
			auto v = resi(n, k-1);
			for (int x : v)
				cout << x + 1 << ' ';
			cout << '\n';
		}
	}
}