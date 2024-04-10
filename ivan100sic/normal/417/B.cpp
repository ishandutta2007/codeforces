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

	// ne kapiram zadatak majke mi...
	set<pair<int, int>> s;
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		if (x > 0) {
			if (!s.count({x-1, y})) {
				cout << "NO\n";
				return 0;
			}
		}
		s.insert({x, y});
	}
	cout << "YES\n";
}