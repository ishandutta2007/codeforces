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

	int n;
	cin >> n;
	
	map<pair<int, string>, vector<int>> mp;

	for (int i=1; i<=n; i++) {
		string s, t;
		cin >> s >> t;
		int a = 0;
		for (char x : t)
			a |= 1 << (x - 'a');
		// dokle god je poslednje slovo u skupu makni ga
		while (s.size()) {
			if (a & (1 << (s.back() - 'a'))) {
				s.pop_back();
			} else {
				break;
			}
		}
		mp[{a, s}].push_back(i);
	}

	cout << mp.size() << '\n';
	for (auto p : mp) {
		cout << p.second.size();
		for (int x : p.second)
			cout << ' ' << x;
		cout << '\n';
	}

}