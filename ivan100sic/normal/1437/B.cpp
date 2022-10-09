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
		string s;
		cin >> n >> s;

		int sol = 1e9;
		for (int p=0; p<2; p++) {
			int c=0, u=0;
			for (int i=0; i<n; i++) {
				if ((s[i] + p) % 2 != i % 2) {
					if (!u) {
						c++;
						u = 1;
					}
				} else {
					u = 0;
				}
			}
			sol = min(sol, c);
		}

		cout << sol << '\n';
	}
}