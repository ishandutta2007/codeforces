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
		string s;
		cin >> s;
		map<char, int> br;
		char w;
		int n = s.size();
		for (char c : s) {
			br[c]++;
		}

		int mb = 0;
		char mc = 0;
		for (auto [c, b] : br) {
			if (b > mb) {
				mb = b;
				mc = c;
			}
		}

		if (mc == 'R') {
			w = 'P';
		} else if (mc == 'S') {
			w = 'R';
		} else {
			w = 'S';
		}

		cout << string(n, w) << '\n';
	}
}