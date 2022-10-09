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

int m;

int evalt(vector<vector<int>>& b) {
	int t = 0;
	for (auto c : b) {
		t += *min_element(c.begin(), c.end());
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	vector<string> a;
	cin >> n;
	a.resize(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	m = a[0].size();
	string ref = a[0];

	vector<vector<int>> b(n);

	for (int i=0; i<n; i++) {
		vector<int>& c = b[i];
		string s = a[i];

		for (int j=0; j<m; j++) {
			if (s == ref) {
				c.push_back(j);
			}
			char x = s[0];
			s.erase(0, 1);
			s += x;
		}

		if (c.size() == 0) {
			cout << -1;
			return 0;
		}
	}

	int sol = evalt(b);

	for (int i=1; i<m; i++) {
		for (auto& c : b) {
			for (int& x : c) {
				x--;
				if (x == -1) {
					x = m-1;
				}
			}
		}
		sol = min(sol, evalt(b));
	}

	cout << sol;
}