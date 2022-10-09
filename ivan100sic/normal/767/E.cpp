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

int n;
int c[100005], w[100005];
multiset<pair<int, int>> s;

int mark[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int m, heaps, rem;
	long long sol = 0;

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> c[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> w[i];
	}

	for (int i=1; i<=n; i++) {

		if (c[i] % 100) {
			s.insert({(100 - c[i] % 100) * w[i], i});
		}

		m -= c[i] % 100;
		if (m < 0) {
			m += 100;
			sol += s.begin()->first;
			mark[s.begin()->second] = 1;
			s.erase(s.begin());
		}
		
	}

	cout << sol << '\n';

	for (int i=1; i<=n; i++) {
		if (mark[i]) {
			cout << c[i]/100 + 1 << " 0\n";
		} else {
			cout << c[i]/100 << ' ' << c[i] % 100 << '\n';
		}
	}
}