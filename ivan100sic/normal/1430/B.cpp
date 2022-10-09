// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;
		sort(begin(a), end(a));
		for (int i=n-2; i>n-2-k && i>=0; i--) {
			a.back() += a[i];
			a[i] = 0;
		}
		cout << a.back() << '\n';
	}
}