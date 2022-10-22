#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	ll sum = 0;
	ll cnt = 0;
	for(int i = 0; i < k; ++i) {
		int a,b;
		cin >> a >> b;
		sum += (ll)a * b;
		cnt += b;
	}
	ll res = (ll)n * (n + 1) / 2;
	if((cnt == n && sum % n != res % n) || cnt > n) {
		cout << "-1";
	} else {
		cout << "1";
	}
}