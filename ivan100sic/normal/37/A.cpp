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

	int n;
	cin >> n;
	map<int, int> mp;
	while (n--) {
		int x;
		cin >> x;
		mp[x]++;
	}
	int y = 0;
	for (auto p : mp)
		y = max(y, p.second);
	cout << y << ' ' << mp.size() << '\n';
}