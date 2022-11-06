#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> loses(n);
	vector<bool> defined(n, false);
	set<int> winners;
	int def = 0;
	forn(i, 0, n) winners.insert(i);
	vector<vector<int> > edges(n);
	forn(i, 0, m) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		if (defined[u]) continue;
		edges[u].push_back(v);
		if (loses[v] == 0) winners.erase(v);
		loses[v]++;
		while (winners.size() == 1) {
			//cout << i << '\n';
			++def;
			int win = *(winners.begin());
			winners.clear();
			defined[win] = true;
			for (int p : edges[win]) {
				loses[p]--;
				if (loses[p] == 0 && !defined[p]) winners.insert(p);
			}
		}
		if (def == n) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}