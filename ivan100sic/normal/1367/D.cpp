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
		int c[26] = {0};
		for (char x : s) {
			c[x-'a']++;
		}

		int m;
		cin >> m;
		vector<int> b(m);
		for (int& x : b)
			cin >> x;

		s = string(m, 0);

		int slovo = 25;
		while (1) {
			vector<int> f;
			for (int i=0; i<m; i++) {
				if (b[i] == 0 && s[i] == 0) {
					f.push_back(i);
				}
			}

			if (f.empty()) {
				break;
			}

			for (int i=0; i<m; i++) {
				if (b[i] > 0 && s[i] == 0) {
					for (int j : f) {
						b[i] -= abs(i-j);
					}
				}
			}

			while (c[slovo] < (int)f.size()) {
				slovo--;
			}

			for (int i : f)
				s[i] = 'a' + slovo;

			slovo--;
		}

		cout << s << '\n';
	}
}