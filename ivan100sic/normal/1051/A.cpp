#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool ok(string s) {
	int u = 0, l = 0, n = 0;
	for (char x : s) {
		u |= isupper(x);
		l |= islower(x);
		n |= isdigit(x);
	}
	return u && l && n;
}

vector<string> z = {"", "a", "A", "0", "aA", "a0", "A0", "aA0" };

void solve1(string s) {
	for (string r : z) {
		for (int i = 0; i <= (int)s.size() - r.size(); i++) {
			string p = s;
			copy(r.begin(), r.end(), p.begin() + i);
			if (ok(p)) {
				cout << p << '\n';
				return;
			}
		}
	}
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		solve1(s);
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}