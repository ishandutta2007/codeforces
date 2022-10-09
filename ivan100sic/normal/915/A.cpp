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
	int sol = 12312323;
	while (n--) {
		int x;
		cin >> x;
		if (k % x == 0)
			sol = min(sol, k / x);
	}
	cout << sol << '\n';
}