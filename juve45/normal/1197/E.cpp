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

const int MOD = 1e9 + 7;
const int N = 200100;
int n, val[2 * N], res, l[N], r[N], dp[2 * N], mx[2 * N], cst[2 * N], ans, mc, ml;
map<int, int > m;
vector <int> v[2 * N];

int dif(int a, int b) {
	return val[a] - val[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	set <int> s;
	for(int i = 1; i <= n; i++) {
		cin >> r[i] >> l[i];
		s.insert(l[i]);
		s.insert(r[i]);
	}

	int k = 1;
	for(auto i : s) {
		// dbg(i, k);
		val[k] = i;
		m[i] = k++;
	}

	for(int i = 1; i <= n; i++) {
		v[m[r[i]]].push_back(m[l[i]]);
		ml = max(m[l[i]], ml);
	}

	dp[0] = 1;
	mc = 1e9;
	for(int i = 1; i < k; i++) {
		dp[i] = dp[i - 1];
		cst[i] = cst[i - 1] + dif(i, i - 1);

		for(auto j : v[i]) {
			// dbg(j);
			if(cst[j] < cst[i]) {
				dp[i] = dp[j];
				cst[i] = cst[j];
			} else if(cst[j] == cst[i]) {
				dp[i] = (dp[i] + dp[j]) % MOD;
			}
		}
		// dbg(i, dp[i], cst[i]);
		if(i > ml)
			mc = min(mc, cst[i]);
	}

	// dbg(ml, mc);
	for(int i = ml + 1; i < k; i++)
		if(cst[i] == mc)
			ans = (ans + dp[i]) % MOD;

	cout << ans << '\n';

}