#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

using namespace std;

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 1000100;
int n, k, m, v[N], a, b;
long long ans = 1e18, dp[N][3];

vector <int> p;

void desc(int nr) {
	for(int i = 2; i * i <= nr; i++)
		if(nr % i == 0) {
			p.push_back(i);
			while(nr % i == 0) nr /= i;
		}
	if(nr != 1) p.push_back(nr);
}

bool almost(int nr, int d) {
	if(nr % d <= 1)
		return true;
	if(nr % d == d - 1)
		return true;
	return false;
}

long long solve(int d) {
	
	// dbg(d);

	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;

	for(int i = 1; i <= n; i++) {	
		// dbg(almost(v[i], d));
		if(almost(v[i], d)) dp[i][0] = dp[i - 1][0] + (v[i] % d == 0 ? 0 : b);
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a;
		if(almost(v[i], d)) dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (v[i] % d == 0 ? 0 : b);
	}
	// dbg_v(dp[1], 3);
	// dbg_v(dp[2], 3);
	// dbg_v(dp[3], 3);
	// dbg_v(dp[4], 3);
	// dbg_v(dp[5], 3);
	// dbg_v(dp[6], 3);
	// dbg_v(dp[7], 3);
	return min({dp[n][0], dp[n][1], dp[n][2]});
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> a >> b;

	for(int i = 1; i <= n; i++)
		cin >> v[i];

	desc(v[1]);
	desc(v[1] + 1);
	desc(v[1] - 1);
	desc(v[n]);
	desc(v[n] + 1);
	desc(v[n] - 1);

	sort(p.begin(), p.end());
	p.resize( distance(p.begin(), unique(p.begin(), p.end())) );

	for(auto i : p)
		ans = min(ans, solve(i));
	cout << ans << '\n';
}