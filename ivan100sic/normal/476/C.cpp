#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll M = 1'000'000'007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b;
	cin >> a >> b;

	ll z = 0;
	for (ll r=1; r<b; r++) {
		z += a*b%M*r%M + a*a%M*b%M*r%M + 2*a%M*r;
		z %= M;
	}

	cout << z*((M+1)/2)%M << '\n';
}