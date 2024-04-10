#include <bits/stdc++.h>
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
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " ; " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <int> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const int N = 100100;
int n, k, m, a, q;
int dp[255][255][255];
string s[4];
string t;
char b, op;
int nxt[N][30];


void update(int x, int y, int z) {
	if(x == 0 && y == 0 && z == 0)
		dp[x][y][z] = 0;
	dp[x][y][z] = N;
	if(x > 0) {
		int lg = dp[x - 1][y][z];
		// dbg("x");
		if(lg < t.size())
			dp[x][y][z] = min(dp[x][y][z], nxt[lg][s[1][x - 1] - 'a'] + 1);
	}
	if(y > 0) {
		// dbg("y");
		int lg = dp[x][y - 1][z];
		// dbg(lg);
		// dbg(s[2][y - 1]);
		// dbg(nxt[lg][s[2][y - 1] - 'a']);
		if(lg < t.size())
			dp[x][y][z] = min(dp[x][y][z], nxt[lg][s[2][y - 1] - 'a'] + 1);
		// dbg(dp[x][y][z]);
	}
	if(z > 0) {
		// dbg("z");
		int lg = dp[x][y][z - 1];
		if(lg < t.size())
			dp[x][y][z] = min(dp[x][y][z], nxt[lg][s[3][z - 1] - 'a'] + 1);
	}
	// dbg(x, y, z);
	// dbg(dp[x][y][z]);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> q;

	cin >> t;

	for(char c = 'a'; c <= 'z'; c++) {
		int last = N;
		for(int i = t.size() - 1; i >= 0; i--) {
			nxt[i + 1][c - 'a'] = last;
			if(t[i] == c) last = i;
		}
		nxt[0][c - 'a'] = last;
	}

	// dbg(nxt[0]['c' - 'a']);
	// dbg(nxt[1]['c' - 'a']);
	// dbg(nxt[2]['c' - 'a']);
	// dbg(nxt[3]['c' - 'a']);
	// dbg(nxt[4]['c' - 'a']);

	for(int i = 1; i <= q; i++) {
		cin >> op >> a;
		// e corect pana la dp[s[1].size()][s[2].size()][s[3].size()]
		// acuma tre sa vad unde se schimba
		if(op == '+') {
			cin >> b;
			s[a] += b;
			// dbg(i, s[1], s[2], s[3]);
			// tre sa updatez dp cu a...
			if(a == 1) {
				for(int j = 0; j <= s[2].size(); j++)
					for(int k = 0; k <= s[3].size(); k++) {
						// dbg(j, k);
						update(s[1].size(), j, k);
					}
			} else if(a == 2) {
				for(int i = 0; i <= s[1].size(); i++)
					for(int k = 0; k <= s[3].size(); k++)
						update(i, s[2].size(), k);
			} else {
				for(int i = 0; i <= s[1].size(); i++)
					for(int j = 0; j <= s[2].size(); j++)
						update(i, j, s[3].size());
			}

		} else s[a].pop_back();

		// dbg(dp[s[1].size()][s[2].size()][s[3].size()]);

		if(dp[s[1].size()][s[2].size()][s[3].size()] <= n) //! <= !!!1
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
}