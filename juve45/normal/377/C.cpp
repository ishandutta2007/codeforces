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

const int N = 101;
int n, a[N], m, dp[1 << 21], who[N];
char op[N];
int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n, greater <int>());

	cin >> m;
	n = m;
	for(int i= 1; i <= m; i++) {
		cin >> op[i] >> who[i];
	}

	for(int i = 0; i < (1 << n); i++)
		if(who[n - __builtin_popcount(i) + 1] == 1)
			dp[i] = -1e9;
		else dp[i] = 1e9;

	dp[0] = 0;
	for(int msk = 0; msk < (1 << n); msk++) {
		// dbg(msk, dp[msk]);

		for(int bit = 0; bit < n; bit++) {

			if(((1 << bit) & msk) == 0) {
				int curr = ((1 << bit) | msk);
				int nr = n - __builtin_popcount(curr) + 1;
			
				if(op[nr] == 'b') {
					if(who[nr] == 1) dp[curr] = max(dp[curr], dp[msk]);
					else dp[curr] = min(dp[curr], dp[msk]);
				} else {
					if(who[nr] == 1) dp[curr] = max(dp[curr], dp[msk] + a[bit]);
					else dp[curr] = min(dp[curr], dp[msk] - a[bit]);
				}
				// dbg(curr, dp[curr]);
			}
		}
		
	}
	cout << dp[(1 << n) - 1];
}