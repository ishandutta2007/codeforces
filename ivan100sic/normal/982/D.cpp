#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
pair<int, int> asrt[100005];

struct areAllEqual {
	multiset<int> s;
	void add(int x) {
		s.insert(x);
	}
	void rem(int x) {
		auto it = s.find(x);
		if (it != s.end())
			s.erase(it);
	}
	bool q() const {
		if (s.size() == 0)
			return 0;
		return *s.begin() == *s.rbegin();
	}
} aae;

set<pair<int, int>> segz;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		asrt[i] = {a[i], i};
	}
	sort(asrt, asrt+n);

	int maxlocs = 0, idx = -1;

	for (int i=0; i<n; i++) {
		int j = asrt[i].second;

		if (segz.size() == 0) {
			segz.insert({j, j});
			aae.add(0);
		} else {
			auto it = segz.lower_bound({j, j});

			int jl = j, jr = j;

			if (it != segz.end()) {
				if (it->first == j+1) {
					jr = it->second;
					aae.rem(it->second - it->first);
					segz.erase(it);
				}
			}

			it = segz.lower_bound({j, j});

			if (it != segz.begin()) {
				--it;
				if (it->second == j-1) {
					jl = it->first;
					aae.rem(it->second - it->first);
					segz.erase(it);
				}
			}

			segz.insert({jl, jr});
			aae.add(jr - jl);
		}

		if (aae.q()) {
			if ((int)segz.size() > maxlocs) {
				maxlocs = segz.size();
				idx = asrt[i].first + 1;
			}
		}
	}

	if (idx == -1)
		idx = asrt[n-1].first + 1;

	cout << idx << '\n';
}