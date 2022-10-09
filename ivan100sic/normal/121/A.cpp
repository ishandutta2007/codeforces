#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<ll> b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	const int H = 10;

	b = {0};
	for (int l=1; l<=H; l++) {
		for (int m=0; m<(1<<l); m++) {
			ll z = 0;
			for (int i=0; i<l; i++) {
				if (m & (1 << i)) {
					z = 10*z + 7;
				} else {
					z = 10*z + 4;
				}
			}
			b.push_back(z);
		}
	}
	sort(b.begin(), b.end());

	ll l, r, z=0;
	cin >> l >> r;
	for (int i=1; i<(int)b.size(); i++) {
		ll x = max(b[i-1]+1, l);
		ll y = min(b[i], r);
		z += max(y-x+1, 0ll) * b[i];
	}
	cout << z << '\n';
}