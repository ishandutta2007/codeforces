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
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <long long> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const long long N = 100100;
long long n, k, m, a[N], b, ans;

vector <long long> v[N];

long long dei(long long level, long long st, long long fi) {
	if(level == n) return 0;

	long long ans = 0;
	ans += (n - level + 1);
	long long last = st;
	for(auto i : v[level])
		ans += dei(level + 1, last, i - 1), last = i + 1;
	ans += dei(level + 1, last, fi);
	
	dbg(level, st, fi, ans);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ans = a[1] * (n - a[1] + 1);
	ans += a[n] * (n - a[n] + 1);
	// ans = 0;
	// dbg(ans);
	for(long long i = 2; i <= n; i++) {

		// dbg(i);
		ans +=  min(a[i], a[i - 1]) *  (abs(a[i] - a[i - 1]));
		// dbg(ans);
		ans += (n - max(a[i - 1], a[i]) + 1) * (abs(a[i] - a[i - 1]));
		// dbg(ans);
		//- (abs(a[i] - a[i - 1]) + 1) * (abs(a[i] - a[i - 1]) + 1));
	}
		ans /= 2;
		// ans += n*(n + 1) / 2;


	cout << ans << '\n';

}