#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5 + 6;
const long long mod = 998244353;

long long fact[maxn];

long long power(long long a, long long b, long long r){
	if(b == 0) return 1;
	if(b == 1) return (a % r);

	long long res = power(a, b / 2, r);
	res *= res;
	res %= r;

	if(b % 2) res *= a % r, res %= r;
	return res;
}

void build(){
	fact[0] = 1;
	for(long long i = 1; i < maxn; ++i){
		fact[i] = (fact[i - 1] * i) % mod;
	}
}

long long P(long long k, long long n){
	//n! / (n - k)!
	if(k > n) return 0;

	long long res = fact[n];
	res *= power(fact[n - k], mod - 2, mod);
	res %= mod;

	return res;
}

void solve(){
	long long n;
	cin >> n;

	map<long long, long long> cow;
	for(int i = 0; i < n; ++i){
		long long val;
		cin >> val;
		++cow[val];
	}

	auto it = cow.end();
	--it;

	long long fst = (*it).first;
	if(cow[fst] > 1){
		cout << fact[n] << '\n';
		return;
	}

	--it;
	long long snd = (*it).first;
	if(fst - snd > 1){
		cout << "0\n";
		return;
	}

	long long num = cow[snd];
	long long ans = 0;
	for(int i = n; i > 0; --i){
		long long res = fact[i - 1];
		res *= P(n - i, n - num - 1);
		res %= mod;

		ans += res;
		ans %= mod;
	}

	ans = (fact[n] - ans + mod) % mod;
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	build();

	int t;
	cin >> t;

	while(t--) solve();
}