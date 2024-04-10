#include <bits/stdc++.h>
using namespace std;

bool moze[1005];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k >> n;
	k--;

	fill(moze+1, moze+101, true);

	for (int i=1; i<=n; i++) {
		int stan, sprat;
		cin >> stan >> sprat;
		stan--;
		sprat--;

		for (int j=1; j<=100; j++) {
			if (stan / j != sprat) {
				moze[j] = false;
			}
		}
	}

	set<int> sol;

	for (int i=1; i<=100; i++) {
		if (moze[i]) {
			sol.insert(k / i);
		}
	}

	if (sol.size() == 0 || sol.size() > 1) {
		cout << -1;
		return 0;
	}

	cout << *sol.begin() + 1;
}