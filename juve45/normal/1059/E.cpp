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
long long n, lg, w[N], s, dp[N], a, ans;
vector <long long> v[N], st;

long long cb() {
	long long l = 0, r = min((long long) st.size() - 2, lg - 1);
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		if(st.back() - st[st.size() - mid - 2] <= s) l = mid;
		else r = mid - 1;
	}
	return l;
}

void dfs(long long node, long long tot) {
	
	st.push_back(tot);
	// dbg(node, tot);
	long long up = -1;
	for(auto i : v[node]) {
		dfs(i, tot + w[i]);
		up = max(up, dp[i] - 1);
	}
	// dbg(node, up);

	if(up == -1) 
		dp[node] = cb(), ans++;
	else 
		dp[node] = up;

	// dbg(node, dp[node]);
	// dbg(st);
	st.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> lg >> s;
	for(long long i = 1; i <= n; i++)  {
		cin >> w[i];
		if(w[i] > s) return cout << "-1\n", 0;
	}

	for(long long i = 2; i <= n; i++) {
		cin >> a;
		v[a].push_back(i);
	}

	st.push_back(0);
	dfs(1, w[1]);

	cout << ans << '\n';
}