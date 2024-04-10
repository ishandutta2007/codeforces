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
		int n;
		cin >> n;
		ll sol = 0;
		vector<int> a(n);
		vector<int> m(66);
		for (int i=0; i<n; i++) {
			cin >> a[i];
			sol += m[__builtin_clz(a[i])]++;
		}
		cout << sol << '\n';


	}
}