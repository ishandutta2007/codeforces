// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, a[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a, a+n);

	ull sol = accumulate(a, a+n, 0ll) - n;

	for (int x=2, ok=1; ok; x++) {
		ull pw = 1, w = 0;
		ld pwd = 1;
		for (int i=0; i<n; i++) {
			if (pwd > n*5e9) {
				w = 1e18;
				ok = 0;
				break;
			}

			w += abs(ll(a[i]) - ll(pw));
			pw *= x;
			pwd *= x;
		}
		sol = min(sol, w);
	}

	cout << sol << '\n';
}