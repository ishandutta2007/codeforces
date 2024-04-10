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

const long long N = 100100;
long long n, dp[N], old[N], m, x[100], s[88];

vector <pair<long long, long long> > v;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(long long i = 1; i <= n; i++) {
		cin >> x[i] >> s[i];
		v.push_back({x[i], i});
	}

	sort(v.begin(), v.end());

	memset(old, 0x3f, sizeof old);
	memset(dp, 0x3f, sizeof dp);
	old[0] = 0;


	for(auto j : v) {
		long long i = j.nd;

		for(long long r = 0; r <= s[i]; r++)
			dp[min(x[i] + r, m)] = min(max(0LL, x[i] - 1 - s[i]), old[max(x[i] - s[i] - 1, 0LL)]);

		for(long long l = 0; x[i] + s[i] + l <= m || x[i] - s[i] - l > 0; l++) {
			long long pos = min(x[i] + s[i] + l, m);
			long long left = max(x[i] - s[i] - l - 1, 0LL);

			dp[pos] = min({old[left] + l, old[pos], dp[pos], dp[pos - 1] + 1});
		}

		// dbg_v(dp, m + 1);
		for(long long i = m - 1; i >= 0; i--)
			dp[i] = min(dp[i], dp[i + 1]);

		for(long long i = 1; i <= m; i++)
			old[i] = min(old[i], dp[i]);

		memset(dp, 0x3f, sizeof dp);
	}

	cout << old[m] << '\n';

}