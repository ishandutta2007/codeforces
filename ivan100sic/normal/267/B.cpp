#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int u[105], v[105], m;
bool used[105];
int d[9];
set<int> e[9];

list<int> euler(int x) {
	list<int> t;
	while (e[x].size()) {
		int i = *e[x].begin();
		int y = u[i] ^ v[i] ^ x;
		e[x].erase(i);
		e[y].erase(i);
		t.push_back(y);
		x = y;
	}

	for (auto it = t.begin(); it != t.end(); ++it) {
		auto w = euler(*it);
		t.splice(next(it), w); // idk valjda je ovako
	}

	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m;
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i];
		d[u[i]]++, d[v[i]]++;
	}

	vector<int> odd;
	for (int i=0; i<=6; i++)
		if (d[i] % 2)
			odd.push_back(i);
	if (odd.size() >= 4) {
		cout << "No solution\n";
		return 0;
	}

	int mm = m;
	if (odd.size() == 2) {
		mm++;
		cerr << "adding " << odd[0] << ' ' << odd[1] << '\n';
		u[mm] = odd[0];
		v[mm] = odd[1];
	}

	for (int i=1; i<=mm; i++) {
		e[u[i]].insert(i);
		e[v[i]].insert(i);
	}

	for (int x=0; x<=6; x++) {
		auto a = euler(x);
		if (a.size()) {
			if ((int)a.size() != mm) {
				cout << "No solution\n";
				return 0;
			}
			a.push_front(x);
			vector<pair<int, char>> sol;
			for (auto it = a.begin(); next(it) != a.end(); ++it) {
				int x = *it, y = *next(it);
				for (int j=1; j<=mm; j++) {
					if (used[j])
						continue;
					if (u[j] == x && v[j] == y) {
						used[j] = true;
						sol.emplace_back(j, '+');
						break;
					} else if (u[j] == y && v[j] == x) {
						used[j] = true;
						sol.emplace_back(j, '-');
						break;
					}
				}
			}
			if (mm != m) {
				auto it = find_if(sol.begin(), sol.end(),
					[&](auto a) { return a.first == mm; });
				rotate(sol.begin(), it, sol.end());
				sol.erase(sol.begin());
			}
			for (auto [a, b] : sol)
				cout << a << ' ' << b << '\n';
		}
	}
}