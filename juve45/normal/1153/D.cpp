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

const int N = 300100;
int n, a[N], dp[N], p, k;
vector <int> v[N];

void dfs(int node) {

	if(a[node] == 1) dp[node] = 1e9;
	else dp[node] = 0;

	if(v[node].size() == 0)
		dp[node] = 1, k++;

	for(auto i : v[node]) {
		dfs(i);
		if(a[node] == 1)
			dp[node] = min(dp[node], dp[i]);
		else 
			dp[node] += dp[i];
	}
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 2; i <= n; i++) {
		cin >> p;
		v[p].push_back(i);
	}

	dfs(1);
	// dbg_v(dp, n + 1);
	cout << k - dp[1] + 1;
}