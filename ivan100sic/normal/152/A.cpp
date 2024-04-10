#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s[105];
char c[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			c[j] = max(c[j], s[i][j]);

	int k = 0;
	for (int i=0; i<n; i++) {
		int z = 0;
		for (int j=0; j<m; j++) {
			if (s[i][j] == c[j])
				z = 1;
		}
		k += z;
	}
	cout << k << '\n';
}