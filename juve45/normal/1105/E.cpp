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

const long long N = 44;
long long n, k, m, dp[(1 << 20) + 10], op, ans;
set <long long> cache;
map <string, long long> mp;
string str;

long long assign(string s) {
	if(!mp.count(s)) {
		long long tmp = mp.size();
		mp[s] = tmp;
	}
	return mp[s];
}

long long v[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(long long i = 1; i <= n; i++) {
		cin >> op;
		if(op == 1) cache.clear();
		else {
			cin >> str;
			long long nr = assign(str);

			for(auto i : cache) {
				v[i] |= (1LL << nr);
				v[nr] |= (1LL << i);
			}

			cache.insert(nr);
		}
	}

	for(long long i = 0; i < m; i++)
		if(v[i] & (1LL << i))
			v[i] ^= (1LL << i);

	long long L = m / 2;
	long long R = m - L;

	for(long long i = 0; i < (1 << L); i++) {
		long long vec = 0;
		
		for(long long j = 0; j < L; j++)
			if(i & (1 << j)) 
				vec |= v[j];

		if((vec & i) == 0)
			dp[i] = __builtin_popcount(i);

		for(long long j = 0; j < L; j++)
			if(i & (1 << j)) 
				dp[i] = max(dp[i], dp[i ^ (1 << j)]);
	}
	// dbg_v(dp, 10);
	long long xorr = (1 << L) - 1;
	for(long long i = 0; i < (1 << R); i++) {
		long long msk = (i << L), vec = 0;
		// dbg(msk);
		for(long long j = L; j < m; j++){
			// dbg(j);
			// dbg(v[j]);
			if(msk & (1LL << j))
				vec |= v[j];
		}
		// dbg(vec);
		// dbg(((vec & xorr) ^ xorr));
		if((vec & msk) == 0)
			ans = max(ans, __builtin_popcount(i) + dp[(vec & xorr) ^ xorr]);
	}
	cout << ans << '\n';
	// cout << dp[(1 << L) - 1] << '\n';
}