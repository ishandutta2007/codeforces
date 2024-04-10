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

	map<int, int> mp;
	int n, m;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		mp[x] = max(mp[x], y);
	}
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		mp[x] = max(mp[x], y);
	}
	ll z = 0;
	for (auto p : mp)
		z += p.second;
	cout << z << '\n';
}