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

const long long N = 1001000;
// const long long MOD = 2000003; //1e9 + 7;
const long long MOD = 1e9 + 7;
long long n, f[N], w, h, ans, r, c;

long long powMod(long long base, long long exp) {
	if(exp == 0) return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (tmp * tmp) % MOD;
	if(exp % 2 == 1) tmp = (tmp * base) % MOD;
	return tmp;
}

long long invMod(long long k) { return powMod(k % MOD, MOD - 2);}

long long comb(long long n, long long k) {
	return (f[n] * invMod(f[k] * f[n - k])) % MOD;
}

long long coef(long long r, long long c) {
	return comb(r + c - 2, c - 1);
}

unordered_map <long long, long long> val;
vector <pair<long long, pair<long long, long long> > > v;

int main() {
	// ifstream cin("padure2.in");
	// ofstream cout("padure2.out");
	ios_base::sync_with_stdio(false);
	cin >> h >> w >> n;
		
	f[0] = 1;
	for(long long i = 1; i < N; i++)
		f[i] = (i * f[i - 1]) % MOD;

	ans += coef(h, w);

	// dbg(ans);
	
	for(long long i = 1; i <= n; i++) {
		cin >> r >> c;
		val[r * N + c] = coef(r, c);
		v.push_back({r + c, {r, c}});
	}

	sort(v.begin(), v.end());

	for(long long i = 0; i < v.size(); i++) {
		auto p = v[i].nd;
		// dbg(h - v[i].nd.st + 1, w - v[i].nd.nd + 1, coef(h - v[i].nd.st + 1, w - v[i].nd.nd + 1));
		ans -= (coef(h - v[i].nd.st + 1, w - v[i].nd.nd + 1) * val[v[i].nd.st * N + v[i].nd.nd]) % MOD;
		ans = (ans + MOD) % MOD;

		// dbg(ans, p, val[p.st][p.nd]);
		for(long long j = i + 1; j < v.size(); j++)
			if(p.st <= v[j].nd.st && p.nd <= v[j].nd.nd) {
				val[v[j].nd.st * N + v[j].nd.nd] -= (val[p.st * N + p.nd] * coef(v[j].nd.st - p.st + 1, v[j].nd.nd - p.nd + 1)) % MOD;
				val[v[j].nd.st * N + v[j].nd.nd] %= MOD;
			}
	}
	ans = (ans + MOD) % MOD;
	// cout << ((ans + MOD) % MOD) << '\n';
	cout << ans << '\n';
}