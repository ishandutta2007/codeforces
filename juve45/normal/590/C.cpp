#include <bits/stdc++.h>
#define st first
#define nd second
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <int> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"



const int N = 1010;
int n, k, m, a, b;
int dmin[5][N][N], dr[5][5];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

string w[N];

void lee(char c) {
	// dbg(c);
	queue <pair <int, int> > q;
	int k = c - '0';
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(w[i][j] == c) 
				q.push({i, j}), dmin[k][i][j] = 0;

	while(!q.empty()) {
		auto p = q.front();
		q.pop();
		// dbg(p, dmin[k][p.st][p.nd]);
		for(int i = 0; i < 4; i++)
			if(w[p.st + dx[i]][p.nd + dy[i]] != '#' && dmin[k][p.st + dx[i]][p.nd + dy[i]] > dmin[k][p.st][p.nd] + 1) {
				dmin[k][p.st + dx[i]][p.nd + dy[i]] = dmin[k][p.st][p.nd] + 1;
				q.push({p.st + dx[i], p.nd + dy[i]});
			}
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(w[i][j] <= '3' && '1' <= w[i][j])
				dr[k][w[i][j] - '0'] = min(dr[k][w[i][j] - '0'], dmin[k][i][j]);
}

int main() {
	memset(dmin, 0x3f, sizeof dmin);
	memset(dr, 0x3f, sizeof dr);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	w[0] = w[n + 1] = string(m + 2, '#');

	for(int i = 1; i <= n; i++) {
		cin >> w[i];
		w[i] = "#" + w[i] + "#";
	}

	lee('1');
	lee('2');
	lee('3');

	// for(int i = 0; i <= n + 1; i++) dbg(w[i]);
	// 	dbg_ok;
	// for(int i = 0; i <= n + 1; i++) dbg_v(dmin[1][i], m + 2);
	// 	dbg_ok;
	// for(int i = 0; i <= n + 1; i++) dbg_v(dmin[2][i], m + 2);
	// 	dbg_ok;
	// for(int i = 0; i <= n + 1; i++) dbg_v(dmin[3][i], m + 2);


	long long ans = dr[1][2] + dr[2][3] + dr[3][1] - max({dr[1][2], dr[2][3], dr[3][1]}) - 2;
	// dbg(dr[1][2], dr[2][1]);
	// dbg(dr[1][3], dr[3][1]);
	// dbg(dr[3][2], dr[2][3]);
	// dbg(ans);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			ans = min(0LL + ans, 0LL + dmin[1][i][j] + dmin[2][i][j] + dmin[3][i][j] - 2);
			// dbg(dmin[1][i][j], dmin[2][i][j], dmin[3][i][j]);
		}
	if(ans > 1e8) 
		ans = -1;
	cout << ans << '\n';
	return 0;
}