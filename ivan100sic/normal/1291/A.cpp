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
		int n;
		cin >> n;
		string s;
		cin >> s;

		while (s.size() && s.back() % 2 == 0) {
			s.pop_back();
		}

		int u = accumulate(begin(s), end(s), 0);
		if (u % 2) {
			bool f = 0;
			for (int j=0; j<(int)s.size(); j++) {
				if (s[j] % 2) {
					if (j == 0 && (s.size() == 1 || s[j+1] == '0')) {
						// nemoj ipak
					} else if (j == (int)s.size() - 1) {
						// isto
					} else {
						s.erase(j, 1);
						f = 1;
						break;
					}
				}
			}
			if (!f) s = "";
		}

		cout << (s.size() ? s : "-1") << '\n';
	}
}