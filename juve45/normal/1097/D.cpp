#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T, T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

const long long MOD = 1e9 + 7;
long long n, k, m, dp[10410][54][54], ans = 1, inv[65], calc[52];
vector <long long> primes;
map <long long, long long>  f;

long long powMod(long long x, long long p) {
	if(p == 0) return 1;
	if(p == 1) return x % MOD;
	long long res = powMod(x, p / 2);
	res = (res * res) % MOD;
	if(p % 2 == 0) return res;
	else return (res * x) % MOD;
}

long long invMod(long long x) {
	return powMod(x, MOD - 2);
}

void prepre() {
	for(long long i =0; i < 55; i++)
		inv[i] = invMod(i);
}

void pre(long long from) {
	calc[from] = 1;
	dp[0][from][from] = 1;
	for(long long i = 1; i <= k; i++) 
		for(long long j = 0; j <= from; j++)
			for(long long l = j; l <= from; l++) 
				dp[i][from][j] = (dp[i][from][j] + inv[l + 1] * dp[i - 1][from][l]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	prepre();

	cin >> n >> k;

	long long p = 2;
	while(n % p == 0)
		primes.push_back(p), n /= p;

	for(p = 3; p * p <= n; p += 2)
		while(n % p == 0)
			primes.push_back(p), n /= p;

	if(n != 1) primes.push_back(n);

	for(auto i : primes) f[i]++;

	for(auto p : f) {
		long long tmp = 0;
		
		if(!calc[p.nd]) pre(p.nd);

		for(long long i = 0; i <= p.nd; i++) 
			tmp = (tmp + 1LL * powMod(p.st, i) * dp[k][p.nd][i]) % MOD;

		ans *= tmp;
		ans %= MOD;
	}
	cout << ans << '\n';
}