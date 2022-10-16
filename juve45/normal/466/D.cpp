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
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <long long> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const long long N = 2020;
const int MOD = 1e9 + 7;
long long n, k, m, a[N], b, h, open, ans, dp[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> h;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = h - a[i];
	}

	for(long long i = 1; i <= n + 1; i++)
		if(abs(a[i] - a[i - 1]) > 1)
			return cout << "0\n", 0;

	dp[0] = 1;
	for(long long i = 1; i <= n; i++) {

		if(a[i] == a[i - 1]) {
			if(a[i] > 0)
				dp[i] = ((a[i] + 1) * dp[i - 1]) % MOD;
			else dp[i] = dp[i - 1];
		}
		else if(a[i] == a[i - 1] + 1)
			dp[i] = dp[i - 1];
		else dp[i] = (dp[i - 1] * a[i - 1]) % MOD;


		// for(long long j = 0; j <=i; j++) {
		// 	if(a[i] == a[i - 1]) {

		// 	} else if(a[i] == a[i - 1] + 1){
		// 		dp[i][j] = dp[i - 1][j - 1];
		// 	} else 
		// }
		// dbg(i);
		// dbg_v(dp[i], i + 1);
	}
	cout << dp[n] << '\n';
}