#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n;
ll a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	ll z = a[1] * (n-a[1]+1);
	for (int i=2; i<=n; i++) {
		ll x = a[i-1], y = a[i];
		// levi ne postoji, ja postojim
		if (y > x) {
			z += (y-x) * (n-y+1);
		} else if (y < x) {
			z += (x-y) * y;
		}
	}
	cout << z << '\n';
}