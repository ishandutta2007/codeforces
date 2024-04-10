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

const int N = 555;
int n, dp[N][N];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	s = "." + s;
	for(int i = n; i > 0; i--)
		for(int j = i; j <= n; j++) {
			if(i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i + 1][j] + 1;

			for(int k = i + 1; k <= j; k++)
				if(s[k] == s[i])
					dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
		}
	cout << dp[1][n] << '\n';
}