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
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <ynt> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const int N = 100100;
long long n, k, m, a, b, v[N], c[N], q;
long long dp[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> q;

	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) cin >> c[i];

	for(int i = 1; i <= q; i++) {
		cin >> a >> b;
		for(int i = 1; i <= n; i++) dp[i] = -1e18;
		dp[0] = 0;
		
		int max1, max2 = 0;
		max1 = 0;

		for(int i = 1; i <= n; i++) {
			int ch = max1;
			if(c[i] == max1) ch = max2;

			dp[c[i]] = max({dp[c[i]] + 1LL * v[i] * a, dp[ch] + 1LL * v[i] * b, dp[c[i]]});

			if(c[i] != max1 && c[i] != max2 && dp[c[i]] > dp[max2])
				max2 = c[i];
			if(dp[max1] < dp[max2]) 
				swap(max1, max2);
			// dbg(dp[c[i]]);
			// dbg(max1, max2);
			// dbg(dp[max1], dp[max2]);
		}
		cout << dp[max1] << '\n';
	}
}