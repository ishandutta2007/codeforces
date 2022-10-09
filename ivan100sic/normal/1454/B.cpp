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
		map<int, basic_string<int>> e;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			e[x] += i;
		}
		int f=0;
		for (auto [k, v] : e) {
			if (v.size() == 1) {
				cout << v[0]+1 << '\n';
				f=1;
				break;
			}
		}
		if (!f) cout << "-1\n";
	}
}