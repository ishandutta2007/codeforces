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

const long long N = 200100;
const long long MOD = 1e9 + 7;
long long n, a[N], dp[N][2], cnt[N][2], ans, x, y, sum;
vector <long long> v[N];

void dfs(long long node, long long ant = -1) {
	
	dp[node][0] = 0;
	cnt[node][0] = 0;

	for(auto i : v[node]) {
		if(i == ant) continue;
		dfs(i, node);

		ans += (dp[node][1] * cnt[i][0] % MOD + cnt[node][1] * dp[i][0] % MOD) % MOD;
		ans += (dp[node][0] * cnt[i][1] % MOD + cnt[node][0] * dp[i][1] % MOD) % MOD;
		ans %= MOD;


		dp[node][0] += -cnt[i][1] * a[node] + dp[i][1];
		dp[node][0] %= MOD;
		cnt[node][0] += cnt[i][1];
		cnt[node][0] %= MOD;

		dp[node][1] += cnt[i][0] * a[node] + dp[i][0];
		dp[node][1] %= MOD;
		cnt[node][1] += cnt[i][0];
		cnt[node][1] %= MOD;

	}

	cnt[node][1] += 1;
	dp[node][1] += a[node];
	ans += dp[node][1];
	ans %= MOD;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <=n; i++)  {
		cin >> a[i];
		sum += a[i];
		sum %= MOD;
		// dbg(sum);
	}


	for(long long i = 1; i < n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1);
	cout << (10 * MOD + 2 * ans - sum) % MOD << '\n';
}