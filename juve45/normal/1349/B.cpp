#include <bits/stdc++.h>
using namespace std;

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_array(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)

const int N = 100100;
int n, a[N], mn[N], mx[N], s[N], k, t;

string solve() {
	cin >> n >> k;
	int nr = 0;

	memset(mn, 0, (n + 4) * sizeof(int));
	memset(mx, 0, (n + 4) * sizeof(int));
	memset(s, 0, (n + 4) * sizeof(int));

	vector <int> v;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == k) nr++, a[i] = 1, v.push_back(i);
		else a[i] = (a[i] > k ? 1 : -1);
	}
	if(nr == 0) return "no\n";
	if(n == 1) return "yes\n";

	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		mn[i] = min(s[i], mn[i - 1]);
		// mx[i] = max(s[i], mx[i - 1]);
	}

	mx[n] = s[n];
	for(int i = n - 1; i >= 0; i--)
		mx[i] = max(s[i], mx[i + 1]);

	// for(auto i : v) {
	for(int i = 1; i <= n; i++) {
		if(a[i] == -1) continue;
		if(i < n && mx[i + 1] - s[i] >= 0)
			return "yes\n";
		if(i > 1 && s[i - 1] - mn[i - 2] >= 0)
			return "yes\n";

	}
	return "no\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) cout << solve();
}