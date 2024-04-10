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
vector<pair<int, int>> a;
vector<bool> b;

vector<vector<int>> sol;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	a.resize(n);
	for (int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end());
	b.resize(n, false);

	for (int i=0; i<n; i++) {
		int j = i;

		if (!b[j]) {
			vector<int> c;
			do {
				b[j] = true;
				j = a[j].second;
				c.push_back(j);
			} while (!b[j]);
			sol.push_back(c);
		}
	}

	cout << sol.size() << '\n';
	for (auto v: sol) {
		cout << v.size();
		for (int x : v) {
			cout << ' ' << 1+x;
		}
		cout << '\n';
	}
}