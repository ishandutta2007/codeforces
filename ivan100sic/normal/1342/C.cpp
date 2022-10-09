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
		int a, b, q;
		cin >> a >> b >> q;
		vector<int> z(a*b+1);
		for (int i=0; i<a*b; i++) {
			int k = i % a % b != i % b % a;
			z[i+1] = z[i] + k;
		}

		auto f = [&](ll x) {
			return x/a/b * z[a*b] + z[x%(a*b)];
		};

		while (q--) {
			ll l, r;
			cin >> l >> r;
			cout << f(r+1) - f(l) << ' ';
		}
		cout << '\n';
	}
}