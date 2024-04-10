#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s >> t;
	set<int> sa, ta;
	for (int i=0; i<n; i++) {
		if (s[i] == 'a')
			sa.insert(i);
		if (t[i] == 'a')
			ta.insert(i);
	}

	if ((sa.size() + ta.size()) % 2) {
		cout << "-1\n";
		return 0;
	}

	set<int> comm;
	for (int x : sa)
		if (ta.count(x))
			comm.insert(x);
	for (int x : comm)
		sa.erase(x), ta.erase(x);

	vector<pair<int, int>> sol;

	while (sa.size() >= 2) {
		int x = *sa.begin();
		sa.erase(x);
		int y = *sa.begin();
		sa.erase(y);
		sol.emplace_back(x, y);
	}

	while (ta.size() >= 2) {
		int x = *ta.begin();
		ta.erase(x);
		int y = *ta.begin();
		ta.erase(y);
		sol.emplace_back(x, y);
	}

	if (sa.size() && ta.size()) {
		int x = *sa.begin();
		int y = *ta.begin();
		sol.emplace_back(x, x);
		sol.emplace_back(x, y);
	}

	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << x+1 << ' ' << y+1 << '\n';
}