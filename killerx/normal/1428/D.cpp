#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	auto FAIL = [&] () {
		printf("-1\n");
		exit(0);
	};
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	rep(i, n) scanf("%d", &v[i]);
	array<set<int>, 4> st;
	rep(i, n) st[v[i]].insert(i);
	int cnt = n;
	vector<pair<int, int> > ans;
	rep(i, n) if (v[i] == 2) {
		auto it = st[1].upper_bound(i);
		if (it != st[1].end()) {
			-- cnt;
			ans.pb(mp(i, cnt));
			ans.pb(mp(*it, cnt));
			st[1].erase(it);
		} else FAIL();
	}
	for (auto i : st[1]) {
		-- cnt;
		ans.pb(mp(i, cnt));
	}
	int cnt2 = 0;
	rep(i, n) if (v[i] == 3) {
		auto it1 = st[1].upper_bound(i);
		auto it2 = st[2].upper_bound(i);
		auto it3 = st[3].upper_bound(i);
		if (it1 != st[1].end() &&
			(it2 == st[2].end() || *it1 < *it2) &&
			(it3 == st[3].end() || *it1 < *it3)) {
			ans.pb(mp(i, cnt2));
			ans.pb(mp(*it1, cnt2));
			++ cnt2;
			st[1].erase(it1);
		} else if (it2 != st[2].end() &&
				(it3 == st[3].end() || *it2 < *it3)) {
			ans.pb(mp(i, cnt2));
			ans.pb(mp(*it2, cnt2));
			++ cnt2;
			st[2].erase(it2);
		} else if (it3 != st[3].end()) {
			ans.pb(mp(i, cnt2));
			ans.pb(mp(*it3, cnt2));
			++ cnt2;
			st[3].erase(it3);
		} else FAIL();
	}
	printf("%d\n", (int) ans.size());
	rep(i, ans.size())
		printf("%d %d\n", ans[i].second + 1, ans[i].first + 1);
	return 0;
}