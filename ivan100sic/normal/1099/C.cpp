#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stvar {
	int tip;
	char x;
};

int c[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	int k;
	cin >> s >> k;
	basic_string<stvar> b;


	for (int i=0; i<(int)s.size(); i++) {
		if (i+1 < (int)s.size() && !isalpha(s[i+1])) {
			if (s[i+1] == '*') {
				b += stvar{2, s[i]};
			} else if (s[i+1] == '?') {
				b += stvar{0, s[i]};
			}
			i++;
		} else {
			b += stvar{1, s[i]};
		}
	}

	for (auto p : b)
		c[p.tip]++;

	// da li ima *
	if (c[2] > 0) {
		if (k >= c[1]) {
			int preko = k - c[1];
			for (auto p : b)
				if (p.tip == 1)
					cout << p.x;
				else if (p.tip == 2 && preko > 0) {
					cout << string(preko, p.x);
					preko = 0;
				}
			cout << '\n';
		} else {
			cout << "Impossible\n";
		}
	} else {
		// moze izmedju c1 i c0 + c1
		if (k >= c[1] && k <= c[0] + c[1]) {
			int preko = k - c[1];
			for (auto p : b)
				if (p.tip == 1)
					cout << p.x;
				else if (p.tip == 0 && preko > 0) {
					cout << p.x;
					preko--;
				}
			cout << '\n';
		} else {
			cout << "Impossible\n";
		}
	}
}