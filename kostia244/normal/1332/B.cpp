#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 404, mod = (119<<23)+1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n;
	vi p = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	vi a, c;
	cin >> n;
	c.resize(n);
	a.resize(n);
	for(auto &i : a) cin >> i;
	int l = n, r = 0, cur = 1;
	while(l) {
		r++;
		int used = 0;
		for(int i = 0; i < n; i++) if(!c[i]&&a[i]%p[r]==0){
			c[i] = cur, l--;
			used = 1;
		}
		cur += used;
	}
	cout << cur-1 << '\n';
	for(auto &i : c) cout << i << " ";cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}