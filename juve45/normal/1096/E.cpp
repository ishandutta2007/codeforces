#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 2 * 5010;
const long long MOD = 998244353;
long long n, fact[N];

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

long long invMod(long long a) {
	return powMod(a, MOD - 2);
}

long long comb(long long n, long long k) {
	return (1LL * fact[n] * invMod((1LL * fact[k] * fact[n - k]) % MOD)) % MOD;
}

long long stars_bars(long long n, long long s) {
	// dbg(n, k, n + k - 1, k - 1);
	if(s < 0) return 0;
	if(n < 0) return 0;
	if(s == 0 && n == 0) return 1;
	return comb(n + s - 1, s);
}

long long stars_bars_bound(long long n, long long s, long long limit) {
	long long mul = 1;
	long long ret = 0;
	for(long long i = 0; i <= n; i++) {
		ret += (mul * comb(n, i) * stars_bars(n, s - i * limit)) % MOD;
		mul *= -1;
		ret %= MOD;
	}
	return ret;
}

void pre() {
	fact[0] = 1;
	for(long long i = 1; i < N; i++)
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
}


int main() {
	ios_base::sync_with_stdio(false);
	pre();
	// dbg_v(fact, 10);
	// dbg(comb(5, 2));
	// dbg(stars_bars_bound(3, 7, 4));

	long long p, s, r;
	cin >> p >> s >> r;

	long long ans = 0, tot = 0;

	// dbg(stars_bars_bound(0, 0, 3));
	// dbg(stars_bars(0, 0));
	// dbg(comb(0, 0));

	tot = stars_bars(p, s - r) % MOD;
	for(long long i = 1; i <= p; i++) {
		for(long long j = r; j <= s; j++) {
			if(s >= i * j) {
				ans = (ans + comb(p - 1, i - 1) * (MOD + (stars_bars_bound(p - i, s - i * j, j) * invMod(i)) % MOD)) % MOD; // 
				// if(ans < 0) cerr << ans << '\n';
			}
		// dbg(i, j, ans);
		}
	}
	dbg(ans, tot);
	cout << (ans * invMod(tot)) % MOD;
}