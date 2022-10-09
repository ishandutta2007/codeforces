#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll ask(int t, int x, int y, int z) {
	cout << t << ' ' << x << ' ' << y << ' ' << z << '\n';
	cout << flush;
	ll r;
	cin >> r;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	int b = 1, c = 2;
	// nadji minimalnu, c

	for (int i=3; i<=n; i++) {
		if (ask(2, b, i, c) < 0)
			c = i;
	}

	vector<ll> dist(n+1);
	for (int i=2; i<=n; i++) {
		if (i == c)
			continue;
		dist[i] = ask(1, b, c, i);
	}

	int d = max_element(dist.begin(), dist.end()) - dist.begin();

	basic_string<int> levo, desno;

	for (int i=2; i<=n; i++) {
		if (i == d)
			continue;
		if (ask(2, b, d, i) < 0)
			levo += i;
		else
			desno += i;
	}

	sort(levo.begin(), levo.end(), [&](int x, int y) {
		return dist[x] < dist[y];
	});

	sort(desno.begin(), desno.end(), [&](int x, int y) {
		return dist[x] > dist[y];
	});

	basic_string<int> sol = {b};
	sol += levo + d + desno;

	cout << "0\n";
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
	cout << flush;
}