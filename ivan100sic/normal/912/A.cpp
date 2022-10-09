#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b, x, y, z;

	cin >> a >> b >> x >> y >> z;

	ll xa = 2*x + y;
	ll xb = y + 3*z;

	cout << max(0ll, xa-a) + max(0ll, xb-b);
}