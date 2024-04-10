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

	ll a, b, c;
	cin >> a >> b >> c;
	bool ok;
	if (c > 0) {
		ok = (b >= a && (b-a) % c == 0);
	} else if (c == 0) {
		ok = b == a;
	} else if (c < 0) {
		ok = (b <= a && (a-b) % (-c) == 0);
	}
	cout << (ok ? "YES\n" : "NO\n");
}