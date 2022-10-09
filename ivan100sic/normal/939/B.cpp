#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, k;
	cin >> n >> k;

	ll sol = -1, jbg = 0, idx = 0;

	for (int i=1; i<=k; i++) {
		ll a;
		cin >> a;
		ll v = n/a*a;
		if (v > sol) {
			sol = v;
			jbg = v/a;
			idx = i;
		}
	}

	cout << idx << ' ' << jbg << '\n';

}