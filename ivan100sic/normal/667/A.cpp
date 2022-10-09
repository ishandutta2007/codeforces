#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = 3.141592653589879323;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ld d, h, v, e;
	cin >> d >> h >> v >> e;

	v /= d * d * PI / 4;

	if (v - e < 1e-9) {
		cout << "NO\n";
	} else {
		cout.precision(20);
		cout << "YES\n";
		cout << fixed << h / (v - e) << '\n';
	}
}