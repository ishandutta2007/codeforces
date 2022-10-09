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

	int n, d, e;
	cin >> n >> d >> e;
	e *= 5;

	int l = n;
	for (int x=0; d*x<=n; x++) {
		int y = (n-d*x) / e;
		l = min(l, n-d*x-e*y);
	}
	cout << l << '\n';
}