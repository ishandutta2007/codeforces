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

const int N = 2010;
int n, a[14][N], w[14][15], m, dp[14][(1 << 13)], t, pre[14][(1 << 13)];

int calc(int col, int msk) {
	int add = 0;

	for(int off = 0; off < n; off++) {
		int tmp = 0;
		for(int j = 0; j < n; j++)
			if(msk & (1 << j))
				tmp += w[(j + off) % n][col];	
		add = max(add, tmp);
	}
	return add;
}

void solve() {
	cin >> n >> m;
	memset(w, 0, sizeof w);
	memset(a, 0, sizeof a);

	vector <pair<int, int> >  v;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	for(int i = 0; i < m; i++) {
		int mx = 0;
		for(int j = 0; j < n; j++)
			mx = max(a[j][i], mx);
		v.push_back({-mx, i});
	}

	sort(v.begin(), v.end());
	// dbg(v);

	if(m > n) m = n;

	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++)
			w[i][j] = a[i][v[j].nd];
	}

	memset(dp, 0, sizeof dp);

	for(int i = 0; i < m; i++)
		for(int msk = 0; msk < (1 << n); msk++)
			pre[i][msk] = calc(i, msk);

	for(int i = 1; i <= m; i++) {
		for(int mask = 0; mask < (1 << n); mask++) {
			for(int submask = mask; ; submask = (submask - 1) & mask) {
         // do something
				int base = dp[i - 1][mask ^ submask];
				
				dp[i][mask] = max(dp[i][mask], base + pre[i - 1][submask]);
        if(submask == 0) break;	
			}
		}
	}
	cout << dp[m][(1 << n) - 1] << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) solve();
}