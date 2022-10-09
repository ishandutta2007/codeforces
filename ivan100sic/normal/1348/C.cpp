// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		sort(begin(s), end(s));
		if (k == 1) {
			cout << s << '\n';
			continue;
		}

		if (k == n) {
			cout << s.back() << '\n';
			continue;
		}

		if (s[0] != s[k-1]) {
			cout << s[k-1] << '\n';
			continue;
		}

		if (s[k] == s.back()) {
			cout << s[k-1] << string((n-k+k-1)/k, s.back()) << '\n';
		} else {
			cout << s.substr(k-1) << '\n';
		}
	}
}