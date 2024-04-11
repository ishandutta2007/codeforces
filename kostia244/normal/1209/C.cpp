#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<20, mod = 998244353, rt = 565042129, i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool check(vi &a, vi & b) {
	vi r;
	for(int i = 0; i < a.size(); i++) if(b[i] == 1) r.pb(a[i]);
	for(int i = 0; i < a.size(); i++) if(b[i] == 2) r.pb(a[i]);
	return is_sorted(all(r));
}
void solve() {
	int n;
	cin >> n;
	vi a(n);
	char t;
	for(auto &i : a) {
		cin >> t;
		i = t-'0';
	}
	for(int x = 0; x < 10; x++) {
		int sbx = 1, sax = 1, lbx = -1;
		for(int lst = -1, i = 0; i < n; i++) {
			if(a[i] >= x) continue;
			if(a[i] < lst) sbx = 0;
			lst = a[i];
			lbx = i;
		}
		for(int lst = -1, i = 0; i < n; i++) {
			if(a[i] <= x) continue;
			if(a[i] < lst) sax = 0;
			lst = a[i];
		}
		if(!sax||!sbx) continue;
		vi col(n, 2);
		for(int i = 0; i < n; i++) if(a[i] < x) col[i] = 1;
		for(int i = lbx+1; i < n; i++) if(a[i] == x) col[i] = 1;
		if(check(a, col)) {
			for(auto i : col) cout << i;
			cout << '\n';
			return;
		}
	}
	cout << "-\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}