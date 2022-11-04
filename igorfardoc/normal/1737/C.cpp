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
int n;

void turn(vector<array<int, 2>>& a, int& r, int& c) {
	map<int, int> am1;
	map<int, int> am2;
	int mnx = 1000000;
	int mny = 1000000;
	for(int i = 0; i < 3; i++) {
		++am1[a[i][0]];
		++am2[a[i][1]];
		mnx = min(mnx, a[i][0]);
		mny = min(mny, a[i][1]);
	}
	int x;
	int y;
	for(const auto& el : am1) {
		if(el.second == 1) x = el.first;
	}
	for(const auto& el : am2) {
		if(el.second == 1) y = el.first;
	}
	if(x == mnx && y == mny) return;
	for(int i = 0; i < 3; i++) {
		int xbef = a[i][0];
		int ybef = a[i][1];
		a[i] = (array<int, 2>){ybef, n + 1 - xbef};
	}
	int xbef = r;
	int ybef = c;
	r = ybef;
	c = n + 1 - xbef;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		map<int, int> am1;
		map<int, int> am2;
		vector<array<int, 2>> a(3);
		for(int i = 0; i < 3; i++) {
			cin >> a[i][0] >> a[i][1];
		}
		int r, c;
		cin >> r >> c;
		for(int i = 0; i < 3; i++) {
			turn(a, r, c);
		}
		int mnx = 1000000;
		int mny = 1000000;
		for(int i = 0; i < 3; i++) {
			mnx = min(mnx, a[i][0]);
			mny = min(mny, a[i][1]);
		}
		int x = mnx;
		int y = mny;
		if(mnx == n - 1 && mny == n - 1) {
			if(r == n || c == n) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
			continue;
		}
		if(abs(r - x) % 2 == 0 && abs(c - y) % 2 == 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}

}