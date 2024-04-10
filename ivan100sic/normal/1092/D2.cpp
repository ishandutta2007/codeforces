#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void no() {
	cout << "NO\n";
	exit(0);
}

void run(basic_string<int> a) {
	basic_string<pair<int, int>> s;
	for (int i=0; i<(int)a.size(); i++) {
		int x = a[i];
		while (s.size() && x >= s.back().first) {
			// cerr << "! " << i << ' ' << s.back().second << '\n';
			if ((s.back().second - i + 1) % 2)
				no();
			s.pop_back();
		}
		s += {x, i};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, h = 0;
	cin >> n;
	basic_string<int> a;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		h = max(h, x);
		a += x;
	}
	a = basic_string<int>(1, h) + a + h;
	run(a);
	reverse(a.begin(), a.end());
	run(a);
	cout << "YES\n";
}