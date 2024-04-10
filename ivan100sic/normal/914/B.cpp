#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	map<int, int> mp;

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;

		mp[-x]++;
	}

	for (auto p : mp) {
		if (p.second % 2) {
			cout << "Conan\n";
			return 0;
		}
	}

	cout << "Agasa\n";

}