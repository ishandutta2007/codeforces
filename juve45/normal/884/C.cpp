#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <ynt> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const long long N = 100100;
long long n, k, m, a, b, nr = 0, p[N], use[N];

void dfs(long long k) {
	nr++;
	use[k] = 1;
	if(!use[p[k]])
		dfs(p[k]);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) cin >> p[i];

	vector <long long> v;

	for(long long i = 1; i <= n; i++) {
		if(!use[i]) {
			nr = 0;
			dfs(i);
			v.push_back(nr);
		}
	}

	sort(v.begin(), v.end());
	// dbg(v);
	if(v.size() == 1) cout << v[0] * v[0] << '\n';
	else {
		long long ans = 0;
		long long tmp = v[v.size() - 1] + v[v.size() - 2];
		v.pop_back();
		v.pop_back();
		v.push_back(tmp);
		// dbg(v);
		for(auto i : v)
			ans += i * i;
		cout << ans << '\n';
	}
}