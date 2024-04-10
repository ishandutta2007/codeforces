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

	int n;
	cin >> n;
	ll a=0, b=0;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		a += x / 2;
		b += x / 2;
		(i % 2 ? a : b) += x % 2;
	}
	if (a != b && n % 2)
		a++;
	cerr << a << ' ' << b << '\n';
	cout << (a == b ? "YES\n" : "NO\n");
}