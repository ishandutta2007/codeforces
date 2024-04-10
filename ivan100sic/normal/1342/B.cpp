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
		string s;
		cin >> s;
		int x = count(begin(s), end(s), '0');
		if (x == 0 || x == (int)s.size()) {
			cout << s << '\n';
		} else {
			for (int i=0; i<(int)s.size(); i++)
				cout << "10";
			cout << '\n';
		}
	}
}