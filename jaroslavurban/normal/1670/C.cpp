#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n), b(n), c(n), ia(n + 1), cnt(n + 1);
	for (auto& v : a) cin >> v;
	for (auto& v : b) cin >> v;
	for (auto& v : c) cin >> v, ++cnt[v];
	if (*max_element(cnt.begin() + 1, cnt.end()) > 1) { cout << "0\n"; return; }
	for (int i = 0; i < n; ++i) ia[a[i]] = i;
	vector<int> vis(n);
	int res = 1;
	for (int i = 0; i < n; ++i) if (!vis[i]) {
		bool done = i == ia[b[i]];
		for (int j = i; !vis[j]; j = ia[b[j]]) {
			vis[j] = true;
			done |= c[j];
		}
		if (!done) res = 2 * res % mod;
	}
	cout << res << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}