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
		set<int> seen;
		for (int i=0; i<2*n; i++) {
			int x;
			cin >> x;
			if (!seen.count(x)) {
				cout << x << ' ';
				seen.insert(x);
			}
		}
		cout << '\n';
	}
}