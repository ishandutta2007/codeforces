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
	string s;

	cin >> n >> s;
	if (count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')')) {
		cout << "-1\n";
		return 0;
	}

	int x = 0, sol = 0, q = 0;
	for (int i=0; i<n; i++) {
		int y = x + (s[i] == '(' ? 1 : -1);
		if (y == 0 && x < 0) {
			sol += q + 1;
			q = 0;
		} else if (y == 0 && x > 0) {
			q = 0;
		} else {
			q++;
		}
		x = y;
	}
	cout << sol << '\n';
}