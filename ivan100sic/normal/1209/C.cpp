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

	int t;
	cin >> t;
	while (t--) {
		int n, ok = 0;
		string s;
		cin >> n >> s;

		for (char h='0'; h<='9'; h++) {
			string t, u, v;
			for (char c : s) {
				if (c < h) {
					t += '1';
					u += c;
				} else if (c > h) {
					t += '2';
					v += c;
				} else if (v.size() == 0 || v.back() == c) {
					t += '2';
					v += c;
				} else {
					t += '1';
					u += c;
				}
			}

			u += v;
			if (is_sorted(u.begin(), u.end())) {
				ok = 1;
				cout << t << '\n';
				break;
			}
		}

		if (!ok) {
			cout << "-\n";
		}
	}
}