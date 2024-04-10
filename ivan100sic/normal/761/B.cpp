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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, L, x;
	set<int> a, b, c;

	cin >> n >> L;
	for (int i=1; i<=n; i++) {
		cin >> x;
		a.insert(x);
	}
	for (int i=1; i<=n; i++) {
		cin >> x;
		b.insert(x);
	}

	for (int i=0; i<L; i++) {
		c.clear();
		for (int x : a) {
			c.insert((x+i) % L);
		}
		if (b == c) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

}