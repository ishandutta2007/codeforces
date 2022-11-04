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



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi c(1 << n);
	for(int i = 0; i < 1 << n; i++) {
		c[i] = (s[i] - 'a');
	}
	for(int i = 1; i <= n; i++) {
		vector<array<int, 3>> arr;
		for(int j = 0; j < 1 << n; j++) {
			arr.push_back({c[j], c[j ^ (1 << (i - 1))], j});
		}
		sort(arr.begin(), arr.end());
		vi cnew(1 << n);
		int now = 0;
		for(int j = 0; j < 1 << n; j++) {
			if(j == 0 || (arr[j][0] == arr[j - 1][0] && arr[j][1] == arr[j - 1][1])) {
				cnew[arr[j][2]] = now;
			} else {
				cnew[arr[j][2]] = ++now;
			}
		}
		swap(c, cnew);
	}
	string t = s;
	int bst = 0;
	for(int i = 0; i < 1 << n; i++) {
		if(c[i] == 0) bst = i;
	}
	for(int i = 0; i < 1 << n; i++) {
		t[i] = s[i ^ bst];
	}
	cout << t;
}