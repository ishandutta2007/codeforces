#include <bits/stdc++.h>
using namespace std;

inline bool solve() {
	int n; string s, t;
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++) 
		if (s[i] == '1' && t[i] == '1') return 1;
	return 0;
}

signed main() {
	int t;
	for (cin >> t; t --; ) {
		cout << (solve() ? "NO\n" : "YES\n");
	}
}