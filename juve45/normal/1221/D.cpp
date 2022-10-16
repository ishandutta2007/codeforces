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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 300100;
long long n, dp[N][3], a[N], b[N], q;

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];

	// memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i <= n; i++) for(int j = 0; j < 3; j++) dp[i][j] = 0x3f3f3f3f3f3f3f3f;

	dp[0][0] = 0;
	a[0] = -1e9;
	for(int i = 1; i <= n;i++) {
		// dbg(i);
		for(int j = 0; j <= 2; j++) {
			for(int k = 0; k <= 2; k++) {
				// dbg(i);
				if(a[i - 1] + k == a[i] + j) continue;
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1LL * j * b[i]);
			}
		}
	}
	cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> q;
	while(q--) solve();

}