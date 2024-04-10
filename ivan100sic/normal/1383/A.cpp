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
		string a, b;
		cin >> n >> a >> b;

		int c[20][20];
		memset(c, 0, sizeof c);

		bool ok = 1;

		for (int i=0; i<n; i++) {
			if (a[i] > b[i]) {
				ok = false;
				break;
			} else if (a[i] < b[i]) {
				c[a[i]-'a'][b[i]-'a'] = 1;
				c[b[i]-'a'][a[i]-'a'] = 1;
			}
		}

		if (!ok) {
			cout << "-1\n";
			continue;
		}

		for (int i=0; i<20; i++) {
			c[i][i] = 1;
		}

		for (int i=0; i<20; i++) {
			for (int j=0; j<20; j++) {
				for (int k=0; k<20; k++) {
					c[j][k] |= c[j][i] && c[i][k];
				}
			}
		}

		set<vector<int>> s;
		for (int i=0; i<20; i++) {
			s.insert(vector<int>(c[i], c[i]+20));
		}

		cout << 20 - s.size() << '\n';
	}
}