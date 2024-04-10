#include <bits/stdc++.h>
#define st first
#define nd second

#define area(xa, ya, xb, yb, xc, yc)  (xa * yb + xb * yc + xc * ya - ya * xb - yb * xc - yc * xa)


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
long long n, f[4][4], m, ans;

inline long long cnt(long x,long y) {
	if(x == y && y == 0)
		return (n + 1) * (m + 1);
	long long ans = 6LL * (n - x + 1) * (m - y + 1) * (__gcd(x, y) - 1) + 6LL * (n - x + 1) * (m - y + 1);
	ans %= MOD;
	if(x == 0 || y == 0)
		return ans;
	return 2 * ans;
}

int gcd(int a, int b) {
	int c = a % b;
	while(c) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			f[i%2][j%2]++;

	for(int i = 0; i <= 1; i++)
		for(int j = 0; j <= 1; j++) {
			// dbg(i, j);
			for(int k = 0; k < 16; k++) {
				if(area(i, j, !(k & 1), !(k & 2), !(k & 4), !(k & 8)) % 2 == 0) {
					// dbg(k, !(k & 1), !(k & 2), !(k & 4), !(k & 8));
					ans += (((1LL * f[i][j] * f[!(k & 1)][!(k & 2)]) % MOD) * f[!(k & 4)][!(k & 8)]) % MOD;
					ans %= MOD;
				}
			}
			// dbg(ans);
		}

	ans -= (n + 1) * (m + 1);
	
	for(long long i = 1; i <= n; i++) {
		ans -= 6LL * (n - i + 1) * (m + 1) * i;
		ans %= MOD;
	}

	for(long long i = 1; i <= m; i++) {
		ans -= 6LL * (m - i + 1) * (n + 1) * i;
		ans %= MOD;
	}
	
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= m; j++) {
			ans -= 12LL * (m - j + 1) * (n - i + 1) * gcd(i, j);
			ans %= MOD;
		}

	// ans += (n + 1) * (m + 1);
	cout << (ans + MOD) % MOD << '\n';
}