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

	int n;
	cin >> n;
	set<int> s, d;
	while (n--) {
		int x;
		cin >> x;
		if (x == 0)
			continue;

		if (s.count(x)) {
			s.erase(x);
			d.insert(x);
		} else if (d.count(x)) {
			cout << "-1\n";
			return 0;
		} else {
			s.insert(x);
		}
	}
	cout << d.size() << '\n';
}