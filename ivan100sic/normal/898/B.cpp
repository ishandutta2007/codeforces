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

	ll n, a, b;
	cin >> n >> a >> b;
	for (int i=0; i<=n; i++) {
		if ((n - i*a) >= 0 && (n - i*a) % b == 0) {
			cout << "YES\n";
			cout << i << ' ' << (n - i*a) / b << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}