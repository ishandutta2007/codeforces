// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
		string s;
		cin >> s;
		s = string("R") + s + 'R';
		int n = s.size(), z = 0, q = 0;
		for (int i=0; i<n; i++) {
			if (s[i] == 'R') {
				z = max(z, i-q);
				q = i;
			}
		}
		cout << z << '\n';
	}

}

// I will still practice daily...