// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

multiset<string> s[12];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	string sep;

	int sve = 0;

	cin >> n;
	for (int i=0; i<n; i++) {
		string t;
		cin >> t;
		s[t.size()].insert(t);
		sve += t.size();
	}

	cin >> sep;

	int tl = sve / (n / 2);

	for (int i=0; i<n/2; i++) {
		// sve duzine
		string qb;
		int xb = -1;

		for (int x=1; x<tl; x++) {
			int y = tl - x;
			if (x != y) {
				if (s[x].size() && s[y].size()) {
					string w = *s[x].begin() + sep + *s[y].begin();
					if (xb == -1 || w < qb) {
						qb = w;
						xb = x;
					}
				}
			} else {
				if (s[x].size() >= 2) {
					string w1 = *s[x].begin() + sep + *next(s[x].begin());
					string w2 = *next(s[x].begin()) + sep + *s[x].begin();

					string w = min(w1, w2);

					if (xb == -1 || w < qb) {
						qb = w;
						xb = x;
					}
				}
			}
		}

		cout << qb << '\n';
		int x = xb, y = tl - x;
		s[x].erase(s[x].begin());
		s[y].erase(s[y].begin());
	}
}