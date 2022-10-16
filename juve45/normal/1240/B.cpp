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
int n, a[N], q, l[N], r[N];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) l[i] = r[i] = 0;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		assert(a[i] <= n);
		if(l[a[i]] == 0) l[a[i]] = i;
		r[a[i]] = i;
	}

	vector <int> dp;
	dp.resize(n + 1, n + 1);
	dp[0] = 0;

	int nr = 0, ans = 0, cnt = 0;
	int last = 0;

	for(int i = 1; i <= n; i++) {
		if(l[i] == 0) continue;
		// dbg(i, last);
		nr++;

		if(l[i] > last)
			cnt++;
		else {	
			ans = max(ans, cnt);
			cnt = 1;
		}
		last = r[i];

		// int pos = lower_bound(dp.begin(), dp.end(), l[i]) - dp.begin();
		// dp[pos] = min(r[i], dp[pos]);
		// // dp[pos] = r[i];
		// ans = max(ans, pos);
	}
	ans = max(ans, cnt);
	// dbg(ans);
	cout <<  nr - ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> q;
	while(q--) solve();
}