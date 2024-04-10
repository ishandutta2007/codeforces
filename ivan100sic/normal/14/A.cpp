// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
string s[55];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int i0=123123,j0=123123,i1=-21,j1=-21;

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		for (int j=0; j<m; j++) {
			if (s[i][j] == '*') {
				i0 = min(i0, i);
				i1 = max(i1, i);

				j0 = min(j0, j);
				j1 = max(j1, j);
			}
		}
	}

	for (int i=i0; i<=i1; i++) {
		cout << s[i].substr(j0, j1-j0+1) << '\n';
	}
}