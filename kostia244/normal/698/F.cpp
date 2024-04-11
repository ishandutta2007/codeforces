// Problem: F. Coprime Permutation
// Contest: Codeforces - Codeforces Round #363 (Div. 1)
// URL: https://codeforces.com/contest/698/problem/F
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
const int N = 1e6 + 16, mod = 1e9 + 7;
int lp[N], sq[N], cnt[N];
vector<int> pr;
void sieve() {
	sq[1] = 1;
	for(int i = 2; i < N; i++) {
		if(lp[i] == 0)
			pr.push_back(lp[i] = i);
		sq[i] = sq[i/lp[i]];
		if(lp[i/lp[i]] != lp[i])
			sq[i] *= lp[i];
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j]*i < N; j++)
			lp[pr[j]*i] = pr[j];
	}
}
ll hL[N], hR[N];
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void edge(int x, int y) {
	ll h = rng();
	x = sq[x], y = sq[y];
	while(x>1) {
		hL[lp[x]] ^= h;
		x/=lp[x];
	}
	while(y>1) {
		hR[lp[y]] ^= h;
		y/=lp[y];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	sieve();
	int n;
	cin >> n;
	auto f = [&](int x) {
		if(lp[x]*2 > n)
			return 1;
		return sq[x];
	};
	vector<int> cnt(n+1);
	vector<pair<int, vector<int>>> s;
	for(int t=0, i = 1; i <= n; i++) {
		cin >> t;
		cnt[f(i)]++;
		if(t) {
			cnt[f(i)]--;
			edge(i, t);
		}
	}
	int ans = 1;
	for(int i = 1; i <= n; i++) {//account for same prime set
		while(cnt[i]) ans = ans*1ll*cnt[i]--%mod;
	}
	//account for swapping primes
	vector<pair<int, ll>> x, y;
	for(auto i : pr) {
		if(2*i > n) break;
		x.push_back({n/i, hL[i]});
		y.push_back({n/i, hR[i]});
	}
	sort(all(x));
	sort(all(y));
	if(x != y) {
		cout << "0\n";
		return 0;
	}
	for(int i = 0, j = 0; i < x.size();) {
		while(j < x.size() && x[j] == x[i]) j++;
		for(int x = j-i; x;)
			ans = ans*1ll*x--%mod;
		i = j;
	}
	cout << ans << '\n';
}