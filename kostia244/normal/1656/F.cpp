// Problem: F. Parametric MST
// Contest: Codeforces - CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = __int128;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const ll inf = 1ll<<22;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int32_t n;
		cin >> n;
		vector<ll> a(n);
		for(auto &i : a) {
			int64_t T;
			cin >> T;
			i = T;
		}
		sort(all(a));
		#define EVAL(t) (sum_pos + (t)*cnt_pos)*(mn + (t)) + \
						(sum_neg + (t)*cnt_neg)*(mx + (t)) - \
						(mn + (t))*(mx + (t)) - (n-1)*(t)*(t)
		#define EVAL2(t) (sum_pos + (t)*cnt_pos)*(mn + (t)) + \
						(sum_neg + (t)*cnt_neg)*(mx + (t)) - \
						(mn + (t))*(mn + (t)) - (n-1)*(t)*(t)
		#define EVAL3(t) (sum_pos + (t)*cnt_pos)*(mn + (t)) + \
						(sum_neg + (t)*cnt_neg)*(mx + (t)) - \
						(mx + (t))*(mx + (t)) - (n-1)*(t)*(t)
		auto solve = [&](ll sum_pos, ll cnt_pos, ll sum_neg, ll cnt_neg,
					ll mn, ll mx, ll tL, ll tR) {//actually linear
			ll L = EVAL(tL);
			ll R = EVAL(tR);
			if(tR == inf) {
				L = EVAL2(tL);
				R = EVAL2(tR);
			}
			if(tL == -inf) {
				L = EVAL3(tL);
				R = EVAL3(tR);
			}
			if(tR == inf && L < R) return (ll(1)<<126);
			if(tL == -inf && L > R) return (ll(1)<<126);
			return max(L, R);
		};
		ll sum_pos = 0, cnt_pos = 0, sum_neg = 0, cnt_neg = 0,
			mn = a[0], mx = a.back();
		for(int i = 0; i < n; i++)
			sum_pos += a[i], cnt_pos++;
		ll ans = solve(sum_pos, cnt_pos,
			sum_neg, cnt_neg, mn, mx, -mn, inf); 
		for(int i = 0; i < n; i++) {
			sum_pos -= a[i], cnt_pos--;
			sum_neg += a[i], cnt_neg++;
			ans = max(solve(sum_pos, cnt_pos, sum_neg, cnt_neg, mn, mx,
				(i+1 == n ? -inf : -a[i+1]), -a[i]), ans); 
		}
		if(ans == (ll(1) << 126)) cout << "INF\n";
		else cout << int64_t(ans) << '\n';
	});
	
}