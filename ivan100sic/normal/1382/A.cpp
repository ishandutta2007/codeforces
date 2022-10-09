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
		set<int> a;
		int n, m;
		cin >> n >> m;
		while (n--) {
			int x;
			cin >> x;
			a.insert(x);
		}
		int z = -1;
		while (m--) {
			int x;
			cin >> x;
			if (a.count(x)) {
				z = x;
			}
		}
		if (z == -1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << "1 " << z << '\n';
		}
	}
}