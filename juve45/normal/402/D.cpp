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

const int N = 5010;
int n, v[N][2], vg[N][2], a[N], g[N], m, b[N], sum, dp[N], max_dp;
set <int> good;

void add(int i, int x, int v[N][2]) {
	// dbg(x);
	for(int j = 2; j * j <= x; j++) {
		if(x % j == 0) {
			int cnt = 0;
			while(x % j == 0) x /= j, cnt++;
			if(good.count(j)) v[i][0] += cnt;
			else v[i][1] += cnt;
		}
	}
	if(x != 1) 
		if(good.count(x)) v[i][0]++;
		else v[i][1]++;
	// dbg(v[i][0], v[i][1]);
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i], good.insert(b[i]);


	for(int i = 1; i <= n; i++)
		g[i] = __gcd(g[i - 1], a[i]);


	for(int i = 1; i <= n; i++) {
		add(i, a[i], v);
		add(i, g[i], vg);
	}

	for(int i = 1; i <= n; i++) {
		
		sum += v[i][1] - v[i][0];
		// dbg(i, v[i][0], v[i][1]);
		// dbg(sum);
		int dif = 0;

		for(int j = i - 1; j >= 0; j--) {
			dif += vg[i][0] - vg[i][1];
			dp[i] = max(dp[i], dp[j] + dif);
		}
		max_dp = max(max_dp, dp[i]);
	}
	// dbg(max_dp);
	cout << sum + max_dp << '\n';

}