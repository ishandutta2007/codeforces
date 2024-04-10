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
		int n;
		cin >> n;
		vector<string> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		bool f = 0;
		for (int i=0; i<2 && !f; i++) {
			for (int j=0; j<2 && !f; j++) {
				for (int k=0; k<2 && !f; k++) {
					for (int l=0; l<2 && !f; l++) {
						if (i+j+k+l <= 2) {
							bool p = (a[0][1] == '1') ^ i;
							bool q = (a[1][0] == '1') ^ j;
							bool r = (a[n-1][n-2] == '1') ^ k;
							bool s = (a[n-2][n-1] == '1') ^ l;

							if (p == q && r == s && p != r) {
								f = 1;
								vector<pair<int, int>> v;
								if (i) v.emplace_back(0, 1);
								if (j) v.emplace_back(1, 0);
								if (k) v.emplace_back(n-1, n-2);
								if (l) v.emplace_back(n-2, n-1);

								cout << v.size() << "\n";
								for (auto [x, y] : v) {
									cout << x+1 << ' ' << y+1 << '\n';
								}
								break;
							}
						}
					}
				}
			}
		}
	}
}