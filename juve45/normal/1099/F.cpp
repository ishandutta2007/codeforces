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
const long long MX = 10 * N;
long long t[N], sum[N * 10], fre[N * 10], x[N], cnt[N], p[N], c[N], dp[N];
long long n, tot;

vector <pair<long long, long long> > v[N];

long long lsb(long long k) {
	return k & (-k);
}

void add(long long * aib, long long pos, long long val) {
	for(; pos < MX; pos += lsb(pos))
		aib[pos] += val;
}

long long que(long long * aib, long long pos) {
	long long ret = 0;
	for(; pos; pos -= lsb(pos))
		ret += aib[pos];
	return ret;
}

long long cb(long long lim) {
	if(lim <= 0) return 0;
	long long l = 0, r = 1e6;
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		if(que(sum, mid) <= lim) l = mid;
		else r = mid - 1;
	}

	long long ret = que(fre, l);
	long long rem = lim - que(sum, l);
	long long cant = que(fre, l + 1) - que(fre, l);
	ret += min(rem / (l + 1), cant);
	return ret;
}

void dfs(long long node, long long rem) {
	// dbg(node);
	add(sum, t[node], cnt[node] * t[node]);
	add(fre, t[node], cnt[node]);

	dp[node] = cb(rem);

	if(node != 1 && v[node].size() < 2) {
		add(sum, t[node], -cnt[node] * t[node]);
		add(fre, t[node], -cnt[node]);
		// dbg(node, dp[node]);
		return;
	}

	vector <long long> dps;
	for(auto i : v[node]) {
		dfs(i.st, rem - 2 * i.nd);
		dps.push_back(dp[i.st]);
	}
	sort(dps.begin(), dps.end(), greater<long long>());

	if(node != 1)
		dp[node] = max(dps[1], dp[node]);
	else 
		dp[node] = max(dps[0], dp[node]);

	add(sum, t[node], -cnt[node] * t[node]);
	add(fre, t[node], -cnt[node]);
	// dbg(node, dp[node]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> tot;
	for(long long i = 1; i <= n; i++)
		cin >> cnt[i];
	for(long long i = 1; i <= n; i++)
		cin >> t[i];

	for(long long i = 2; i <= n; i++) {
		cin >> p[i] >> c[i];
		v[p[i]].push_back({i, c[i]});
	}

	dfs(1, tot);
	cout << dp[1] << '\n';
}