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
const int maxn = 100;

bool dp[maxn + 1][maxn + 1][2][2]; // am0, am1, chet, who

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			dp[0][0][i][j] = 1 - i;
		}
	}
	for(int i = 0; i <= maxn; i++) {
		for(int j = 0; j <= maxn; j++) {
			if(i == 0 && j == 0) continue;
			for(int k = 0; k < 2; k++) {
				for(int l = 0; l < 2; l++) {
					if(l == 0) {
						if(i != 0 && dp[i - 1][j][k][1 - l]) {
							dp[i][j][k][l] = 1;
							continue;
						}
						if(j != 0 && dp[i][j - 1][1 - k][1 - l]) {
							dp[i][j][k][l] = 1;
							continue;
						}
					} else {
						dp[i][j][k][l] = 1;
						if(i != 0 && !dp[i - 1][j][k][1 - l]) {
							dp[i][j][k][l] = 0;
							continue;
						}
						if(j != 0 && !dp[i][j - 1][k][1 - l]) {
							dp[i][j][k][l] = 0;
							continue;
						}
					}
				}
			}
		}
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int am0 = 0;
		int am1 = 0;
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if(a % 2 == 0) {
				++am0;
			} else {
				++am1;
			}
		}
		if(dp[am0][am1][0][0]) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}

}