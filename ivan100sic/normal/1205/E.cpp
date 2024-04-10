#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 1'000'000'007;

int pw(int x, int y) {
	if (y == 0)
		return 1;
	int z = pw(x, y >> 1);
	z = 1ll*z*z % mod;
	if (y & 1)
		z = 1ll*z*x % mod;
	return z;
}

ll cs(int n) {
	vector<ll> a(n+1);
	for (int i=1; i<=n; i++)
		a[i] = 1ll*(n/i)*(n/i-1)/2;
	for (int i=n; i>=1; i--)
		for (int j=2*i; j<=n; j+=i)
			a[i] -= a[j];
	return a[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	k = pw(k, mod-2);

	vector<ll> v(n+1);
	for (int i=2; i<n; i++)
		v[i] = i-1;
	for (int g=1; g<n; g++) {
		for (int a=g; a<n; a+=g) {
			int b = (n-a)/g*g;
			while (a+b < n)
				b += g;
			while (b < n && g > a+b-n) {
				if (gcd(a, b) == g) {
					v[2*n-a-b]--;
					v[n-g]++;					
				}
				b += g;
			}
		}
	}
	for (int g=1; g<n; g++)
		v[n-g] += cs((n-1)/g);

	ll s = 0, ki = 1;
	for (int i=1; i<n; i++) {
		ki = ki * k % mod;
		s = (s + ki * v[i]) % mod;
	}
	cout << s << '\n';
}