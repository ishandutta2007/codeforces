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

const long long N = 200100;
long long n, c[N], g[N], v[N], s, t, k;

bool ok(long long val) {
	long long tot_time = 0;
	for(long long i = 1; i <= k; i++) {
		// dbg(i);
		long long d = g[i] - g[i - 1];
		if(d > val)
			return 0;
		// dbg(d);
		long long eco = min(val - d, d);
		tot_time += 2 * d - eco;
		if(tot_time > t) return 0;
	}
	// dbg(val, tot_time);
	return (tot_time <= t);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k >> s >> t;

	for(long long i = 1; i <= n; i++) 
		 cin >> c[i] >> v[i];

	for(long long i = 1; i <= k; i++)
		cin >> g[i];
	g[++k] = s;

	sort(g, g + k + 1);

	// dbg(ok(s));
	// return 0;
	long long l = 1, r = 1e9 + 12446;
	while(l != r) {
		// dbg(l, r);
		long long mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}

	// dbg(l);
	// dbg(ok(5000000));
	// return 0;
	// assert(ok(l));
	// assert(!ok(l - 1));

	if(!ok(l)) return cout << "-1\n", 0;

	long long ans = 2e9;
	for(long long i =1; i <= n; i++)
		if(v[i] >= l)
			ans = min(ans, c[i]);
	if(ans > 1.2e9) ans = -1;
	cout << ans << '\n';
}