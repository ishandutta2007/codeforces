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

const int N = 1000100;
int n, f[2 * N], m;

string s[N];
vector <int> use[N];

bool dfs(int x, int y) {
	// dbg(x, y);
	if(x == n - 1 && y == m - 1) return 1;
	
	int ok = 0;

	if(x != n - 1)  {
		if(!use[x + 1][y]) ok |= dfs(x + 1, y);
		else if(use[x + 1][y] == 2) ok = 1;
	}
	if(y != m - 1) {
		if(!use[x][y + 1]) ok |= dfs(x, y + 1);
		else if(use[x][y + 1] == 2) ok = 1;
	}
	use[x][y] = ok + 1;
	if(ok) f[x + y]++;
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 0; i < n; i++)  {
		cin >> s[i];
		use[i] = vector <int> (m, 0);
		for(int j = 0; j < m; j++)
			if(s[i][j] == '#')
				use[i][j] = 1;
		// dbg(use[i]);
	}
	dfs(0, 0);
	int ans = 2;
	for(int i = 1; i < n - 1 + m - 1; i++)
		ans = min(ans, f[i]);
	// dbg_v(f, n + m);
	cout << ans << '\n';
}