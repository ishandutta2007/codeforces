#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n, k;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	string s;
	cin >> s;
	map<string, int> mp;
	for (int i = 0; i < n - 1; i++) {
		mp[s.substr(i, 2)]++;
	}

	int mx = 0;
	for (auto p : mp) {
		mx = max(mx, p.second);
	}

	for (auto p : mp) {
		if (p.second == mx) {
			cout << p.first;
			return;
		}
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}