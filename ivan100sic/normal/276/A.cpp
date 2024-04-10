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

	int n, k;
	cin >> n >> k;
	ll sol = -1123123123123123123ll;
	while (n--) {
		ll f, t;
		cin >> f >> t;
		if (t > k)
			sol = max(sol, f-(t-k));
		else
			sol = max(sol, f);
	}
	cout << sol << '\n';
}