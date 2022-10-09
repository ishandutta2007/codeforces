#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s[1005];
int r[1005], c[1005], t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (s[i][j] == '*') {
				r[i]++;
				c[j]++;
				t++;
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int z = r[i] + c[j] - (s[i][j] == '*');
			if (z == t) {
				cout << "YES\n" << i+1 << ' ' << j+1 << '\n';
				return 0;
			}
		}
	}
	cout << "NO\n";
}