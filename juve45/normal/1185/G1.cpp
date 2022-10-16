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

const long long N = 22;
const long long MOD = 1e9 + 7;
long long n, tt, t[N], g[N];
long long ans = 0, dp[(1 << 16)][16];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> tt;
	for(long long i = 0; i < n; i++) 
		cin >> t[i] >> g[i];

	dp[1][0] = 1;

	for(long long msk = 1; msk < (1 << n); msk++) {
		long long time = 0;
		for(long long i = 0; i < n; i++)
			if(((1 << i) & msk) != 0)
				time += t[i];

		for(long long lst = 0; lst < n; lst++) {
			if((msk & (1 << lst)) == 0) continue;
			if(msk == (1 << lst)) 
				dp[msk][lst] = 1;
			else 
				for(long long prv = 0; prv < n; prv++)
					if(lst != prv && (msk & (1 << prv)) != 0 && g[lst] != g[prv]) {
							dp[msk][lst] += dp[msk ^ (1 << lst)][prv];
					}

			if(time == tt)
				ans += dp[msk][lst];
		}
	}
	cout << ans % MOD << '\n';
}