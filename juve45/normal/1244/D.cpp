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
long long n, c[N][3], ans, a, b, cans, ii, jj, col[N];
vector <long long> v[N];

void dfs(long long node, long long ant, long long c1, long long c2, long long c3) {
	// dbg(node, c1);
	ans += c[node][c1];
	col[node] = c1;
	for(auto i: v[node])
		if(i != ant)
			dfs(i, node, c2, c3, c1);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) cin >> c[i][0];
	for(long long i = 1; i <= n; i++) cin >> c[i][1];
	for(long long i = 1; i <= n; i++) cin >> c[i][2];

	for(long long i = 1 ; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	long long nr1 = 0, nr2 = 0, start, cans = 1e18;
	for(long long i = 1; i <= n; i++)
		if(v[i].size() == 1) nr1++, start = i;
		else if(v[i].size() == 2) nr2++;

	if(nr1 != 2 || nr2 != n - 2) return cout << "-1\n", 0;

	// dbg(start);
	for(long long i = 0; i < 3; i++)
		for(long long j = 0; j < 3; j++) 
			if(i != j) {
				ans = 0;
				dfs(start, -1, i, j, 3 - i - j);
				// dbg(i, j, ans);
				if(ans < cans) {
					cans = ans;
					ii = i;
					jj = j;
				}
		}
	ans = 0;
	// dbg(ans, ii, jj);
	dfs(start, -1, ii, jj, 3 -ii - jj);
	cout << ans << '\n';
	for(long long i = 1; i <= n; i++) cout << 1 + col[i] << ' ';
}