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

	ll n, k, a, b, z=0;
	cin >> n >> k >> a >> b;
	if (k == 1)
		return cout << a*(n-1) << '\n', 0;
	while (n > 0) {
		if (n % k == 0) {
			z += min(b, a*(n-n/k));
			n /= k;
		} else {
			z += n % k * a;
			n -= n % k;
		}
	}
	cout << z - a << '\n';
}