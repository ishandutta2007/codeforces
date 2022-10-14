#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	int n, k;
	while(t--) {
		cin >> n >> k;
		int ok = 0;
		vector<array<int, 2>> a(n);
		for(auto &[x, y] : a) cin >> x >> y;
		for(auto &[x, y] : a) {
			int mx = 0;
			for(auto &[x1, y1] : a) {
				mx = max(mx, abs(x-x1)+abs(y-y1));
			}
			ok |= mx <= k;
		}
		cout << (ok?1:-1) << '\n';
	}
}