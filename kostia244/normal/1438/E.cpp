#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
#include<bits/extc++.h>
#define int ll
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, a[maxn], p[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vector<int> com;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i-1] + a[i];
	}
	int ans = 0;
	set<array<int, 2>> s;
	for(int i = 1; i <= n; i++) {
		auto it = s.end();
		while(true) {
			if(it == s.begin()) break;
			it--;
			if(it->at(0) < -a[i]+p[i-1]) break;
			int t = it->at(1);
			ans += (a[t] ^ a[i]) == (p[i-1]-p[t]);
		}
		if(i>1)
		s.insert({a[i-1]+p[i-1], i-1});
	}
	cout << ans << '\n';
}