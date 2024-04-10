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

	string s;
	cin >> s;

	int n = s.size();

	// proveri ima li resenja
	if  (count(s.begin(), s.end(), s[0]) >= n-n%2) {
		cout << "Impossible\n";
		return 0;
	}

	for (int i=1; i<n; i++) {
		string p = s.substr(0, i);
		string q = s.substr(i);
		p = q + p;
		string r = p;
		reverse(r.begin(), r.end());
		if (r == p && r != s) {
			cout << "1\n";
			return 0;
		}
	}

	cout << "2\n";
}