#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005][3];
basic_string<int> e[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<pair<int, int>, int> mp;

	cin >> n;
	for (int i=0; i<n-2; i++) {
		for (int j=0; j<3; j++)
			cin >> a[i][j];
		
		sort(a[i], a[i]+3);
		mp[{a[i][0], a[i][1]}]++;
		mp[{a[i][1], a[i][2]}]++;
		mp[{a[i][0], a[i][2]}]++;
	}

	for (auto [p, c] : mp) {
		if (c == 2) {
			auto [u, v] = p;
			e[u] += v;
			e[v] += u;
		}
	}

	int x = 1;
	for (int i=1; i<=n; i++)
		if (e[i].size() == 1)
			x = i;

	int y = e[x][0], p = x;
	basic_string<int> sol = {x, y};
	while (e[y].size() == 2) {
		int t = p;
		p = y;
		y = e[y][0] ^ e[y][1] ^ t;
		sol += y;
	}

	int xx = -1, yy = -1;
	for (int i=0; i<n-2; i++) {
		set<int> s(a[i], a[i]+3);
		if (s.count(x) && s.count(e[x][0])) {
			int t = a[i][0] ^ a[i][1] ^ a[i][2] ^ x ^ e[x][0];
			if (e[t].size() == 0)
				xx = t;
		} 

		if (s.count(y) && s.count(e[y][0])) {
			int t = a[i][0] ^ a[i][1] ^ a[i][2] ^ y ^ e[y][0];
			if (e[t].size() == 0)
				yy = t;
		}
	}

	sol = basic_string<int>(1, xx) + sol + yy;

	for (int x : sol)
		cout << x << ' ';
	cout << '\n';

}