// Problem: F. Make It One
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/F
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
const int A = 3e5 + 3;
const int bad = 277200;
vector<int> divs[A], p_divs[A];
int cnt[A];
int ans = 1<<30;
int x[1<<6], y[1<<6];
template<int inv>
void transform(int *x, int n) {
	for(int j = 1; j < 1<<n; j*=2)
		for(int i = 0; i < 1<<n; i++)
			if(i&j)
				x[i] = x[i] + (inv?-x[i^j]:x[i^j]);
}
void solve(int V) {
	memset(x, 0, sizeof x);
	memset(y, 0, sizeof y);
	int n = p_divs[V].size();
	int ful = (1<<n)-1;
	for(int i = 0; i < 1<<n; i++) {
		int c = 1;
		for(int j = 0; j < n; j++) if((i>>j)&1)
			c *= p_divs[V][j];
		x[ful^i] = cnt[c];
	}
	transform<1>(x, n);
	for(int i = 0; i < 1<<n; i++) {
		y[i] = !!x[i];
	}
	memset(x, 0, sizeof x);
	x[0] = 1;
	transform<0>(y, n);
	for(int cnt = 2; cnt <= min(n+1, ans); cnt++) {
		transform<0>(x, n);
		for(int i = 0; i < 1<<n; i++)
			x[i] *= y[i];
		transform<1>(x, n);
		for(int i = 0; i < 1<<n; i++)
			x[i] = !!x[i];
		if(x[ful]) {
			//cout << V << " // " << cnt << endl;
			ans = min(ans, cnt);
			break;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	for(int i = 2; i < A; i++) {
		assert(p_divs[i].size()<7);
		if(p_divs[i].size()) continue;
		p_divs[i].push_back(i);
		for(int j = i*2; j < A; j+=i) {
			p_divs[j].push_back(i);
		}
	}
	for(int i = 1; i < A; i++) {
		[&]() {
		for(auto d : p_divs[i])
			if(i%(d*1ll*d) == 0) return;
		for(int d = 1; d*i < A; d++)
			divs[d*i].push_back(i);
		}();
	}
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) {
		cin >> i;
		for(auto j : divs[i])
			cnt[j]++;
	}
	if(count(all(a), 1)) {
		cout << "1\n";
		return 0;
	}
	for(auto &i : a) solve(i);
	if(ans == 1<<30) ans = -1;
	cout << ans << '\n';
}