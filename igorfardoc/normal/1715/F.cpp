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
const ld dt = 1e-4;
const ld eps = 1e-8;

ld q(vector<pair<ld, ld>> res) {
	cout << "? " << res.size() << '\n';
	for(const auto& el : res) {
		cout << el.first << ' ' << el.second << '\n';
	}
	cout << endl;
	ld ans;
	cin >> ans;
	return ans;
}

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}


vector<pair<ld, ld>> get_rect(int m) {
	vector<pair<ld, ld>> res;
	res.push_back({1000, 0});
	for(int i = 0; i < m; i++) {
		res.push_back({0, i});
		res.push_back({0, i + dt * (i + 1)});
		res.push_back({500, i + dt * (i + 1)});
		res.push_back({500, i + 1});
	}
	res.push_back({1000, m});
	return res;
}

pair<ld, bool> get_mn(ld res, int m) {
	for(int i = 1; i <= m; i++) {
		if(eq(i * dt, res)) return {(i - 2) + i * dt, false};
	}
	for(int i = 0; i < m - 1; i++) {
		if(res < (i + 2) * dt + eps) {
			return {i + res, true};
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cout << fixed << setprecision(10);
	int n, m;
	cin >> n >> m;
	ld x, y;
	auto res = get_mn(q(get_rect(m)), m);
	y = res.first;
	if(!res.second) {
		ld res1 = q({{0, y + 1}, {1000, y + 1}, {1000, y + 2}, {0, y + 2}});
		y += res1;
	}
	auto rct = get_rect(n);
	for(auto& el : rct) {
		swap(el.first, el.second);
	}
	res = get_mn(q(rct), n);
	x = res.first;
	if(!res.second) {
		ld res1 = q({{x + 1, 0}, {x + 1, 1000}, {x + 2, 1000}, {x + 2, 0}});
		x += res1;
	}
	cout << "! " << x << ' ' << y << endl;
}