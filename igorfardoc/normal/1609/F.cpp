#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T, typename Cmp = less<T>> using ordered_set = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename Cmp = less_equal<T>> using ordered_multiset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename T, typename Cmp = less<K>> using ordered_map = tree<K, T, Cmp, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(), order_of_key()
*/
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int maxn = 1000000;
const ll inf = 2000000000000000000ll;
const int B = 60;
ll a[maxn];
int amount[B];
int n;
ll ans = 0;

void calc(vl& a, int mid, bool lft) {
	int n = a.size();
	vl prefmin(n, inf), prefmax(n, -inf);
	for(int i = mid + 1; i < n; i++) {
		prefmin[i] = min(prefmin[i - 1], a[i]);
		prefmax[i] = max(prefmax[i - 1], a[i]);
	}
	int ptr1 = mid;
	int ptr2 = mid + 1;
	ll mn = inf;
	ll mx = -inf;
	for(int i = mid; i >= 0; i--) {
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		while(ptr2 < n && prefmin[ptr2] > mn) {
			--amount[__builtin_popcountll(prefmin[ptr2])];
			++ptr2;
		}
		if(lft) {
			while(ptr1 < n - 1 && prefmax[ptr1 + 1] <= mx) {
				++amount[__builtin_popcountll(prefmin[ptr1 + 1])];
				++ptr1;
			}
		} else {
			while(ptr1 < n - 1 && prefmax[ptr1 + 1] < mx) {
				++amount[__builtin_popcountll(prefmin[ptr1 + 1])];
				++ptr1;
			}
		}
		if(__builtin_popcountll(mn) == __builtin_popcountll(mx)) {
			ans += min(ptr2 - mid - 1, ptr1 - mid);
		}
		if(ptr1 >= ptr2) {
			ans += amount[__builtin_popcountll(mx)];
		}
	}
	while(ptr1 >= ptr2) {
		--amount[__builtin_popcountll(prefmin[ptr2])];
		++ptr2;
	}
	while(ptr1 < ptr2 - 1) {
		++amount[__builtin_popcountll(prefmin[ptr1 + 1])];
		++ptr1;
	}
}


void rec(int l, int r) {
	if(l == r) {
		++ans;
		return;
	}
	int mid = (l + r) / 2;
	rec(l, mid);
	rec(mid + 1, r);
	vl rs(r - l + 1);
	for(int i = l; i <= r; i++) {
		rs[i - l] = a[i];
	}
	calc(rs, mid - l, true);
	for(int i = r; i >= l; i--) {
		rs[r - i] = a[i];
	}
	calc(rs, r - mid - 1, false);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	rec(0, n - 1);
	cout << ans;
}