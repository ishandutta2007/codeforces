#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[100005], n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	ll sx = 0, sb = 0, sc = 0;
	while (m--) {
		ll x, d;
		cin >> x >> d;
		sx += x;
		if (d < 0) {
			sc += d;
		} else {
			sb += d;
		}
	}
	ll c = (n+1) / 2;
	
	double z = n*sx;
	z += (double)sb * n * (n-1) / 2;
	for (int i=1; i<=n; i++)
		z += abs(c-i)*sc;

	cout.precision(20);
	cout << fixed << z/n << '\n';
}