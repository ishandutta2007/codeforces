#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[200005], z[200005], n;

int init_val() {
	int z = 0;
	for (int i=1; i<=100000; i++) {
		int d = 0, t = i;
		while (t > 1) {
			t >>= 1;
			d++;
		}
		z += d * c[i];
	}
	return z;
}

int sol;

void solve(int x, int val) {
	if (x > 100000)
		return;
	sol = min(sol, val);
	for (int y=2*x; y<2*x+2; y++) {
		int tmp = val + (n-z[y]) - z[y];
		if (n-z[y] && y%2)
			continue;
		solve(y, tmp);
	}
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
		c[x]++;
		for (int y=x; y>0; y>>=1)
			z[y]++;
	}
	sol = init_val();
	solve(1, sol);
	cout << sol << '\n';
}