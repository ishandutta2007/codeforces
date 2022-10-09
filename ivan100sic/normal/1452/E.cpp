// Retired?
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k, w;
short u[2005][2005];

int l[2005], r[2005];

void rd() {
	cin >> n >> m >> k;
	for (int i=0; i<m; i++) cin >> l[i] >> r[i];
}

void gen() {
	n = m = 2000;
	k = 100;

	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> g(1, n);
	for (int i=0; i<m; i++) {
		l[i] = g(eng);
		r[i] = g(eng);
		if (r[i] < l[i]) {
			swap(l[i], r[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	// gen();
	rd();

	int w = n-k+1;
	for (int i=1; i<=w; i++) {
		for (int j=0; j<m; j++) {
			int q = min(r[j], i+k-1) - max(l[j], i) + 1;
			q = max(q, 0);
			u[i][j] = q;
		}
	}

	int sol = 0;

	for (int i=1; i<=w; i++) {
		for (int j=i; j<=w; j++) {
			int s = 0;
			for (int k=0; k<m; k++) {
				s += max(u[i][k], u[j][k]);
			}
			sol = max(sol, s);
		}
	}

	cout << sol << '\n';
}