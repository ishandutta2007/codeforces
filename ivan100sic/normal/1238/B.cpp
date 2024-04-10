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
		ll n, r;
		cin >> n >> r;
		vector<ll> a(n);
		for (ll& x : a)
			cin >> x;
		sort(begin(a), end(a));
		ll decr = 0, used = 0, pos = n-1;
		while (pos >= 0) {
			if (a[pos] - decr <= 0) {
				pos--;
			} else {
				used++;
				decr += r;
				int eq = a[pos];
				while (pos >= 0 && a[pos] == eq)
					pos--;
			}
		}
		cout << used << '\n';
	}
}