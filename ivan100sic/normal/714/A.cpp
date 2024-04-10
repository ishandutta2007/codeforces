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

	ll a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	ll z = min(b, d) - max(a, c) + 1;
	if (a <= e && e <= b && c <= e && e <= d)
		z--;
	cout << max(z, 0ll) << '\n';
}