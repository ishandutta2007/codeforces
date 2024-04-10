#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
int n;
int c[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	vector<pair<int, int>> st;
	int q;
	cin >> q;
	vector<int> upiti(q);
	unordered_map<int, vector<int>> mp;
	for (int i=0; i<q; i++) {
		string s;
		cin >> s;
		int x = 0;
		for (char y : s)
			x |= 1 << (y - 'a');
		upiti[i] = x;
		mp[x] = {};
	}

	st.push_back({0, 0});
	for (int r=1; r<=n; r++) {
		int v = 1 << (s[r-1] - 'a');
		st.push_back({r-1, v});
		for (auto& t : st)
			t.second |= v;
		int j = 1;
		for (int i=1; i<(int)st.size(); i++) {
			if (st[i].second != st[j-1].second) {
				st[j++] = st[i];
			}
		}

		st.resize(j);

		for (auto [l, x] : st) {
			auto it = mp.find(x);
			if (it != mp.end()) {
				it->second.push_back(l);
			}
		}
	}

	map<int, int> cache;

	for (int x : upiti) {
		if (cache.count(x)) {
			cout << cache[x] << '\n';
		} else {
			auto it = mp.find(x);
			int a = 0;
			for (int x : it->second)
				a += 1 - c[x], c[x] = 1;
			for (int x : it->second)
				c[x] = 0;
			cout << (cache[x] = a) << '\n';
		}
	}
}