// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	int n, m;
	cin >> n >> m;
	int r = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		r = gcd(r, x-1);
	}

	while (r % 2 == 0)
		r >>= 1;


	set<int> d;
	for (int x=1; x*x <= r; x++) {
		if (r % x == 0) {
			d.insert(x);
			d.insert(r / x);
		}
	}

	ll s = 0;

	for (int p : d) {
		// svi r*2^x
		for (int i=p; i<m; i*=2)
			s += m-i;
	}
	
	cout << s << '\n';
}

// I will still practice daily...