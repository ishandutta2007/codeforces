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

	set<ll> b;

	for (int n=2; n<=10; n++) {
		for (int mask=0; mask<(1<<n); mask++) {
			ll z = 0;
			int y = 0;
			for (int i=0; i<n; i++) {
				if (mask & (1 << i))
					z = 10*z + 4, y++;
				else
					z = 10*z + 7, y--;
			}
			if (!y) 
				b.insert(z);
		}
	}

	ll n;
	cin >> n;
	cout << *b.lower_bound(n) << '\n';
}