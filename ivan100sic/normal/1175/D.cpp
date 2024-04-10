#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
ll a[300005];
ll z[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	
	for (int i=n; i>=1; i--) {
		z[i] = a[i] + z[i+1];
	}

	ll u = 0;
	sort(z+2, z+n+1, greater<ll>());
	for (int i=2; i<=k; i++) {
		u += z[i];
	}
	u += z[1];
	cout << u << '\n';
}