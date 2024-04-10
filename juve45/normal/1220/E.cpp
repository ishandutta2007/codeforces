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
long long n, m, a, b, use[N], gr[N], s, w[N], ans, max_dp, dp[N];
queue <long long> q;
vector <long long> v[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
		cin >> w[i];

	for(long long i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		gr[a]++;
		gr[b]++;
	}
	cin >> s;

	use[s] = 1;
	ans = w[s];

	for(long long i = 1; i <= n; i++)
		if(gr[i] == 1 && i != s)
			q.push(i), use[i] = 1;

	while(!q.empty()) {
		auto x = q.front();
		// dbg(x);
		q.pop();

		for(auto i : v[x]) {
			if(!use[i]) {
				gr[i]--;
				if(gr[i] == 1) q.push(i), use[i] = 1;
			}
			else if(i != s){
				dp[x] = max(dp[x], dp[i]);
			}
		}

		dp[x] += w[x];
		max_dp = max(max_dp, dp[x]);
		// dbg(dp[x]);
	}	
	// dbg_v(use, n + 1);
	for(long long i = 1; i <= n; i++)
		if(!use[i]) ans += w[i];

	cout << ans + max_dp << '\n';
}