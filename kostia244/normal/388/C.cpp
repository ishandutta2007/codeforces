//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e2 + 5;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n;
vi a, c;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int ans[2] = {0, 0};
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		c.assign(t, 0);
		for(auto &i:c) cin >> i;
		for(int i = 0; i < t-i-1; i++) {
			ans[0] += c[i], ans[1] += c[t-i-1];
		}
		if(t&1)a.pb(c[t/2]);
	}
	sort(rall(a));
	for(int i = 0; i < a.size(); i++)
		ans[i&1] += a[i];
	cout << ans[0] << " " << ans[1] << "\n";
}