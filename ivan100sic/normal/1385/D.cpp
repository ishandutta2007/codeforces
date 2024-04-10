// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct sol {
	int g[26], e[26];
};

sol solve(string& s, int l, int r) {
	if (r - l == 1) {
		sol so;
		for (int i=0; i<26; i++) {
			so.g[i] = so.e[i] = 1 - (s[l] - 'a' == i);
		}
		return so;
	}

	int m = (l+r) / 2;
	sol sl = solve(s, l, m);
	sol sr = solve(s, m, r);

	sol so;
	for (int i=0; i<26; i++) {
		so.e[i] = sl.e[i] + sr.e[i];
		if (i < 25) {
			so.g[i] = min(sl.e[i] + sr.g[i+1], sl.g[i+1] + sr.e[i]);
		} else {
			so.g[i] = 1123123;
		}
	}

	return so;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		cout << solve(s, 0, n).g[0] << '\n';
	}
}