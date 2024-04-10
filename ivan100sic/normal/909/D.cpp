#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int sol = 0;
	string s;
	cin >> s;
	list<pair<char, int>> a;
	for (int i=0; i<(int)s.size(); i++)
		a.emplace_back(s[i], i);
	vector<list<pair<char, int>>::iterator> b;
	for (auto it=a.begin(); it!=a.end(); ++it)
		b.push_back(it);
	while (1) {
		// proveri koji su dobri u b
		vector<list<pair<char, int>>::iterator> c;
		for (auto it : b) {
			if (it != a.begin() && prev(it)->first != it->first)
				c.push_back(it);
			else if (next(it) != a.end() && next(it)->first != it->first)
				c.push_back(it);
		}
		unordered_map<int, list<pair<char, int>>::iterator> mp;
		for (auto it : c) {
			if (it != a.begin())
				mp[prev(it)->second] = prev(it);
			if (next(it) != a.end())
				mp[next(it)->second] = next(it);
		}
		if (c.size()) {
			for (auto it : c) {
				mp.erase(it->second);
				a.erase(it);
			}
			b = {};
			for (auto [k, it] : mp)
				b.push_back(it);
			sol++;
		} else {
			break;
		}
	}
	cout << sol << '\n';
}