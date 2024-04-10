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

	ll a, b;
	cin >> a >> b;
	if (b > a) {
		cout << "-1\n";
	} else if (a == b) {
		cout << a << '\n';
	} else {
		ld x = 1e50;
		int k = a / b;
		if (k % 2 == 0)
			k--;
		k /= 2;
		x = min(x, (a-b) / (ld)2.0 / k);
		x = min(x, (a+b) / (ld)2.0 / (k + 1));
		cout.precision(20);
		cout << fixed;
		cout << x << '\n';		
	}
}