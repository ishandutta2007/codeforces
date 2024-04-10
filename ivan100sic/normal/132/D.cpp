#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void ad(string& s, int x) {
	if (s[x] == '1') {
		s[x] = '0';
		ad(s, x+1);
	} else {
		s[x] = '1';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(), s.end());
	basic_string<pair<char, int>> sol;
	s += "00";

	for (int i=0; i<=n; i++) {
		if (s[i] == '1') {
			if (s[i+1] == '1') {
				ad(s, i);
				sol += {'-', i};
			} else {
				s[i] = '0';
				sol += {'+', i};
			}
		}
	}
	cout << sol.size() << '\n';
	for (auto [c, x] : sol)
		cout << c << "2^" << x << '\n';
}