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
	string z;
	int n;
	cin >> n >> z;
	map<pair<int, int>, int> a;
	int l = -1, r = 1<<20;
	int x = 0, y = 0, m = 0;
	a[{0, 0}] = 0;
	for(auto i : z) {
		m++;
		if(i=='L') x--;
		if(i=='R') x++;
		if(i=='D') y--;
		if(i=='U') y++;
//		cout << x << " " << y << "\n";
		if(a.count({x, y})&&m-a[{x, y}]<r-l) l = a[{x, y}], r = m;
		a[{x, y}] = m;
	}
	if(r-l>z.size()) cout << "-1\n";
	else cout << l+1 << " " << r << "\n";
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