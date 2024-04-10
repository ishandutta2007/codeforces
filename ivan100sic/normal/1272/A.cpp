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

	int q;
	cin >> q;
	while (q--) {
		ll a, b, c, u = 1e18;
		cin >> a >> b >> c;
		for (int i=-1; i<=1; i++)
		for (int j=-1; j<=1; j++)
		for (int k=-1; k<=1; k++)
		{
			ll x = a+i, y = b+j, z = c+k;
			u = min(u, abs(x-y) + abs(y-z) + abs(z-x));
		}
		cout << u << '\n';
	}
}