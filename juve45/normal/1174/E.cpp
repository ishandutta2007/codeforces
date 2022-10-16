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
const long long MOD = 1e9 + 7;
int n, dp[N][22][2];
	
long long f(long long p2, long long p3) {
	if(p3) return n / ((1 << p2) * 3);
	return n / (1 << p2);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	long long lg = 0, nn = n;
	while(nn) nn /= 2, lg++;
	lg--;

	dp[1][lg][0] = 1;
	if( (1 << (lg - 1)) * 3 <= n)
		dp[1][lg - 1][1] = 1;

	for(long long i = 1; i < n; i++)
		for(long long x = 0; x <= lg; x++)
			for(long long y = 0; y <= 1; y++) {
				dp[i + 1][x][y] += (1LL * dp[i][x][y] * (f(x, y) - i)) % MOD;
				dp[i][x][y] %= MOD;
				if(x > 0) 
					dp[i + 1][x - 1][y] += (1LL * dp[i][x][y] * (f(x - 1, y) - f(x, y))) % MOD,
					dp[i + 1][x - 1][y] %= MOD;
				if(y > 0) 
					dp[i + 1][x][y - 1] += (1LL * dp[i][x][y] * (f(x, y - 1) - f(x, y))) % MOD,
					dp[i + 1][x][y - 1] %= MOD;
			}

	cout << dp[n][0][0];
}