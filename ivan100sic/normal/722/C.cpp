#include <iostream>
#include <set>
#include <string>
using namespace std;

set<pair<int, int>> b;
multiset<long long> t;
int a[100005], p[100005];
int n;
long long z[100005];

long long sum(int l, int r) {
	return z[r] - z[l - 1];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		z[i] = z[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	b.insert({ 1, n });
	t.insert(sum(1, n));
	for (int i = 1; i<n; i++) {
		auto it = *--b.upper_bound({ p[i], 1e9 });
		b.erase(it);
		auto pt = t.find(sum(it.first, it.second));
		t.erase(pt);

		// ubaci novonastala dva
		if (it.first <= p[i] - 1) {
			b.insert({ it.first, p[i] - 1 });
			t.insert(sum(it.first, p[i] - 1));
		}

		if (p[i] + 1 <= it.second) {
			b.insert({ p[i] + 1, it.second });
			t.insert(sum(p[i] + 1, it.second));
		}

		cout << *t.rbegin() << endl;
	}

	cout << 0 << endl;

	cin >> n;

	return 0;
}