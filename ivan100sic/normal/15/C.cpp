#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll e(ll x) {
	if (x % 4 == 0)
		return x;
	else if (x % 4 == 1)
		return 1;
	else if (x % 4 == 2)
		return x+1;
	else
		return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	ll z = 0;
	while (n--) {
		ll x, m;
		cin >> x >> m;
		z ^= e(x+m-1) ^ e(x-1);
	}
	cout << (z ? "tolik" : "bolik") << '\n';
}