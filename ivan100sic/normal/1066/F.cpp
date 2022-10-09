#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first - a.second < b.first - b.second;
}

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

map<int, vector<pair<int, int>>> e;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[max(x, y)].push_back({x, y});
	}

	e[0].push_back({0, 0});

	for (auto& p : e) {
		sort(p.second.begin(), p.second.end(), cmp);
	}

	ll dpold0 = 0;
	ll dpold1 = 0;

	auto it1 = e.begin();
	auto it2 = next(it1);

	while (it2 != e.end()) {
		auto old0 = it1->second[0];
		auto old1 = it1->second.back();
		auto new0 = it2->second[0];
		auto new1 = it2->second.back();

		ll dpnu0 = min(dpold0 + dist(old0, new1), dpold1 + dist(old1, new1));
		ll dpnu1 = min(dpold0 + dist(old0, new0), dpold1 + dist(old1, new0));

		dpold0 = dpnu0 + dist(new0, new1);
		dpold1 = dpnu1 + dist(new0, new1);

		++it1;
		++it2;
	}

	cout << min(dpold0, dpold1) << '\n';

}