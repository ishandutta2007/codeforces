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
const long long K = 5005;
long long n, k, a[N], dp[K][K];

vector <long long> v;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	long long sz = n / k;
	long long extra = n % k;
	// dbg(sz);
	// dbg(extra);


	for(long long i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);

	for(long long i = 1; i < n; i++) {
		v.push_back(a[i + 1] - a[i]);
	}

	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	// dbg_v(a, n + 1);
	
	for(long long i = 1; i <= k; i++) {
		for(long long j = 0; j <= min(extra, i); j++) {
			long long pos = i * sz + j;
			// dbg(i, j);
			// dbg(dp[i - 1][j], pos, a[pos], a[pos - sz + 1]);
			if(j > 0)
				dp[i][j] = min(dp[i - 1][j] + a[pos] - a[pos - sz + 1], dp[i - 1][j - 1] + a[pos] - a[pos - sz]);
			else
				dp[i][j] = dp[i - 1][j] + a[pos] - a[pos - sz + 1];

			// dbg(dp[i][j]);
		}
	}

	cout << dp[k][extra] << '\n';
}