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

const long long N = 505;
const long long MOD = 998244353;
long long n, a[N], dp[N][N];


long long solve(long long l, long long r) {
	if(l > r) return 1;


	if(dp[l][r] == -1) {

		if(l == r) 
			dp[l][r] = 1;
		else {
			long long mn = l;
			for(long long i = l; i <= r; i++) {
				if(a[i] < a[mn])
					mn = i;
			}

			dp[l][r] = 0;
			long long sum_left = 0;
			for(long long i = l; i <= mn; i++) {
				sum_left += ((solve(l, i - 1) * solve(i, mn - 1)) % MOD);
				sum_left %= MOD;
			}

				for(long long j = mn; j <= r; j++) {
					dp[l][r] += ( sum_left * ((solve(mn + 1, j) * solve(j + 1, r)) % MOD) ) % MOD;
				}
				
			dp[l][r] %= MOD;
		}
	}
	return dp[l][r];
}

int main() {
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof dp);
	cin >> n >> n;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];
	cout << solve(1, n);
}