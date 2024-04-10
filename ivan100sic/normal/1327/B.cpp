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
		int n, p=0, uu=0;
		cin >> n;
		string u(n+1, 0);
		for (int i=0; i<n; i++) {
			int k, f = 0;
			cin >> k;
			while (k--) {
				int x;
				cin >> x;
				if (!f && !u[x]) {
					f = u[x] = 1;
				}
			}
			if (!f && !p) {
				p = 1;
				uu = i+1;
			}
		}

		if (!p)
			cout << "OPTIMAL\n";
		else
			cout << "IMPROVE\n" << uu << ' ' << (find(u.begin() + 1, u.end(), 0) - u.begin()) << '\n';
	}
}

// I will still practice daily...