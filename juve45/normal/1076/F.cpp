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

const long long N = 300100;
long long n, k, x[N][2], dp[N][2];

long long get_min(long long good, long long sep, long long ant, long long ant_sep) {

	long long min_sep_req = (good + ant + k - 1) / k - 1;
	long long max_sep_req = (good - 1)* k + (k - ant_sep);
	
	// dbg(good, sep, ant, ant_sep, min_sep_req, max_sep_req);

	if(min_sep_req < sep && sep <= max_sep_req)
		return 1;
	if(sep == min_sep_req && (good + ant) % k != 0)
		return (good + ant) % k;
	if(sep == min_sep_req)
		return k;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);

	// dbg(get_min(6, 3, 2, 0));

	cin >> n >> k;
	for(long long i = 1; i <= n; i++)
		cin >> x[i][0];
	for(long long i = 1; i <= n; i++)
		cin >> x[i][1];

	memset(dp, -1, sizeof dp);
	dp[0][0] = dp[0][1] = 0;

	for(long long i = 1; i <= n; i++) {

		for(long long j = 0; j < 2; j++)
			for(long long k = 0; k < 2; k++) {
				if(dp[i - 1][k] == -1) continue;
				long long p = get_min(x[i][j], x[i][1 - j], dp[i - 1][k] * (j == k), dp[i - 1][k] * (j != k));
				if(dp[i][j] == -1 || dp[i][j] > p && p != -1) 
					dp[i][j] = p;
			}
		
		// dbg(dp[i][0], dp[i][1]);
	}
	if(dp[n][0] != -1 || dp[n][1] != -1) cout << "YES\n";
	else cout << "NO\n";
}