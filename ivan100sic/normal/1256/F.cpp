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

	int q;
	cin >> q;
	while (q--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		map<char, int> c;
		for (char x : s)
			c[x]++;
		int ok = 0;
		for (auto [x, y] : c) {
			if (y > 1) {
				ok = 1;
			}
		}
		for (char x : t)
			c[x]--;
		int no = 0;
		for (auto [x, y] : c) {
			if (y) {
				no = 1;
				cout << "NO\n";
				break;
			}
		}
		if (no)
			continue;
		if (ok) {
			cout << "YES\n";
			continue;
		}

		int u = 0;
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				u += (s[i] > s[j]) + (t[i] > t[j]);
		cout << (u%2 ? "NO\n" : "YES\n");
	}
}