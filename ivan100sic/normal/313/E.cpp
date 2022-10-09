#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;

struct cycms {
	multiset<pair<int, int>> ms;

	void insert(pair<int, int> x) {
		ms.insert(x);
	}

	void erase(pair<int, int> x) {
		ms.erase(ms.find(x));
	}

	pair<int, int> seek(pair<int, int> x) {
		auto it = ms.lower_bound(x);
		if (it == ms.begin()) {
			return *prev(ms.end());
		} else {
			return *prev(it);
		}
	}
};

vector<int> sol;
int ao[100005], bo[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	cycms a;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		ao[i] = x;
		a.insert({x, i});
	}
	vector<pair<int, int>> toinsert;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		x = m-1-x;
		bo[i] = x;
		auto g = a.seek({x, 123123123});
		if (g.first == x) {
			a.erase(g);
			sol.push_back(m-1);
		} else {
			toinsert.emplace_back(x, i+n);
		}
	}

	for (auto p : toinsert)
		a.insert(p);

	set<array<int, 3>> pq;	
	map<int, int> semafor;

	for (auto [x, y] : a.ms) {
		if (y < n)
			continue;
		auto [p, q] = a.seek({x, y});

		if (q >= n) {
			semafor[q] = y;
		} else {
			pq.insert({(m+x-p)%m, y, q});
		}
	}

	// cerr << pq.size() << '\n';

	while (pq.size()) {
		auto [d, yy, tgt] = *pq.begin();
		pq.erase(pq.begin());
		sol.push_back(m-1-d);

		a.erase({ao[tgt], tgt});
		a.erase({bo[yy-n], yy});

		if (semafor.count(yy)) {
			int i = semafor[yy];
			int x = bo[i-n], y = i;

			// cerr << "semafor me ceka " << yy << ' ' << i << '\n';

			auto [p, q] = a.seek({x, y});
			if (q >= n) {
				semafor[q] = y;
			} else {
				pq.insert({(m+x-p)%m, y, q});
			}
		}
	}

	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}