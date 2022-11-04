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

int q(vi s) {
	for(int i = 0; i < s.size(); i++) {
		if(s[i]) {
			cout << 'T';
		} else {
			cout << 'F';
		}
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vi a(n, 1);
	vi b(n, 0);
	for(int i = 0; i < n; i+=2) {
		b[i] = 1;
	}
	int a1 = q(a);
	if(a1 == n) return 0;
	int b1 = q(b);
	if(b1 == n) return 0;
	int ptr = 0;
	while(ptr + 3 <= n) {
		a[ptr] = 1 - a[ptr];
		a[ptr + 1] = 1 - a[ptr + 1];
		int rs = q(a);
		if(rs == n) return 0;
		if(rs > a1) {
			a1 = rs;
			ptr += 2;
		} else if(rs < a1) {
			a[ptr] = 1 - a[ptr];
			a[ptr + 1] = 1 - a[ptr + 1];
			ptr += 2;
		} else {
			auto c = b;
			c[ptr] = 1 - c[ptr];
			c[ptr + 1] = 1 - c[ptr + 1];
			c[ptr + 2] = 1 - c[ptr + 2];
			int rs = q(c);
			if(rs == n) return 0;
			int newa = a1;
			if(rs > b1) {
				if(a[ptr] != c[ptr]) ++newa;
				a[ptr] = c[ptr];
				if(a[ptr + 1] != c[ptr + 1]) ++newa;
				a[ptr + 1] = c[ptr + 1];
			} else {
				if(a[ptr] != 1 - c[ptr]) ++newa;
				a[ptr] = 1 - c[ptr];
				if(a[ptr + 1] != 1 - c[ptr + 1]) ++newa;
				a[ptr + 1] = 1 - c[ptr + 1];
			}
			if(rs - b1 == 3 || rs - b1 == -1) {
				if(a[ptr + 2] != c[ptr + 2]) ++newa;
				a[ptr + 2] = c[ptr + 2];
			} else {
				if(a[ptr + 2] != 1 - c[ptr + 2]) ++newa;
				a[ptr + 2] = 1 - c[ptr + 2];
			}
			a1 = newa;
			ptr += 3;
		}
	}
	while(ptr < n) {
		a[ptr] = 1 - a[ptr];
		int rs = q(a);
		if(rs == n) return 0;
		if(rs > a1) {
			a1 = rs;
		} else {
			a[ptr] = 1 - a[ptr];
		}
		++ptr;
	}
	q(a);
}