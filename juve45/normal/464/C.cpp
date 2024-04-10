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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;
const long long MOD = 1e9 + 7;
long long n, dp[N][10], sz[N][10], q[N];

string s, t[N];
vector <long long> v[N][10];

long long get(long long pas, long long cif) {

	if(pas == n + 1) {
		sz[pas][cif] = 10;
		dp[pas][cif] = cif;
		return cif;
	}

	if(dp[pas][cif] != -1) return dp[pas][cif];

	if(v[pas][cif].size() == 0 && q[pas] != cif)  {
		dp[pas][cif] = get(pas + 1, cif);
		sz[pas][cif] = sz[pas + 1][cif];
		return dp[pas][cif];
	}

	// dbg(pas, cif);

	sz[pas][cif] = 1;
	dp[pas][cif] = 0;

	for(auto i : v[pas][cif]) {
		long long val = get(pas + 1, i);
		dp[pas][cif] += sz[pas][cif] * val;
		dp[pas][cif] %= MOD;
		sz[pas][cif] *= sz[pas + 1][i];
		sz[pas][cif] %= MOD;
	}

	return dp[pas][cif];
}


int main() {
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof dp);
	memset(q, -1, sizeof q);

	cin >> s;
	for(auto i : s) 
		v[0][1].push_back(i - '0');
	reverse(v[0][1].begin(), v[0][1].end());
	q[0] = 1;
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> t[i];
		long long x = t[i][0] - '0';
		t[i] = t[i].substr(3);

		q[i] = x;
		for(auto ii : t[i])
			v[i][x].push_back(ii - '0');
		reverse(v[i][x].begin(), v[i][x].end());
	}
	cout << get(0, 1) << '\n';

}