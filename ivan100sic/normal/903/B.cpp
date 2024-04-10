#include <bits/stdc++.h>
using namespace std;

int h1, a1, c1, h2, a2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> h1 >> a1 >> c1 >> h2 >> a2;

	vector<string> sol;

	while (h2 > 0) {
		// da li smem da ga udarim?
		if (h1 > a2 || h2 - a1 <= 0) {
			h1 -= a2;
			h2 -= a1;
			sol.push_back("STRIKE");
		} else {
			// pijem caj
			h1 += c1;
			h1 -= a2;
			sol.push_back("HEAL");
		}
	}

	cout << sol.size() << '\n';
	for (string s : sol) {
		cout << s << '\n';
	}

}