#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		bool f0 = true, f1 = true;
		char c[2] = { 'W', 'R' };
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == '.') continue;
				if (c[(i + j) & 1] != s[j]) f0 = false;
				if (c[1 - ((i + j) & 1)] != s[j]) f1 = false;
			}
		}
		if (!f0 && !f1) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (f0) cout << c[(i + j) & 1];
				else cout << c[1 - ((i + j) & 1)];
			}
			cout << '\n';
		}
	}
	return 0;
}