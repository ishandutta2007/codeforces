#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
	ordered_set;
// find_by_order(size_t) -> iterator, order_of_key(val) -> size_t

int n, m, q;
int ans[500005];
pair<ll, int> upit[500005];
int c[500005];
ll gaps[500005];
basic_string<int> appear[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	gaps[1] = m;
	for (int i=1; i<=m; i++) {
		gaps[1]--;
		gaps[c[i] + 1]++;
		appear[c[i] + 1] += i;
	}

	for (int i=1; i<=n+1; i++)
		gaps[i] += gaps[i-1];
	for (int i=1; i<=n+1; i++)
		gaps[i] += gaps[i-1];

	for (int i=0; i<q; i++) {
		ll x;
		cin >> x;
		upit[i] = {x, i};
	}
	sort(upit, upit+q);

	int row = 0;
	ordered_set os;
	for (int i=0; i<q; i++) {
		ll z = upit[i].first - n - 1;
		while (row <= n && z >= gaps[row]) {
			row++;
			for (int x : appear[row])
				os.insert(x);
		}
		if (row <= n) {
			ans[upit[i].second] = *os.find_by_order(z - gaps[row-1]);
		} else {
			ans[upit[i].second] = (z - gaps[n]) % m + 1;
		}
	}
	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}