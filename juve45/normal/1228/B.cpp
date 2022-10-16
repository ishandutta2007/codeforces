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

const int N = 3003;
const int MOD = 1e9 + 7;
int n, m, w[N][N], r[N], c[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	memset(w, -1, sizeof w);

	for(int i = 1; i <= n; i++) {
		cin >> r[i];
		for(int j = 1; j <= r[i]; j++)
			w[i][j] = 1;
		w[i][r[i] + 1] = 0;
	}
	for(int i = 1; i <= m; i++) {
		cin >> c[i];
		for(int j = 1; j <= c[i]; j++)
			if(w[j][i] == 0) return cout << "0\n", 0;
			else w[j][i] = 1;
		if(w[c[i] + 1][i] == 1) return cout << "0\n", 0;
		w[c[i] + 1][i] = 0;
	}

	int ans = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(w[i][j] == -1)
				ans = (2LL * ans) % MOD;
	cout << ans << '\n';
}