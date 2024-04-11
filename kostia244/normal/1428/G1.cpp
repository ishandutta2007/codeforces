// Problem: G2. Lucky Numbers (Hard Version)
// Contest: Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1428/problem/G2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
struct MinQ {
	deque<ll> q;
	inline void push(ll x) {
		while(!q.empty() && q.back() < x) q.pop_back();
		q.push_back(x);
	}	
	inline void pop(ll x) {
		if(q.front() == x) q.pop_front();
	}
	inline ll mx() { return q.front(); }
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int k, t, n;
	array<ll, 6> f;
	auto cst = [&](int x) {
		ll ans = 0;
		for(int i = 0; i < 6; i++, x/=10) {
			int d = x%10;
			if(d%3 == 0) ans += f[i]*1ll*(d/3);
		}
		return ans;
	};
	cin >> k;
	for(auto &i : f) cin >> i;
	const int N = 1e6 + 5;
	vector<ll> dp(N/3, -(1ll<<50));
	dp[0] = 0;
	for(int p = 1, d = 0; d < 6; d++, p *= 10) {
		vector<MinQ> q(p);
		auto ndp = dp;
		for(int i = 0; i < 333333; i++) {
			q[i%p].push(dp[i]-(i/p)*f[d]);
			ndp[i] = q[i%p].mx() + (i/p)*f[d];
			if(i-p*3*(k-1)>=0)
			if(ll t = i-p*3ll*(k-1); t >= 0)
				q[i%p].pop(dp[t]-(t/p)*f[d]);
		}
		dp = ndp;
	}
	{
		vector<ll> ndp(N, -(1ll<<50));
		for(int i = 0; i*3 < N; i++)
			ndp[i*3] = dp[i];
		dp = ndp;
	}
	cin >> t;
	while(t--) {
		cin >> n;
		ll ans = -(1ll<<60);
		for(int i = 0; i <= n; i++) {
			ans = max(ans, dp[n-i]+cst(i));
		}
		cout << ans << '\n';
	}
}