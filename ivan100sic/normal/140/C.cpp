#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	set<pair<int, int>> s;
	map<int, int> c;
	cin >> n;

	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	for (auto p : c) {
		s.insert({p.second, p.first});
	}

	while (n > 0) {
		if (n % 3 == 0 && s.rbegin()->first <= n / 3) {
			break;
		}

		auto p = *s.rbegin();
		s.erase(p);

		p.first--;
		n--;

		if (p.first > 0) {
			s.insert(p);
		}
	}

	vector<int> sol;

	for (auto p : s) {
		for (int i=0; i<p.first; i++) {
			sol.push_back(p.second);
		}
	}

	sort(sol.begin(), sol.end());
	reverse(sol.begin(), sol.end());

	cout << sol.size() / 3 << '\n';
	for (int i=0; i<sol.size()/3; i++) {
		for (int j=i; j<sol.size(); j+=sol.size()/3) {
			cout << sol[j] << ' ';
		}
		cout << '\n';
	}
}