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
vector<pair<int, int>> b;
set<pair<int, int>> s;
vector<int> senders;
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		s.insert({a[i], i});
	}

	s.erase({a[1], 1});
	while (a[1]--) {
		senders.push_back(1);
	}

	while (s.size()) {

		if (senders.size() == 0) {
			cout << -1;
			return 0;
		}

		int x = *senders.rbegin();
		senders.pop_back();
		auto p = *s.rbegin();
		s.erase(p);

		b.push_back({x, p.second});
		while (p.first--) {
			senders.push_back(p.second);
		}
	}

	cout << b.size() << '\n';
	for (auto p : b) {
		cout << p.first << ' ' << p.second << '\n';
	}
}