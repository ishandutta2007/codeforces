#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

set<int> divs(int x) {
	set<int> s;
	for (int i=1; i*i<=x; i++) {
		if (x % i == 0) {
			s.insert(i);
			s.insert(x/i);
		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int l, r;
	cin >> l >> r;
	if (r-l >= 8) {
		cout << "2\n";
	} else {
		map<int, int> c;
		for (int i=l; i<=r; i++) {
			auto s = divs(i);
			for (int x : s)
				if (x > 1) c[x]++;
		}
		int h=0, b=0;
		for (auto p : c) {
			if (p.second > h) {
				h = p.second;
				b = p.first;
			}
		}
		cout << b << '\n';
	}
}