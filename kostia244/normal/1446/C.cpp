#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 5050, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> a;
int x_rank(int x) {
	if(x == 0) return 0;
	return 1+__lg(x);
}
int solve(int l, int r) {//[l;r) nlog(n) calls * O(log + n) algo
	if(l+1 >= r) return l+1==r;
	array<int, 32> sols {};
	int nonzero = 0, lower = 0;
	for(int pos = l, rnk = 0; rnk <= 30; rnk++) {
		int old = pos;
		while(pos < r && x_rank(a[pos]) == rnk) {
			if(rnk) a[pos] ^= 1<<(rnk-1);
			pos++;
		}
		sols[rnk] = solve(old, pos);
		nonzero += !!sols[rnk];
	}
	int ans = 0;
	for(int i = 0; i <= 30; i++) {
		nonzero -= !!sols[i];
		ans = max(ans, sols[i] + lower + nonzero);
		lower |= !!sols[i];
	}
	return ans;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	cout << n-solve(0, n) << '\n';
}