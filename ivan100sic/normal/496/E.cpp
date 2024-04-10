#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r, t, id;
	bool operator< (const seg& b) const {
		if (l != b.l) {
			return l < b.l;
		}
		return t > b.t;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<seg> a;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		a.push_back({l, r, 0, i});
	}
	int m;
	cin >> m;
	for (int i=0; i<m; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		a.push_back({l, r, k, i});
	}

	sort(a.begin(), a.end());

	vector<int> ans(n);
	map<int, vector<pair<int, int>>> mp;
	for (auto b : a) {
		if (b.t == 0) {
			auto it = mp.lower_bound(b.r);
			if (it == mp.end()) {
				cout << "NO\n";
				return 0;
			}
			ans[b.id] = it->second.back().first;
			if (!--it->second.back().second) {
				it->second.pop_back();
				if (it->second.empty()) {
					mp.erase(it);
				}
			}
		} else {
			mp[b.r].push_back({b.id, b.t});
		}
	}

	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << ans[i]+1 << ' ';
	cout << '\n';
}