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

const int N = 1000000;
int n, dp[N][2], nr;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	vector <int> v = {1, 2, 4, 5, 9, 10, 20, 21, 41, 42, 84, 85, 169, 170, 340, 341, 681, 682, 1364, 1365, 2729, 2730, 5460, 5461, 10921, 10922, 21844, 21845, 43689, 43690, 87380, 87381, 174761, 174762, 349524, 349525, 699049, 699050};
										// 4, 5, 9, 10, 20, 21, 41, 42, 84, 85, 169, 170, 340, 341, 681, 682, 1364, 1365, 2729, 2730, 5460, 5461, 10921, 10922, 21844, 21845, 43689, 43690, 87380, 87381,
	for(auto i : v)
		if(i == n) return cout << 1 <<'\n', 0;
	cout << "0\n";
	return 0;

	// dp[1][1] = 1;
	// dp[2][0] = 1;

	// int sz = 1;
	// for(int i = 3; i < N; i++) {
	// 	if(i % 5000 == 0) dbg(i, nr);
	// 	if(2 * sz + 1 <= (i - 1) / 2) sz = 2 * sz + 1;
	// 	int szmax = 2 * sz + 1;
	// 	// dbg(i, sz);
	// 	for(int j = max(sz, i - szmax - 1); j + sz + 1 <= i && j <= szmax; j++) {
	// 		dp[i][0] += dp[j][1] * dp[i - j - 1][0 + (j + 1) % 2];
	// 		dp[i][1] += dp[j][0] * dp[i - j - 1][1 - (j + 1) % 2];
	// 		if(dp[i][0] + dp[i][1] == 1)  {
	// 			cout << i << ", ";
	// 			break;
	// 		}
	// 		// dbg(j, i - j - 1, dp[i][0], dp[i][1]);
	// 	}
	// 	if(dp[i][0] + dp[i][1] == 1) {
	// 		nr++;
	// 		if(dp[i- 1][0] + dp[i - 1][1] == 1)
	// 			i += max(i - 10, 1);
	// 	}
	// 	// cout << i << ' ' << dp[i][0] + dp[i][1] << ' ' << dp[i][0]  << ' ' << dp[i][1] << '\n';
	// }
}