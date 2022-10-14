// Problem: Counting Primes
// Contest: Library Checker
// URL: https://judge.yosupo.jp/problem/counting_primes
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
vector<int> linear_sieve(int n) {
	vector<int> lp(n, 0), primes;
	for(int i = 2; i < n; i++) {
		if(!lp[i])
			primes.push_back(lp[i]=i);
		for(int j = 0; j < primes.size() && primes[j]*i < n && 
				primes[j] <= lp[i]; j++)
			lp[primes[j]*i] = primes[j];
	}
	return lp;
}
ll edu_problem(ll n) {
	int C = pow(n, 1./2) + 2;
	auto lp = linear_sieve(C);
	vector<ll> s(C), b(C);
	for(int i = 1; i < C; i++) {
		s[i] = i-1;
		b[i] = (n/i)-1;
	}
	auto ns = s, nb = b;
	ll cnt = 0, prv = 1, ans = 0;
	for(ll j = 2; j*1ll*j <= n; j++) if(lp[j]==j) {
		for(ll i = j*j; i < C; i++) {
			ns[i] = ns[i-1] + (lp[i]==i||lp[i]>j);
		} 
		for(int i = 1; i < C && (n/i)/j >= prv; i++) {
			ll t = i*1ll*j;
			nb[i] = b[i] - (n/t<C?s[n/t]:b[t]) + cnt;
		}
		for(ll i = j*j; i < C; i++) {
			s[i] = ns[i];
		} 
		for(int i = 1; i < C && (n/i)/j >= prv; i++) {
			b[i] = nb[i];
		}
		cnt++;
		prv = j;
	}
	for(ll j = 2; j*1ll*j <= n; j++) if(lp[j]==j) {
		ans += j*j*j <= n;
		ans += b[j] - s[j];
	}
	return ans;
}//6, 8, 10, 14, 15
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	ll n;
	cin >> n;
	cout << edu_problem(n) << '\n';
}