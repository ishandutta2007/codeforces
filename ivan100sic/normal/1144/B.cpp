#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int resi(multiset<int> a, multiset<int> b) {
	for (int i=0;; i++) {
		auto& c = i%2 ? a : b;
		if (!c.size()) {
			return accumulate(a.begin(), a.end(), 0)
				+ accumulate(b.begin(), b.end(), 0);
		} else {
			c.erase(--c.end());
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	multiset<int> e[2];
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		e[x%2].insert(x);
	}
	int z = min(resi(e[0], e[1]), resi(e[1], e[0]));
	cout << z << '\n';
}