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

struct Node {
	int amount;
	int add;
	ll sum;
};

const int N = 200000;
int q, d;
Node t[4 * N + 15];

inline void update(int now, int l, int r) {
	if(l == r) return;
	t[now].amount = t[now * 2].amount + t[now * 2 + 1].amount;
	t[now].sum = t[now * 2].sum + t[now * 2 + 1].sum;
}

inline void push(int now, int l, int r) {
	t[now].sum += (ll)t[now].amount * t[now].add;
	if(l == r) {
		t[now].add = 0;
		return;
	}
	t[now * 2].add += t[now].add;
	t[now * 2 + 1].add += t[now].add;
	t[now].add = 0;
}

void update_value(int now, int l, int r, int pos, int value) {
	push(now, l, r);
	if(l > pos || r < pos) return;
	if(l == r) {
		t[now].sum = value;
		t[now].amount = 1;
		return;
	}
	int mid = (l + r) / 2;
	update_value(now * 2, l, mid, pos, value);
	update_value(now * 2 + 1, mid + 1, r, pos, value);
	update(now, l, r);
}

void delete_value(int now, int l, int r, int pos) {
	push(now, l, r);
	if(l > pos || r < pos) return;
	if(l == r) {
		t[now].sum = 0;
		t[now].amount = 0;
		return;
	}
	int mid = (l + r) / 2;
	delete_value(now * 2, l, mid, pos);
	delete_value(now * 2 + 1, mid + 1, r, pos);
	update(now, l, r);
}

void update_add(int now, int l, int r, int l1, int r1, int add) {
	push(now, l, r);
	if(l1 > r || l > r1 || l1 > r1) return;
	if(l1 <= l && r <= r1) {
		t[now].add += add;
		push(now, l, r);
		return;
	}
	int mid = (l + r) / 2;
	update_add(now * 2, l, mid, l1, r1, add);
	update_add(now * 2 + 1, mid + 1, r, l1, r1, add);
	update(now, l, r);
}

ll get_sum(int now, int l, int r, int l1, int r1) {
	push(now, l, r);
	if(l1 > r || l > r1 || l1 > r1) return 0;
	if(l1 <= l && r <= r1) return t[now].sum;
	int mid = (l + r) / 2;
	return get_sum(now * 2, l, mid, l1, r1) +
		   get_sum(now * 2 + 1, mid + 1, r, l1, r1);
}

int get_amount(int now, int l, int r, int l1, int r1) {
	push(now, l, r);
	if(l1 > r || l > r1 || l1 > r1) return 0;
	if(l1 <= l && r <= r1) return t[now].amount;
	int mid = (l + r) / 2;
	return get_amount(now * 2, l, mid, l1, r1) +
		   get_amount(now * 2 + 1, mid + 1, r, l1, r1);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> q >> d;
	ll ans = 0;
	for(int i = 0; i < q; i++) {
		int a;
		cin >> a;
		if(get_amount(1, 1, N, a, a)) {
			int vl = get_sum(1, 1, N, a, a);
			ans -= (ll)vl * (vl - 1) / 2;
			delete_value(1, 1, N, a);
			ll sm = get_sum(1, 1, N, a + 1, a + d);
			int am = get_amount(1, 1, N, a + 1, a + d);
			ans -= sm - am;
			update_add(1, 1, N, a + 1, a + d, -1);
		} else {
			int am = get_amount(1, 1, N, a - d, a - 1);
			ans += (ll)am * (am - 1) / 2;
			update_value(1, 1, N, a, am);
			ll sm = get_sum(1, 1, N, a + 1, a + d);
			ans += sm;
			update_add(1, 1, N, a + 1, a + d, 1);
		}
		cout << ans << '\n';
	}
}