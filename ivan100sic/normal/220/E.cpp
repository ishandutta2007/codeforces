// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
	ordered_set;
// find_by_order(size_t) -> iterator, order_of_key(val) -> size_t

int n, l, r;
ll k, inv, sol;
int a[100005];
int pref[100005], suff[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	ordered_set os, ls, rs;
	for (int i=1; i<=n; i++) {
		os.insert({a[i], i});
		pref[i] = pref[i-1] + i - os.order_of_key({a[i], 123123123});
	}

	os.clear();
	for (int i=n; i>=1; i--) {
		suff[i] = suff[i+1] + os.order_of_key({a[i], -1});
		os.insert({a[i], i});
	}
	os.clear();

	l = 1;
	r = n + 1;
	inv = 0;
	ls.insert({a[1], 1});

	while (1) {
		if (l == r-1) {
			break;
		}

		ll newinv = inv - suff[r] + suff[r-1] + (a[1] > a[r-1]);
		if (newinv <= k) {
			r--;
			rs.insert({a[r], r});
			inv = newinv;
		} else {
			break;
		}
	}


	auto incr = [&]() {
		inv = inv - suff[r] + suff[r+1] - l + ls.order_of_key({a[r], 123123123});
		rs.erase({a[r], r});
		r++;
	};

	sol += n-r+1;
	while (l+1 < n) {
		l++;
		inv += pref[l] - pref[l-1] + rs.order_of_key({a[l], -1});
		ls.insert({a[l], l});

		// povecavaj r sve dok ne proradi
		while (r <= n && inv > k) {
			incr();
		}

		if (l == r) incr();

		sol += n-r+1;
	}

	cout << sol << '\n';
}