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
		cin >> n >> k;
		string s;
		cin >> s;

		vector<int> z(n+1);
		for (int i=0; i<n; i++) {
			if (s[i] == '1') {
				int l = max(0, i-k);
				int r = min(n, i+k+1);
				z[l]++;
				z[r]--;
			}
		}

		for (int i=1; i<=n; i++)
			z[i] += z[i-1];

		int c = 0;
		for (int i=0; i<n; i++) {
			if (z[i] == 0) {
				c++;
				i += k;
			}
		}

		cout << c << '\n';
	}
}