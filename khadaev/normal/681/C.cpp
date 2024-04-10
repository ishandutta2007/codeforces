#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<int, int> > ans;
	map<int, int> s;
	int n;
	cin >> n;
	forn(i, 0, n) {
		string t;
		cin >> t;
		if (t[0] == 'i') {
			int k;
			cin >> k;
			s[k]++;
			ans.eb(0, k);
		} else if (t[0] == 'g') {
			int k;
			cin >> k;
			if (s.empty()) {
				ans.eb(0, k);
				ans.eb(1, k);
				s[k] = 1;
				continue;
			}
			auto it = s.begin();
			int mn = it->first;
			while (k > mn) {
				forn(j, 0, it->second) ans.eb(2, 0);
				s.erase(it);
				if (s.empty()) break;
				it = s.begin();
				mn = it->first;
			}
			if (s.empty() || k < mn) {
				s[k]++;
				ans.eb(0, k);
			}
			ans.eb(1, k);
		} else {
			if (s.empty()) {
				ans.eb(0, 0);
			} else {
				auto it = s.begin();
				if (it->second == 1) s.erase(it);
				else --it->second;
			}
			ans.eb(2, 0);
		}
	}
	cout << ans.size() << '\n';
	for (auto p : ans) {
		if (p.fs == 0) cout << "insert " << p.sn << '\n';
		if (p.fs == 1) cout << "getMin " << p.sn << '\n';
		if (p.fs == 2) cout << "removeMin\n";
	}
	return 0;
}