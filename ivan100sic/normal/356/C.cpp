#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[5], lj;

int a[5];

int earthmover() {
	int z = 0;
	for (int i=0; i<4; i++) {
		z += abs(a[i]);
		a[i+1] += a[i];
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		lj += x;
		c[x]++;
	}

	int sol = 1231231231;

	// broj praznih kupea
	for (int p=0; p<=n; p++) {
		int tri, cetri;
		// 3*tri + 4*cetri = lj
		// tri + cetri = n-p
		tri = 4*(n-p) - lj;
		cetri = lj - 3*(n-p);

		if (tri < 0 || cetri < 0 || tri > n || cetri > n)
			continue;

		for (int i=0; i<4; i++)
			a[i] = c[i];
		a[0] -= p;
		a[3] -= tri;
		a[4] -= cetri;
		sol = min(sol, earthmover() / 2);
	}

	if (sol == 1231231231)
		sol = -1;
	cout << sol << '\n';
}