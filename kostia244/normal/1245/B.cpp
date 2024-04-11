#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
//using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 1e9 + 7;
//using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n, a, b, c, res = 0;
	string s, y;
	cin >> n >> a >> b >> c >> s;
	y.resize(n, '.');
	for (int i = 0; i < n; i++) {
		if (s[i] == 'S' && a) {
			a--;
			res++;
			y[i] = 'R';
		}
		if (s[i] == 'R' && b) {
			b--;
			res++;
			y[i] = 'P';
		}
		if (s[i] == 'P' && c) {
			c--;
			res++;
			y[i] = 'S';
		}
	}
	for (int i = 0; i < n; i++) {
		if (y[i] == '.' && a) {
			a--;
			y[i] = 'R';
		}
		if (y[i] == '.' && b) {
			b--;
			y[i] = 'P';
		}
		if (y[i] == '.' && c) {
			c--;
			y[i] = 'S';
		}
	}
	if(n > 2*res)cout << "NO\n";
	else {
		cout << "YES\n" << y << "\n";
	}


}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}