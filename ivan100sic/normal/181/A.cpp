#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, x=0, y=0;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		for (int j=1; j<=m; j++) {
			if (s[j-1] == '*') {
				x ^= i;
				y ^= j;
			}
		}
	}
	cout << x << ' ' << y << '\n';
}