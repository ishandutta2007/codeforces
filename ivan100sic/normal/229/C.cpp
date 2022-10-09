#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	ll sol = 0;
	for (int x=1; x<=n; x++) {
		ll z = e[x].size();
		for (int y : e[x])
			z += e[y].size();
		sol += 2*m-z;
	}

	cout << n*(n-1ll)*(n-2) / 6 - sol/2 << '\n';
}