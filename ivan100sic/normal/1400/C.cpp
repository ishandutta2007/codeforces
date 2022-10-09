// ne znam sta mi je danas
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
		int x;
		string s, w;
		cin >> s >> x;
		int n = s.size();
		w = string(n, '1');

		for (int i=0; i<n; i++) {
			if (s[i] == '0') {
				if (i-x >= 0) w[i-x] = '0';
				if (i+x < n) w[i+x] = '0';
			}
		}

		bool ok = true;
		for (int i=0; i<n; i++) {
			char e = '0';
			if (i-x >= 0 && w[i-x] == '1')
				e = '1';
			if (i+x < n && w[i+x] == '1')
				e = '1';
			if (e != s[i]) {
				ok = false;
			}
		}

		cout << (ok ? w : "-1") << '\n';
	}
}