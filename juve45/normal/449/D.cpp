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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long  _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long  MOD = 1e9 + 7;
const long long  N = 2000100;
long long  n, a, f[N];

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

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long  i = 1; i<= n;i++) {
		cin >> a;
		f[a]++;
	}

	for(long long  i = 0; i < 20; i++)
		for(long long  mask = (1 << 20) - 1; mask >= 0; mask--)
			if (!(mask & (1 << i)))
				f[mask] += f[mask ^ (1 << i)];

	long long  ans = powMod(2, n);
	for(long long  i = 1; i < (1 << 20); i++) {
		ans += (powMod(-1, __builtin_popcount(i)) * powMod(2, f[i])) % MOD;
		ans %= MOD;
	}
	cout << (ans + MOD) % MOD << '\n';
}