#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <long long> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const long long N = 300100;
const long long MOD = 666013;
long long n, k, m;

long long dp[N][2], a[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		long long sgn = __builtin_popcountll(a[i]);
		sgn %= 2;
		dp[i][1] = dp[i - 1][1 ^ sgn];
		dp[i][0] = dp[i - 1][0 ^ sgn];
		dp[i][sgn]++;
	}

	// small 
	long long ans = 0;
	for(long long i = 1; i <= n; i++) {
		long long sum = 0;
		long long maxx = 0;
		for(long long j = 0; j < 65 && i + j <= n; j++) {
			maxx = max(maxx, (long long)__builtin_popcountll(a[i + j]));
			sum += __builtin_popcountll(a[i + j]);
			if(sum < 2 * maxx && sum % 2 == 0)
				ans--;
		}
	}
	// dbg(ans);
	// large
	// for(long long i = 64; i <= n; i++) {

	// }
	for(long long i = 1; i <= n; i++)
		ans += dp[i][0];
	cout << ans << '\n';
}