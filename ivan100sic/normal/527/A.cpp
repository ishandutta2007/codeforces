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

	ll a, b, c = 0;
	cin >> a >> b;
	while (a && b) {
		if (a < b)
			swap(a, b);
		c += a / b;
		a = a % b;
	}
	cout << c << '\n';
}