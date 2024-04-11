// Problem: E. Array Equalizer
// Contest: Codeforces - Codeforces Round #754 (Div. 2)
// URL: https://codeforces.com/contest/1605/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int N = 2e5 + 15;
ll n, a[N];
array<ll, 2> b[N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	for(int i = 1; i <= n; i++) 
		cin >> b[i][0], b[i][1] = 0;
	b[1] = {0, 1};
	vector<array<ll, 2>> prs;
	for(int i = 1; i <= n; i++) {
		array<ll, 2> delta = {-b[i][0]+a[i], -b[i][1]};
		prs.push_back({delta[1], delta[0]});
		for(int j = i; j <= n; j+=i) {
			b[j][0] += delta[0];
			b[j][1] += delta[1];
		}
	}
	for(auto &[a, b] : prs) if(a < 0 || (a == 0 && b < 0)) a*=-1,b*=-1;
	auto cmp = [&](auto A, auto B) -> bool {
		if(B[0] == 0) return A[0] != 0;
		if(A[0] == 0) return 0;
		return (-A[1]*B[0] > -B[1]*A[0])^(A[0]*B[0]<0);
	};
	sort(all(prs), cmp);
	auto pre = prs;
	ll as = 0, bs = 0;
	for(int i = 1; i < n; i++) {
		pre[i][0] += pre[i-1][0];
		pre[i][1] += pre[i-1][1];
	}
	as = pre.back()[0], bs = pre.back()[1];
	ll q, t;
	cin >> q;
	while(q--) {
		cin >> t;
		ll p = -1;
		for(ll z = 1ll<<20; z>>=1;) if(p+z < pre.size() && prs[p+z][0]*t+prs[p+z][1] < 0)
			p += z;
		ll ans = p == -1 ? 0 : -(pre[p][0]*t + pre[p][1]);
		ans += (as-(p==-1?0:pre[p][0]))*t + (bs-(p==-1?0:pre[p][1]));
		cout << ans << '\n';
		ans = 0;
	}
}