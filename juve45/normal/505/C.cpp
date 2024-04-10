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

const int N = 30100;
const int SQRT = 500;
const int SQRT2 = 250;
int n, dp[N][SQRT + 10], d, f[N], x;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> d;
	int ans = 0;
	for(int i = 1; i <= n; i++) cin >> x, f[x]++;	

	for(int i = 0; i <= 30000; i++)
		for(int j = 0; j <= SQRT; j++)
			dp[i][j] = -1e9;

	dp[d][SQRT2] = f[d];
	// 150 == d
	// x = 

	for(int i = d; i <= 30000; i++)
		for(int j = 1; j <= SQRT; j++)
			for(int k = -1; k <= 1; k++) {
				
				int last = d + j - SQRT2;
				if(last + k > 0 && i - last >= 0 && last > 0 && abs(last - d) < SQRT2) {
					dp[i][j] = max(dp[i][j], dp[i - last][j + k] + f[i]);
					ans= max(ans, dp[i][j]);
				}
			}
	cout << ans << '\n';
}