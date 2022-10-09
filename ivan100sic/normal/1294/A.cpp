#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		int q = (a+b+c+n);
		if (q % 3) {
			cout << "NO\n";
			continue;
		}
		q /= 3;
		if (max({a, b, c}) > q) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}