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


const long long MOD = 1e9 + 7;
const long long N = 1e6 + 6;
long long n, k, fact[N], m, a, b, ans;

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
	if(n < k) return 0;
	return (1LL * fact[n] * invMod((1LL * fact[k] * fact[n - k]) % MOD)) % MOD;
}

long long perm_rep(vector <long long> v) {
	long long sum = 0;
	for(auto i : v) 
		sum += i;
	long long ans = fact[sum];
	for(auto i : v) 
		ans = (1LL * ans * invMod(fact[i])) % MOD;
	// dbg(v);
	// dbg(ans);
	return ans;
}

void pre() {
	fact[0] = 1;
	for(long long i = 1; i < N; i++)
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
}

long long tree(long long n, long long k) {
	if(k == 0 && n == 0) return 1;
	return (k * powMod(n, (MOD - 1 + n - k - 1) % (MOD - 1))) % MOD;
}

long long cnt(long long nr) {
	// dbg(nr);
	long long nr_conf_muchii = comb(m - 1, nr - 1);
	// dbg_ok;
	long long nr_perm_noduri = (comb(n - 2, nr - 1) * fact[nr - 1]) % MOD;
	// long long nr_paduri = tree(n - 1 - nr, );
	long long nr_trees = tree(n, nr + 1);
	// for(long long i = 0; i <= n - nr - 1; i++) {
	// 	nr_trees += tree(n - nr - 1, i) * powMod(nr + 1, i);
	// 	// dbg(i, nr_trees, tree(n - nr - 1, i));
	// 	nr_trees %= MOD;
	// }
	long long nr_cost_muchii = powMod(m, n - nr - 1);
	// dbg(nr_trees, nr_conf_muchii, nr_cost_muchii, nr_perm_noduri);
	return ((1LL * nr_conf_muchii * nr_perm_noduri) % MOD) * ((1LL * nr_trees * nr_cost_muchii) % MOD);
}

int main() {
	ios_base::sync_with_stdio(false);

	pre();


	// for(long long i = 1; i <= n; i++) {
	// 	dp[i] = 
	// }

	cin >> n >> m >> a >> b;

	for(long long i = 1; i <= min(m, n - 1); i++) {
		ans += cnt(i) % MOD;
		ans %= MOD;
		// dbg(i, ans);
	}
	cout << ans << '\n';


	return 0;
}