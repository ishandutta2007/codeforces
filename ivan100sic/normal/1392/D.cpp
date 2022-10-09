// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const string LR = "LR";

int dp[200005][4];

int tranz(int old, char c) {
	const int l[4] = {-1, 0, 1, 1};
	const int r[4] = {2, 2, 3, -1};
	return (c == 'L' ? l : r)[old];
}

void mn(int& x, int y) {
	x = min(x, y);
}

int resi(string s) {
	int n = s.size();
	string e = s.substr(s.size() - 2);

	for (int i=0; i<=n+3; i++) {
		fill(dp[i], dp[i]+4, 1e9);
	}

	if (e == "LL") {
		dp[0][0] = 0;;
	} else if (e == "RL") {
		dp[0][1] = 0;
	} else if (e == "LR") {
		dp[0][2] = 0;
	} else {
		dp[0][3] = 0;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<4; j++) {
			// ostajemo isti
			int k = tranz(j, s[i]);
			if (k != -1) {
				mn(dp[i+1][k], dp[i][j]);
			}

			if (i < n-2) {
				// prelazimo u kontra (samo ako je i < n-2)
				k = tranz(j, s[i] ^ 'L' ^ 'R');
				if (k != -1) {
					mn(dp[i+1][k], dp[i][j] + 1);
				}
			}
		}
	}

	return *min_element(dp[n], dp[n]+4);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		int sol = 1e9;
		for (char c0 : LR) {
			for (char c1 : LR) {
				int pr = 0;
				pr += c0 != s[s.size() - 2];
				pr += c1 != s[s.size() - 1];

				string t = s;
				t[t.size() - 2] = c0;
				t[t.size() - 1] = c1;
				pr += resi(t);

				sol = min(sol, pr);
			}
		}

		cout << sol << '\n';
	}
}