#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 1e5 + 55, mod = 998244353;
using ll = long long;
ll get(vector<int> &a, int l, int r) {
	int res = a[r];
	if(l) res -= a[l-1];
	return res;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b, q;
		cin >> a >> b >> q;
		vector<int> rem;
		for(int i = 0; i < a*b; i++) rem.push_back((i%a)%b != (i%b)%a);
		for(int i = 1; i < a*b; i++) rem[i] += rem[i-1];
		for(ll l, r, ans; q--;) {
			cin >> l >> r;
			ans = 0;
			if(l/(a*b) == r/(a*b)) {
				cout << get(rem, l%(a*b), r%(a*b)) << ' ';
				continue;
			}
			if(l%(a*b)) {
				ans += get(rem, l%(a*b), a*b-1);
				l -= l%(a*b);
				l += a*b;
			}
			if(r%(a*b)) {
				ans += get(rem, 0, r%(a*b));
				r -= r%(a*b);
			}
			ans += ll((r-l)/(a*b)) * rem.back();
			cout << ans << " ";
		}
		cout << '\n';
	}
}