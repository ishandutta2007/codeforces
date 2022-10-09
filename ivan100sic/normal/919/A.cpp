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

	int n, m;
	double sol = 1e20;
	cin >> n >> m;
	while (n--) {
		int a, b;
		cin >> a >> b;
		sol = min(sol, a*1.0/b);
	}
	cout.precision(20);
	cout << fixed;
	cout << sol*m << '\n';
}