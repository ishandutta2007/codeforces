// Problem: C. Codeword
// Contest: Codeforces - Codeforces Round #349 (Div. 1)
// URL: https://codeforces.com/contest/666/problem/C
// Memory Limit: 256 MB
// Time Limit: 6000 ms
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
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 15, mod = 1e9 + 7;
int fact[maxn], inv[maxn], pws[maxn], pw_26[maxn];
void pre() {
	pws[0] = 1;
	for(int i = 1; i < maxn; i++)
		pws[i] = pws[i-1]*25ll%mod;
	pw_26[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw_26[i] = pw_26[i-1]*26ll%mod;
	for(int i = 0; i < maxn; i++)
		if(i < 2) fact[i] = inv[i] = 1;
		else fact[i] = i, inv[i] = mod - (mod/i)*1ll*inv[mod%i]%mod;
	for(int i = 1; i < maxn; i++)
		fact[i] = fact[i]*1ll*fact[i-1]%mod,
		inv[i] = inv[i]*1ll*inv[i-1]%mod;
}
int bp(int a, int p) {
	int r = 1;
	while(p) {
		if(p&1) r = r*1ll*a%mod;
		a = a*1ll*a%mod, p>>=1;
	}
	return r;
}
int nck(int i, int j) {
	if(i < j || j < 0) return 0;
	int t = fact[i]*1ll*inv[j]%mod;
	return t*1ll*inv[i-j]%mod;
}

array<int, maxn> calculate(int k) {
	array<int, maxn> sol;
	sol.fill(0);
	//sum N choose i * 25^(N-i) for i < k
	for(int N = 0; N < k; N++) {
		sol[N] = pw_26[N];
	}
	int cur = sol[k-1];
	for(int N = k; N < maxn; N++) {
		cur = cur*26ll%mod;
		cur = (cur - nck(N-1, k-1)*1ll*pws[N-k])%mod;
		if(cur < 0) cur += mod;
		sol[N] = cur;
	}
	for(int i = 0; i < maxn; i++) {
		sol[i] = pw_26[i] - sol[i];
		if(sol[i] < 0) sol[i] += mod;
	}
	return sol;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	pre();
	int Q;
	string s;
	cin >> Q >> s;
	int id = 0;
	map<int, vector<array<int, 2>>> f;
	for(int t, x; Q--;) {
		cin >> t;
		if(t == 1) {
			cin >> s;
		} else {
			cin >> x;
			f[s.size()].push_back({x, id++});
		}
	}
	vector<int> ans(id);
	for(auto [S, v] : f) {
		auto t = calculate(S);
		for(auto [a, b] : v)
			ans[b] = t[a];
	}
	for(auto i : ans) cout << i << '\n';
	return 0;
}