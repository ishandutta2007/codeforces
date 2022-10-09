#include <bits/stdc++.h>
using namespace std;

int sumd(int x) {
	int r = 0;
	while (x > 0) {
		r += x % 10;
		x /= 10;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<int> sol;

	int n;
	cin >> n;

	for (int i=n-1; i>=n-200; i--) {
		if (i < 0) {
			break;
		}
		if (i + sumd(i) == n) {
			sol.push_back(i);
		}
	}
	cout << sol.size() << '\n';
	sort(sol.begin(), sol.end());
	for (int x : sol) {
		cout << x << '\n';
	}
}