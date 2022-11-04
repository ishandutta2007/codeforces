#include<bits/stdc++.h>
#define x1 x4
#define y1 y4
#define x2 x5
#define y2 y5
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
int n, k;
const int maxn = 500;
int a[maxn][maxn];
int pref[maxn + 1][maxn + 1];
int x1[maxn * maxn + 1];
int x2[maxn * maxn + 1];
int y1[maxn * maxn + 1];
int y2[maxn * maxn + 1];

void add(int x1, int y1, int x2, int y2) {
	if(x1 > x2 || y1 > y2) return;
	++pref[x2 + 1][y2 + 1];
	--pref[x2 + 1][y1];
	--pref[x1][y2 + 1];
	++pref[x1][y1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> k;
	for(int i = 1; i <= n * n; i++) {
		x1[i] = y1[i] = maxn;
		x2[i] = y2[i] = -1;
	}
	set<int> s;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			x1[a[i][j]] = min(x1[a[i][j]], i);
			y1[a[i][j]] = min(y1[a[i][j]], j);
			x2[a[i][j]] = max(x2[a[i][j]], i);
			y2[a[i][j]] = max(y2[a[i][j]], j);
			s.insert(a[i][j]);
		}
	}
	if(s.size() == k) {
		cout << 0;
		return 0;
	}
	if(s.size() < k) {
		cout << k - s.size();
		return 0;
	}
	bool ok = false;
	for(int len = 1; len <= n; len++) {
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= n; j++) {
				pref[i][j] = 0;
			}
		}
		for(int col = 1; col <= n * n; col++) {
			if(x2[col] == -1) continue;
			if(x2[col] - x1[col] + 1 > len || y2[col] - y1[col] + 1 > len) continue;
			int a = max(0, x2[col] - len + 1);
			int b = max(0, y2[col] - len + 1);
			int c = min(x1[col], n - len);
			int d = min(y1[col], n - len);
			add(a, b, c, d);
		}
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= n; j++) {
				if(i > 0) pref[i][j] += pref[i - 1][j];
				if(j > 0) pref[i][j] += pref[i][j - 1];
				if(i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
			}
		}
		for(int i = 0; i < n - len + 1; i++) {
			for(int j = 0; j < n - len + 1; j++) {
				int here = pref[i][j];
				if(s.size() - here == k || s.size() - here + 1 == k) {
					ok = true;
				}
			}
		}
		if(ok) break;
	}
	if(ok) {
		cout << 1;
	} else {
		cout << 2;
	}

}