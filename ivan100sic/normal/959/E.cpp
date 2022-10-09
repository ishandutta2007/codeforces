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

	ll n, sol=0;
	cin >> n;
	for (ll x=1; x<n; x<<=1) {
		sol += x * ((n-1) / x - (n-1) / x / 2);
	}
	cout << sol << '\n';
}