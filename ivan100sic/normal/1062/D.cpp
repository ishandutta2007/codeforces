#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	ll x = 0;
	for (int i=2; i<=n; i++) {
		for (int j=2*i; j<=n; j+=i) {
			x += 4*(j/i);
		}
	}
	cout << x << '\n';

}