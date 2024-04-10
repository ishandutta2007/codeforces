// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
string s[55];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> s[i];

		bool ok = 1;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				bool p = 0;
				if (i == n-1 || s[i+1][j] == '1')
					p = 1;
				if (j == n-1 || s[i][j+1] == '1')
					p = 1;
				if (s[i][j] == '0')
					p = 1;

				if (!p)
					ok = 0;
			}
		}

		cout << (ok ? "yes\n" : "No\n");
	}
}