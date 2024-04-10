#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, int> c1, c2;

void dec(map<int, int>& mp, int x) {
	mp[x]--;
	if (mp[x] == 0)
		mp.erase(x);
}

void add(int x) {
	if (c1[x])
		dec(c2, c1[x]);
	c1[x]++;
	c2[c1[x]]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	int sol = 0;

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		add(x);

		// cerr << "c1:\n";
		// for (auto p : c1)
		// 	cerr << p.first << ' ' << p.second << '\n';

		// cerr << "c2:\n";
		// for (auto p : c2)
		// 	cerr << p.first << ' ' << p.second << '\n';

		if (c2.size() == 1) {
			if (c2.begin()->first == 1 || c2.begin()->second == 1)
				sol = max(sol, i);
		} else if (c2.size() == 2) {
			pair<int, int> p1 = *c2.begin();
			pair<int, int> p2 = *next(c2.begin());

			bool ok = false;
			if (p1.second == 1 && p1.first - 1 == p2.first)
				ok = true;
			if (p2.second == 1 && p2.first - 1 == p1.first)
				ok = true;
			if (p1 == pair<int, int>{1, 1})
				ok = true;
			if (p2 == pair<int, int>{1, 1})
				ok = true;

			if (ok)
				sol = max(sol, i);
		}
	}

	cout << sol << '\n';


}