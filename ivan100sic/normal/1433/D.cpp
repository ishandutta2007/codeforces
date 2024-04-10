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
		vector<int> a(n);
		for (int i=0; i<n; i++) cin >> a[i];

		auto mm = minmax_element(begin(a), end(a));
		if (*mm.first == *mm.second) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		int d = find_if(begin(a), end(a), [&](int x) { return x != a[0]; }) - begin(a);

		for (int i=1; i<n; i++) {
			if (a[i] == a[0]) {
				cout << d+1 << ' ' << i+1 << '\n';
			} else {
				cout << "1 " << i+1 << '\n';
			}
		}
	}
}