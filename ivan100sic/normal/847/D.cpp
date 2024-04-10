#include <bits/stdc++.h>
using namespace std;

int n, k, sol;
int a[200005];
int b[200005];

map<int, vector<int>> mp;
int inside = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	if (k == 1) {
		cout << 0;
		return 0;
	}

	for (int i=1; i<=n; i++) {
		b[i] = a[i] - i;
		mp[b[i]].push_back(i);
	}

	if (a[1] < k) {
		inside = 1;
		sol = 1;
	}

	for (int stop=2; stop<k && stop<=n; stop++) {
		// izbaci ove bezveze
		for (int x : mp[k - stop]) {
			if (x >= stop) {
				break;
			}
			inside--;
		}

		// ubaci ovog ako je dobar
		if (b[stop] < k - stop) {
			inside++;
		}

		sol = max(sol, inside);
	}

	cout << sol;



}