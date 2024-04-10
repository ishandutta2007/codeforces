#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const long long N = 1000005;
const long long MOD = 998244353;
const long long OFF = 1e7 + 87;
long long n, a[N], x[N], m, dp[5000][5000], last;
vector <long long> pos[N];
vector <pair <long long, long long> > v;

// unordered_map <long long, long long> dp;

inline int tr(int val) {
	if(x[val] == 0) {
		x[val] = ++last;
	}
	return x[val];
}

long long solve(long long l, long long r, int save = 1) {
	// dbg(l, r);
	if(l > r) return 1;

	if(!save || dp[tr(l)][tr(r)] == -1) {

		if(l == r)  {
			long long pmin = *pos[a[l]].begin(), pmax = pos[a[l]].back();

			if(save) 
				dp[tr(l)][tr(r)] = 0;
			if(pmin < l || r < pmax) return 0;
			if(save) 
				dp[tr(l)][tr(r)] = 1;
			return 1;
		}
		else {
			long long mn = l;
			for(long long i = l; i <= r; i++) {
				if(a[i] < a[mn])
					mn = i;
			}
			long long pmin = *pos[a[mn]].begin(), pmax = pos[a[mn]].back();

			// dbg(l, pmin, pmax, r);
			if(pmin < l || r < pmax) return 0;

			long long sum_mid = 1;
			for(long long i = 1; i < pos[a[mn]].size(); i++) 
				sum_mid = (sum_mid * solve(pos[a[mn]][i - 1] + 1, pos[a[mn]][i] - 1, 0)) % MOD;

			long long sum_left = 0;

			for(long long i = l; i <= pmin; i++) {
				sum_left += ((solve(l, i - 1) * solve(i, pmin - 1)) % MOD);
				sum_left %= MOD;
			}

			long long ret = 0;
			for(long long j = pmax; j <= r; j++)
				ret += ( ((sum_mid * sum_left) % MOD) * ((solve(pmax + 1, j) * solve(j + 1, r)) % MOD) ) % MOD;
			ret %= MOD;
			if(save) 
				dp[tr(l)][tr(r)] = ret;
			return ret;
		}
	}

	return dp[tr(l)][tr(r)];
}


bool check() {
	// if(m > 40000)	return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(long long i = 1; i <= m; i++)
		cin >> a[i];

	for(int i = 1, j = 1; i <= m; i++) {
		a[i] = a[j];
		while(j <= m && a[i] == a[j]) j++;
		if(j > m) {
			m = i;
			break;
		}
	}
	// dbg_v(a, m +1);

	for(long long i = 1; i <= m; i++)
		pos[a[i]].push_back(i);

	if(!check()) return cout << "0\n", 0;
	memset(dp, -1, sizeof dp);
	cout << solve(1, m) << '\n';
}