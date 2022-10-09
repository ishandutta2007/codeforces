#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[200005], n, sol = 4e18;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	ll g = 0;
	for (int i=1; i<n; i++)
		g = gcd(g, abs(a[0] - a[i]));

	ll y = 0, hi = *max_element(a, a+n);
	for (int i=0; i<n; i++) {
		y += (hi - a[i]) / g;
	}
	cout << y << ' ' << g << '\n';
}