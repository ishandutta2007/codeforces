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
		ll a, b, n, s;
		cin >> a >> b >> n >> s;
		s -= min(s/n, a) * n;
		s -= min(s, b);
		cout << (s ? "NO\n" : "YES\n");
	}
}