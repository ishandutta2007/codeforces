#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<string, int> sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	set<string> used;

	for (int i=1989; i<=20000; i++) {
		string s = to_string(i);
		for (int k=1; k<=(int)s.size(); k++) {
			string p = s.substr(s.size()-k);
			if (!used.count(p)) {
				used.insert(p);
				// cout << i << ' ' << p << '\n';
				sol[p] = i;
				break;
			}
		}
	}

	while (q--) {
		string s, p;
		cin >> s;
		p = s.substr(4);
		ll n = p.size();
		if (n <= 4) {
			cout << sol[p] << '\n';
		} else {
			string f = "3099";
			for (int i=4; i<n; i++)
				f = string("1") + f;
			if (p < f) {
				cout << 1 << p << '\n';
			} else {
				cout << p << '\n';
			}
		}
	}
}