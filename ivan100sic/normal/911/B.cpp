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

	int n, a, b;
	cin >> n >> a >> b;
	int sol = 0;
	for (int x=1; x<n; x++) {
		int y = n-x;
		sol = max(sol, min(a/x, b/y));
	}
	cout << sol << '\n';
}