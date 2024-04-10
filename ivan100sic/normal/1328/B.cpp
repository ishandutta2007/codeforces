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
		int n, k;
		cin >> n >> k;
		for (int u=n-2; u>=0; u--) {
			int c = n-1-u;
			if (k <= c) {
				string s(n, 'a');
				s[u] = s[n-k] = 'b';
				cout << s << '\n';
				break;
			} else {
				k -= c;
			}
		}
	}
}

// I will still practice daily...