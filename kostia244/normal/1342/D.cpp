#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define list loli
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 2e5 + 55, mod = 998244353;
using ll = long long;
int cnt[maxn], n, k, c[maxn];
int can(int x) {
	int load = 0, extra = 0;
	for(int i = k; i; i--) {
		load += cnt[i]/x;
		extra += cnt[i]%x;
		load += extra/x;
		extra %= x;
		if(load + (extra>0) > c[i]) return 0;
	}
	return 1;
}
vector<int> list[maxn], res[maxn];
int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int t, i = 1; i <= n; i++) cin >> t, cnt[t]++, list[t].push_back(i);
	for(int i = 1; i <= k; i++) cin >> c[i];
	int ans = 0;
	for(int z = 1<<20; z>>=1;)
		ans += z*!can(ans+z);
	cout << ++ans << '\n';
	for(int j = 0, i = k; i; i--) {
		for(auto x : list[i]) {
			res[j].push_back(i);
			if(++j == ans) j = 0;
		}
	}
	for(int i = 0; i < ans; i++) {
		cout << res[i].size() << ' ';
		for(auto j : res[i]) cout << j << " "; cout << endl;
	}
}