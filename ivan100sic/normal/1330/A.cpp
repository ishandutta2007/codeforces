// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		set<int> s;
		for (int i=1; i<=333; i++)
			s.insert(i);
		while (n--) {
			int x;
			cin >> x;
			s.erase(x);
		}
		while (x--) {
			s.erase(s.begin());
		}
		cout << *s.begin() - 1 << '\n';
	}
}

// I will still practice daily...