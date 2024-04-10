#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

set<int> advance(set<int> s) {
	set<int> p;
	for (int x : s) {
		p.insert(x + 1);
		p.insert(x + 5);
		p.insert(x + 10);
		p.insert(x + 50);
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	set<int> s = {0};
	int n;
	cin >> n;
	if (n <= 12) {
		for (int i=1; i<=n; i++) {
			s = advance(s);
			cerr << i << ' ' << s.size() << '\n';
		}
		cout << s.size() << '\n';
	} else {
		cout << 49ll * n - 247 << '\n';
	}

		
}