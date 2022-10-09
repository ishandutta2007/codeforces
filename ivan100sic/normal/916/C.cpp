#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool prost(int x) {
	if (x < 2)
		return false;
	for (int i=2; i*i<=x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;

	basic_string<tuple<int, int, int>> sol;

	for (int i=n; i>2; i--) {
		sol += {1, i, 2};
	}

	int p = (n-2)*2 + 1, w = 1;
	while (!prost(p))
		p++, w++;
	sol += {1, 2, w};

	m -= n-1;

	for (int i=2; i<=n && m > 0; i++) {
		for (int j=i+1; j<=n && m > 0; j++) {
			sol += {i, j, 1000000000};
			m--;
		}
	}

	cout << "2 " << p << '\n';
	for (auto [x, y, z] : sol)
		cout << x << ' ' << y << ' ' << z << '\n';
}