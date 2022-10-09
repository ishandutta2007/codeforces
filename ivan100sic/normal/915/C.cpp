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

	string a, c;
	ll b;
	cin >> a >> b;

	int n = a.size();

	for (int i=0; i<n; i++) {
		set<char> t(a.begin(), a.end());
		if (i == 0)
			t.erase('0');
		for (auto it = t.rbegin(); it != t.rend(); ++it) {
			string s = c + *it;
			string g = a;
			g.erase(g.find(*it), 1);

			cerr << s << ' ' << g << '\n';

			sort(g.begin(), g.end());
			s += g;
			if (stoll(s) <= b) {
				c += *it;
				a = g;
				break;
			}
		}
	}

	cout << c << '\n';
}