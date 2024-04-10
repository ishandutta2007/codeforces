// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
string s[105];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}

	bool ok = 1;

	for (int i=0; i<n-1; i++) {
		for (int j=0; j<m; j++) {
			if (s[i][j] == s[i+1][j]) {
				ok = 0;
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m-1; j++) {
			if (s[i][j] != s[i][j+1]) {
				ok = 0;
			}
		}
	}

	cout << (ok ? "YES\n" : "NO\n");
}