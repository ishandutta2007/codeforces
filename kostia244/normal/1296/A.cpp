#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e5 + 555, mod = (119<<23)+1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
	int n, sm = 0;
	int c[2] = {0, 0};
	cin >> n;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		c[t&1]++;
		sm ^= t;
	}
	cout << (((sm&1)||(c[0]&&c[1]))?"YES":"NO") << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}