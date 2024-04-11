#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 1<<20;
int n;
vector<array<int, 2>> a;
int ans = 0;
void solve() {
	sort(all(a));
	int mny = 1e9, mnx = 1e9;
	for(auto [x, y] : a) {
		mnx = min(mnx, x);
		mny = min(mny, y);
		ans = max(ans, x+y-mnx-mny);
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	a.resize(n);
	int Lx = 1e9, Rx = -1e9, Ly = 1e9, Ry = -1e9;
	for(auto &i : a) {
		cin >> i[0] >> i[1];
		Lx = min(Lx, i[0]);
		Rx = max(Rx, i[0]);
		Ly = min(Ly, i[1]);
		Ry = max(Ry, i[1]);
	}
	for(int i = 0; i < 4; i++) {
		solve();
		for(auto &t : a) t[i&1] *= -1;
	}
	cout << 2*ans << " ";
	for(int i = 4; i <= n; i++) cout << 2*(Rx+Ry-Lx-Ly) << ' ';cout << '\n';
}