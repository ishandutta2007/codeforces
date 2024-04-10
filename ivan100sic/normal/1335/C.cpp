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
		map<int, int> mp;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}
		int h = 0;
		for (auto [x, y] : mp) {
			h = max(h, y);
		}

		int u = mp.size();
		int z = max(min(u-1, h), min(u, h-1));
		cout << z << '\n';
	}
}