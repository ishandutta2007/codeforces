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

	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		if (k == 2 && s[0] >= s[1]) {
			cout << "NO\n";
		} else {
			cout << "YES\n2\n" << s.substr(0, 1) << ' ' << s.substr(1) << '\n';
		}
	}
}