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
		int n, z=0;
		cin >> n;
		map<char, int> c;
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			for (char x : s) {
				c[x]++;
			}
		}
		for (auto [x, y] : c) {
			z += y % n;
		}
		cout << (z == 0 ? "YES\n" : "NO\n");
	}
}