#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int cinv(basic_string<int> a) {
	int n = a.size(), m = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (a[i] > a[j])
				m++;
		}
	}
	return m;
}

bool regularan(basic_string<int> b) {
	int prviplus = -1, zadnjiminus = -1, n = b.size();
	for (int i=0; i<n; i++) {
		if (b[i] > 0) {
			if (prviplus == -1)
				prviplus = i;
		} else if (b[i] < 0) {
			zadnjiminus = i;
		}
	}

	if (prviplus == -1 || zadnjiminus == -1)
		return true;
	return zadnjiminus < prviplus;
}

basic_string<int> brut(basic_string<int> a) {
	int n = a.size();
	basic_string<int> c = a;
	for (int mask=0; mask<(1<<n); mask++) {
		basic_string<int> b = a;
		for (int i=0; i<n; i++)
			if (mask & (1 << i))
				b[i] *= -1;
		if (cinv(b) < cinv(c)) {
			c = b;
		} else if (cinv(b) == cinv(c)) {
			if (regularan(b))
				c = b;
		}
	}
	return c;
}

basic_string<int> ucitaj() {
	int n;
	cin >> n;
	basic_string<int> a(n, 0);
	for (int i=0; i<n; i++)
		cin >> a[i];
	return a;
}

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

basic_string<int> generisi() {
	basic_string<int> a(10, 0);
	iota(a.begin(), a.end(), 1);
	shuffle(a.begin(), a.end(), eng);
	return a;
}

void stampaj(basic_string<int> b, ostream& os = cerr) {
	for (int x : b)
		os << x << ' ';
	os << '\n';
}

basic_string<int> resi(basic_string<int> a) {
	int n = a.size();
	for (int& x : a)
		x = abs(x);
	basic_string<int> b(n, 0);
	basic_string<int> c(n, -123123123);
	iota(b.begin(), b.end(), 0);
	sort(b.begin(), b.end(), [&](int x, int y) {
		return a[x] < a[y];
	});

	for (int i : b) {
		int x = a[i], u = 0;
		for (int j=0; j<n; j++) {
			if (c[j] != -123123123 && abs(c[j]) != x) {
				if (j < i) {
					u++;
				} else {
					u--;
				}
			}
		}

		if (u > 0) {
			c[i] = x;
		} else {
			c[i] = -x;
		}
	}

	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// cerr << cinv({-3, 1, -7, -8, 9, 10, -6, 2, 5, 4}) << '\n';
	// cerr << cinv({-3, -1, -7, -8, 9, 10, -6, 2, 5, 4}) << '\n';
	// cerr << cinv({-3, -1, -7, -8, 9, 10, 6, 2, 5, 4}) << '\n';

	// stampaj(brut(generisi()));

	cout << cinv(resi(ucitaj())) << '\n';

}