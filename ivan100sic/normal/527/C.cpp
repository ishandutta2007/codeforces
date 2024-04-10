#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct cutset {
	set<pair<int, int>> poc, len;

	cutset(int w) {
		poc.insert({0, w});
		len.insert({w, 0});
	}

	void cut(int y) {
		auto it = prev(poc.upper_bound({y, -1}));
		auto [x, w] = *it;
		poc.erase(it);
		poc.insert({x, y-x});
		poc.insert({y, w-(y-x)});
		len.erase({w, x});
		len.insert({y-x, x});
		len.insert({w-(y-x), y});
	}

	int naj() {
		return len.rbegin()->first;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int w, h, n;
	cin >> w >> h >> n;
	cutset hor(h), ver(w);
	while (n--) {
		char x; int y;
		cin >> x >> y;
		(x == 'H' ? hor : ver).cut(y);
		cout << hor.naj() * 1ll * ver.naj() << '\n';
	}
}