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

	string s, a[5];
	cin >> s >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	for (string p : a) {
		if (p[0] == s[0] || p[1] == s[1]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}