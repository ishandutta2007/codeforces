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

const long long N = 200400;
const long long MOD = 998244353;

long long n, f[N], use[N], dp[N], a, b;
vector <long long> v[N];

long long pre(long long n) {
	f[0] = 1;
	for(long long i = 1; i <= n; i++)
		f[i] = (f[i - 1] * i) % MOD;
}

long long powMod(long long b, long long e) {
	if(e == 0) return 1;
	if(e == 1) return b;
	long long tmp = powMod(b, e / 2);
	tmp = (tmp * tmp) % MOD;
	if(e % 2) tmp = (tmp * b) % MOD;
	return tmp;
}

long long invMod(long long nr) {
	return powMod(nr, MOD - 2);
}

long long comb(long long n, long long k) {
	return (f[n] * invMod((f[k] * f[n - k]) % MOD)) % MOD;
}

long long catalan(long long n) {
	return (invMod(n + 1) * comb(2 * n, n)) % MOD;
}

void dfs(long long node, long long ant = -1) {

	long long cat = 0;
	for(auto i : v[node])
		if(i != ant)
			dfs(i, node), cat++;

	if(ant == -1)
		dp[node] = f[cat];
	else 
		dp[node] = f[cat + 1];

	for(auto i : v[node])
		if(i != ant) {
			dp[node] = (dp[node] * dp[i]) % MOD;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	pre(n + 100);
	for(long long i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// dbg(catalan(0));
	// dbg(catalan(1));
	// dbg(catalan(2));
	// dbg(catalan(3));
	// dbg(catalan(4));
	// dbg(catalan(6));
	dfs(1);
	// dbg(dp[1]);
	// dbg(dp[2]);
	cout << (n * dp[1]) % MOD;
}