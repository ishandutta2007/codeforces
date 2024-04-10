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

	ll n, k;
	cin >> n >> k;

	if (n == 1) {
		cout << "1\n";
	} else if (n == 2) {
		cout << k << ' ' << 3-k << '\n';
	} else {
		k--;
		basic_string<ll> a = {1, 2};
		while ((int)a.size() != n-1)
			a += a[a.size()-2] + a[a.size()-1];
		reverse(a.begin(), a.end());
		basic_string<int> b(n, 0);
		iota(b.begin(), b.end(), 1);
		for (int i=1; i<n; i++) {
			if (k >= a[i-1]) {
				k -= a[i-1];
				swap(b[i], b[i-1]);
				i++;
			}
		}
		for (int x : b)
			cout << x << ' ';
		cout << '\n';
	}
}