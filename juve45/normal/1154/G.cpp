#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <long long> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const long long N = 1e6 + 10;
const long long MAX = 1e7 + 5;
long long n, k, m, a[N], b, x, ans = 1e18;

vector <long long> v[MAX + 54], res;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		if(v[a[i]].size() < 2)
			v[a[i]].push_back(i);
	}

	for(long long i = 1; i <= MAX; i++) {
		vector <long long> nr;
		for(long long j = i; j <= MAX && nr.size() < 2; j+=i) {
			for(auto k : v[j])
				nr.push_back(k);
		}
		// if(i%1000 == 0) dbg(i, nr, res, ans);
		if(nr.size() >= 2) 
			if(a[nr[0]] * a[nr[1]] / i < ans)
				ans = a[nr[0]] * a[nr[1]] / i,
				res = nr;
	}
	// dbg(res);
	// cout << ans << '\n';
	sort(res.begin(), res.end());
	cout << res[0] << ' ' << res[1] << '\n';
}