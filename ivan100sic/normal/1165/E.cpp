#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[200005], b[200005], u[200005], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];
	for (int i=0; i<n; i++)
		u[i] = a[i] * (i+1)*(n-i);
	sort(u, u+n);
	sort(b, b+n, greater<ll>());
	const int mod = 998244353;
	ll sol = 0;
	for (int i=0; i<n; i++)
		sol = (sol + u[i] % mod * b[i] % mod) % mod;
	cout << sol << '\n';
}