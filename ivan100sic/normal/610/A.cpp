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

	ll n;
	cin >> n;
	if (n % 2 || n == 2)
		return cout << 0, 0;

	ll x = n / 4;
	if (n % 4 == 0)
		x--;

	cout << x << '\n';
}