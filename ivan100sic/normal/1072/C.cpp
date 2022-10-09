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

	int n, m;
	cin >> n >> m;
	
	int t = n + m;
	basic_string<int> a, b, c;
	for (int i=1;; i++) {
		if (i <= t) {
			t -= i;
			c += i;
		} else break;
	}
	while (c.size()) {
		int x = c.back();
		c.pop_back();
		if (x <= n) {
			a += x;
			n -= x;
		} else {
			b += x;
			m -= x;
		}
	}

	cout << a.size() << '\n';
	for (int x : a)
		cout << x << ' ';
	cout << '\n';

	cout << b.size() << '\n';
	for (int x : b)
		cout << x << ' ';
	cout << '\n';

}