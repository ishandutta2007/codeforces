#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int m;
ull n;
vector<int> e[200005];
ull a, b, c;

ull p1(ull n) {
	ull a[4] = {n, n-1, n-2, n-3};
	int c2 = 3, c3 = 1;
	for (int i=0; i<4; i++) {
		while (c2 > 0 && a[i] % 2 == 0) {
			a[i] /= 2;
			c2--;
		}
		while (c3 > 0 && a[i] % 3 == 0) {
			a[i] /= 3;
			c3--;
		}
	}
	return a[0] * a[1] * a[2] * a[3];
}

ull p2(ull n) {
	ull a[4] = {n, n-1, n-1, n-2};
	int c2 = 2, c3 = 1;
	for (int i=0; i<4; i++) {
		while (c2 > 0 && a[i] % 2 == 0) {
			a[i] /= 2;
			c2--;
		}
		while (c3 > 0 && a[i] % 3 == 0) {
			a[i] /= 3;
			c3--;
		}
	}
	return a[0] * a[1] * a[2] * a[3];
}

ull p3(ull n) {
	ull a[4] = {3*n-1, n, n-1, n-2};
	int c2 = 3, c3 = 1;
	for (int i=0; i<4; i++) {
		while (c2 > 0 && a[i] % 2 == 0) {
			a[i] /= 2;
			c2--;
		}
		while (c3 > 0 && a[i] % 3 == 0) {
			a[i] /= 3;
			c3--;
		}
	}
	return a[0] * a[1] * a[2] * a[3];
}

ull junk[200005];

ull pr(ll x) {
	return x*(x-1) / 2;
}

ull izmedju(ull x, ull y) {
	return pr(y) - pr(x);
}

int sus(int x, int y) {
	auto it = lower_bound(e[x].begin(), e[x].end(), y);
	return it != e[x].end() && *it == y;
}

void brutina() {
	int n = ::n;
	ull z[4] = {0, 0, 0, 0};
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				int d = sus(i, j) + sus(j, k) + sus(k, i);
				z[d] += a*i + b*j + c*k;
			}
		}
	}
	for (ull x : z)
		cerr << x << '\n';
	cerr << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> a >> b >> c;
	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	for (ull i=0; i<n; i++)
		sort(e[i].begin(), e[i].end());

	// brutina();

	ull z = p1(n)*a + p2(n)*b + p3(n)*c;

	ull grane = 0;
	for (int i=0; i<(int)n; i++) {
		for (int j : e[i]) {
			if (i < j) {
				grane += (a*i + b*j)*(n-1-j) + c*izmedju(j+1, n);
				grane += (b*i + c*j)*i       + a*izmedju(0, i);
				grane += (a*i + c*j)*(j-i-1) + b*izmedju(i+1, j);
			}
		}
	}

	ull putici = 0;
	for (ull i=0; i<n; i++) {
		ull cn = lower_bound(e[i].begin(), e[i].end(), i) - e[i].begin();
		ull sz = e[i].size();

		// ja sam srednji po vrednosti
		for (ull j=0; j<cn; j++)
			putici += e[i][j] * a * (sz-cn);
		for (ull j=cn; j<sz; j++)
			putici += e[i][j] * c * cn;
		putici += b * i * cn * (sz-cn);

		// ja sam najveci po vrednosti
		for (ull j=0; j<cn; j++)
			putici += e[i][j] * (a*(cn-j-1) + b*j);
		putici += pr(cn)*c*i;

		// ja sam najmanji po vrednosti
		for (ull j=cn; j<sz; j++)
			putici += e[i][j] * (b*(sz-j-1)+c*(j-cn));
		putici += pr(sz-cn)*a*i;
	}

	ull trouglovi = 0;

	for (int i=0; i<(int)n; i++) {
		for (int j : e[i]) {
			if (i >= j)
				continue;

			auto it1 = upper_bound(e[i].begin(), e[i].end(), j);
			auto it2 = lower_bound(e[j].begin(), e[j].end(), j);

			auto kraj = set_intersection(it1, e[i].end(), it2, e[j].end(), junk);

			trouglovi += a * i * (kraj - junk);
			trouglovi += b * j * (kraj - junk);
			trouglovi += c * accumulate(junk, kraj, (ull)0);
		}
	}

	cerr << z << '\n';
	cerr << grane << '\n';
	cerr << putici << '\n';
	cerr << trouglovi << '\n';

	cout << z - grane + putici - trouglovi << '\n';

}