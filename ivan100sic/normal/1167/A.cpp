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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		while (s.size() && s[0] != '8')
			s = s.substr(1);
		if (s.size() < 11) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}