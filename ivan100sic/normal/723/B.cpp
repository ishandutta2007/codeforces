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

	int _;
	string s;
	cin >> _ >> s;
	s += "_";
	int t = 0, zg = 0;
	int u = 0, v = 0;
	for (char x : s) {
		if (x == '(') {
			if (t) {
				if (zg)
					u++;
				else
					v = max(v, t);
				t = 0;
			}
			zg++;
		} else if (x == ')') {
			if (t) {
				if (zg)
					u++;
				else
					v = max(v, t);
				t = 0;
			}
			zg--;
		} else if (x == '_') {
			if (t) {
				if (zg)
					u++;
				else
					v = max(v, t);
				t = 0;
			}
		} else {
			t += 1;
		}
	}
	cout << v << ' ' << u << '\n';
}