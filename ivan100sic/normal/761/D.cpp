#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, l, r;

struct broj {
	int a, b, c, cc, id;

	bool operator< (const broj& other) const {
		return cc < other.cc;
	}
};

broj a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l >> r;

	for (int i=0; i<n; i++) {
		cin >> a[i].a;
		a[i].id = i;
	}

	for (int i=0; i<n; i++) {
		cin >> a[i].cc;
	}

	sort(a, a+n);

	int cminval = -1.01e9;

	for (int i=0; i<n; i++) {
		int bl = l, br = r;
		bl = max(bl, a[i].a + cminval);
		if (bl <= br) {
			a[i].b = bl;
			a[i].c = a[i].b - a[i].a;
			cminval = a[i].c + 1;
		} else {
			cout << -1;
			return 0;
		}
	}

	sort(a, a+n, [](auto a, auto b) { return a.id < b.id; });
	for (int i=0; i<n; i++) {
		cout << a[i].b << ' ';
	}


}