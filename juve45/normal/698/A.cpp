#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 105;

int n, k, m, dp[N][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> k;
		dp[i][0] = max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][0]});
		if(k % 2 == 1)
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
		if(k / 2 == 1)
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + 1;
	}
	cout << n - max({dp[n][1], dp[n][2], dp[n][0]}) << '\n';


	// for(int i = 1; i <= n; i++) 
	// 	cerr << dp[i][0] <<  ' ';
	// cerr << '\n';
	// for(int i = 1; i <= n; i++) 
	// 	cerr << dp[i][1] <<  ' ';
	// cerr << '\n';
	// for(int i = 1; i <= n; i++) 
	// 	cerr << dp[i][2] <<  ' ';

}