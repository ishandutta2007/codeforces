#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
void solve() {
	array<int, 2> o;
	int n, m, x;
	cin >> n >> x >> m;
	o = {x, x};
	for(int l, r; m--;) {
		cin >> l >> r;
		if(o[1] < l || r < o[0]) continue;
		o = {min(o[0], l), max(o[1], r)};
	}
	cout << o[1]-o[0]+1 << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}