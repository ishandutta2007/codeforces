#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int> > seg(n);
	forn(i, 0, n) {
		int l, r;
		cin >> l >> r;
		seg[i] = {{l, r}, i};
	}
	sort(all(seg));
	vector<int> ans(n);
	ordered_set<int> right;
	for (int i = n - 1; i >= 0; --i) {
		ans[seg[i].sn] = right.order_of_key(seg[i].fs.sn);
		right.insert(seg[i].fs.sn);
	}
	forn(i, 0, n) cout << ans[i] << '\n';
	return 0;
}